#include "AsciiVisualFrontEnd.h"
#include <iostream>

AsciiVisualFrontEnd::AsciiVisualFrontEnd(GameOfLifeInterface& gameOfLife):
   m_gameOfLife(gameOfLife)
{
}

void AsciiVisualFrontEnd::Draw()
{
   std::cout << "\033[2J#" << m_gameOfLife.GetGridString();
}



