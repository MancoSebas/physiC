#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <cstdio>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "../headers/FlatMath.h"


int main (int argc, char *argv[]) {

    FlatVector vector1 = FlatVector(30, 40);

    sf::RenderWindow window(sf::VideoMode(800,600),"SFML");
    sf::CircleShape circle;

    circle.setRadius(30.0f);

    window.setFramerateLimit(60);

    float xPosition = vector1.X;
    float yPosition = vector1.Y;


    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                exit(EXIT_SUCCESS);
            } 
        }

        circle.setPosition(xPosition,yPosition);
        xPosition+=1;
        yPosition+=1;
        if (xPosition > 300 && yPosition > 400) {
            xPosition = 0; 
            yPosition = 0;
        }


        window.clear();

        window.draw(circle);
        window.display();
    }
    
    return 0;
}
