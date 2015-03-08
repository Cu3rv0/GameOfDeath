#pragma once
#include "SFMLVisualGrid.h"
#include "GameOfLife.h"
#include "GameInterface.h"
#include "Grid.h"
#include <SFML/System.hpp>

class SingleDemo: public GameInterface
{

public:

   static const unsigned int FPS = 60;

   SingleDemo(unsigned int width, unsigned int height);
   ~SingleDemo();

   void Run();

private:
   static const unsigned int RES_X = 800;
   static const unsigned int RES_Y = 600;

   SFMLVisualGrid m_demoGrid;
   Grid m_lastGrid;
   GameOfLife m_gameOfLife;
   sf::Clock m_clock;
   sf::Time m_lastFrame;
   sf::Mouse m_Mouse;
};
