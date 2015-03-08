#include "SingleDemo.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

SingleDemo::SingleDemo(unsigned int width, unsigned int height):
   m_demoGrid(width,height),
   m_lastGrid(width,height),
   m_gameOfLife(m_demoGrid, m_lastGrid)
{
   m_demoGrid.SetValue(2,2,1);
   m_demoGrid.SetValue(2,1,1);
   m_demoGrid.SetValue(3,2,1);
   m_demoGrid.SetValue(2,3,1);
   m_demoGrid.SetValue(1,2,1);
}

SingleDemo::~SingleDemo()
{
}

void SingleDemo::Run()
{
   sf::RenderWindow window(VideoMode(RES_X, RES_Y), "Single GOL demo");
   m_demoGrid.setPosition(Vector2f(RES_X/2,RES_Y/2));


    while (window.isOpen())
    {
        Time elapsedTime = m_clock.getElapsedTime(); 
        if ((elapsedTime - m_lastFrame).asSeconds() > 1.0 / FPS)
        {
            m_lastFrame = elapsedTime;
            window.clear();
            window.draw(m_demoGrid);
            window.display();
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Space))
            {
               m_gameOfLife.AdvanceGeneration();
            }

        }

    }
}



