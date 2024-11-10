#include <SFML/Window/ContextSettings.hpp>
#include "../headers/collisions.h"
#include <SFML/Window/WindowStyle.hpp>
#include <iostream>
#include "../headers/vec2.h"
#include "../headers/FlatBody.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowHandle.hpp>
#include <random>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

Vec2 primeCoordinates(Vec2 coordinates){
    return Vec2(coordinates.X + (float(SCREEN_WIDTH) / 2.0f), - coordinates.Y + (float(SCREEN_HEIGHT) / 2.0f));
}

int main () {

    std::random_device device;
    std::mt19937 rng(device());
    std::uniform_int_distribution<> dist(-300, 300);

    std::array<FlatBody, 10> bodyList {};

    for(int i = 0; i < bodyList.size(); i++){
        Vec2 position = primeCoordinates(Vec2(float(dist(rng)),float(dist(rng))));
        FlatBody body = FlatBody().createCircleBody(20.0f, position, 5.0f, false, 1.0f);

        bodyList[i] = body;
    }
    
    sf::ContextSettings settings; 
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "SFML", sf::Style::Default, settings);
    sf::CircleShape shape(10.0f);
    shape.setFillColor(sf::Color::White);

    float speed = 5.0f;
    
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
        for (auto body:bodyList) {
            float radius = body.radius;
            float positionX = body.position.X;
            float positionY = body.position.Y;

            shape.setRadius(radius);
            shape.setPosition(positionX,positionY);

            window.draw(shape);
        }

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
