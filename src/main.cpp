#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowHandle.hpp>
#include <random>
#include <vector>
#include <iostream>

#include "../headers/flatPhysics.h"
#include "../headers/collisions.h"
#include "../headers/vec2.h"
#include "../headers/FlatBody.h"
#include "../headers/FlatMath.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

std::vector<FlatBody> createBodies(int numBodies, float radius){

    std::vector<FlatBody> bodyList;

    std::random_device device;
    std::mt19937 rng(device());
    std::uniform_int_distribution<> dist(-300, 300);
    
    for(int i = 0; i < numBodies; i++){
        
        Vec2 position = Vec2(float(dist(rng)), float(dist(rng)));
        Vec2 shiftedPosition = FlatMath().shifCoordinates(position, SCREEN_WIDTH, SCREEN_HEIGHT);
        
        FlatBody body = FlatBody().createCircleBody(radius, shiftedPosition, 5.0f, false, 1.0f);

        bodyList.push_back(body);
    }

    return bodyList;
}

int main () {

    float speed = 5.0f;
    Vec2 initial_velocity = Vec2(0.0,0.01f);
    Vec2 gravitational_acceleration = Vec2(0.0, 5.5f);
    std::vector<FlatBody> bodyList = createBodies(1,20.0f);

    sf::ContextSettings settings; 
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "SFML", sf::Style::Default, settings);
    sf::CircleShape shape;

    sf::RectangleShape flooor;
    flooor.setSize(sf::Vector2f(SCREEN_WIDTH * 2,10.0f));
    flooor.setPosition(0.0f,SCREEN_WIDTH - 10.0f);
    
    sf::Clock clock; 
    window.setFramerateLimit(60);

    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) bodyList[0].move(Vec2(-speed,0));
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) bodyList[0].move(Vec2(+speed,0)); 
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) bodyList[0].move(Vec2(0,-speed)); 
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) bodyList[0].move(Vec2(0,+speed)); 
            }
        }

        window.clear();
        window.draw(flooor);
        

        for (auto body:bodyList) {
            float radius = body.radius;
            float positionX = body.position.X;
            float positionY = body.position.Y;
            
            shape.setFillColor(sf::Color::White);
            
            shape.setRadius(radius);
            shape.setPosition(positionX,positionY);
            window.draw(shape);
        }
        
        sf::Time time = clock.getElapsedTime();
        float elapsed_time = time.asSeconds();
        
        FlatPhysics().freeFall(bodyList[0], 
                               initial_velocity, 
                               gravitational_acceleration, 
                               elapsed_time, 
                               float(SCREEN_HEIGHT) - bodyList[0].radius*2 - 10.0f);
       
        /*
        if (bodyList[0].position.Y < (float(SCREEN_HEIGHT) - bodyList[0].radius*2 - 10.0f)){
            bodyList[0].move(initial_velocity + gravitational_acceleration*elapsed_time);
        }
        */
        
        Collisions collision;

        for(int i = 0; i < bodyList.size() - 1; i++){
            FlatBody* bodyA = &bodyList[i];
            
            for(int j = i+1; j < bodyList.size(); j++){
                FlatBody* bodyB = &bodyList[j];

                if (collision.intersectCircles(bodyA->position, bodyA->radius, bodyB->position, bodyB->radius)) {
                    
                    bodyA->move((collision.normal * -1)* collision.depth / 2.0f);
                    bodyB->move(collision.normal * collision.depth / 2.0f);
                }
            }
        }
        
        window.display();
    }
}
