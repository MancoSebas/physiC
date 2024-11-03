#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <array>
#include <cstdio>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <random>
#include <vector>
#include "../headers/FlatMath.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

FlatVector changeCoordinate(FlatVector vector){
    return FlatVector(vector.X + double(SCREEN_WIDTH)/2, -vector.Y + double(SCREEN_HEIGHT)/2);
}

sf::VertexArray createLine(FlatVector vo ,  FlatVector vf, int r, int g, int b){
    sf::VertexArray line(sf::Lines,2);

    line[0].position = sf::Vector2f(changeCoordinate(vo).X,changeCoordinate(vo).Y);
    line[1].position = sf::Vector2f(changeCoordinate(vf).X, changeCoordinate(vf).Y);

    line[0].color = sf::Color(r,g,b); 
    line[1].color = sf::Color(r,g,b); 

    return line;
}

int main (int argc, char *argv[]) {

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    std::random_device rseed;
    std::mt19937 rng(rseed());
    std::uniform_int_distribution<> dist(-200,200);

    std::array<sf::VertexArray, 10> listLines;
    for (int i = 0; i < listLines.size(); i++) {
         listLines[i] = createLine(FlatVector(float(dist(rng)), float(dist(rng))), FlatVector(float(dist(rng)), float(dist(rng))), 255, 255, 255);
    }
    
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT),"SFML", sf::Style::Default,settings);
    
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                exit(EXIT_SUCCESS);
            } 
        }
        window.clear();
        for (int i = 0; i < listLines.size(); i ++) {
            window.draw(listLines[i]); 
        }
        window.display();
    }
    
    return 0;
}
