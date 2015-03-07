#include "gtest/gtest.h"
#include <iostream>
#include "Grid.h"
#include "GameOfLife.h"
#include <memory>
#include <SFML/Graphics.hpp>

using namespace std;

int main() 
{
   unique_ptr<Grid> grid(make_unique<Grid>(4,4));
   unique_ptr<Grid> lastGrid(make_unique<Grid>(4,4));

   grid->SetValue(2,2,1);
   grid->SetValue(2,3,1);
   grid->SetValue(1,2,1);
   grid->SetValue(1,3,1);

   sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
   sf::CircleShape shape(100.f);
   shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;

}
