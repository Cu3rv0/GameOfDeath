#include "GameOfLife.h"
#include <iostream>
#include <algorithm>

GameOfLife::GameOfLife(GridInterface &grid, GridInterface &lastGrid):
   m_grid(grid),
   m_lastGrid(lastGrid)
{
}

void GameOfLife::AdvanceGeneration()
{
   m_lastGrid = m_grid;
   for (auto x = 0; x != m_grid.GetWidth(); ++x)
   {
      for(auto y = 0; y != m_grid.GetHeight(); ++y)
      {
         switch (NeighbourSum(x,y))
         {
         case 3:
            m_grid.SetValue(x,y, 1);
            break;
         case 4:
            m_grid.SetValue(x,y, m_lastGrid.GetValue(x,y));
            break;
         default:
            m_grid.SetValue(x,y, 0);
            break;
         }
      }
   }   
}

void GameOfLife::PrintGrid() const
{
   std::cout << m_grid.GetGridString(); 
}

int GameOfLife::NeighbourSum(unsigned int xPos, unsigned int yPos) const
{
   auto sum = 0;
   for (auto x = std::max(static_cast<int>(xPos) -1,0); x < std::min(xPos +2, m_lastGrid.GetWidth());++x)
   {
      for (auto y = std::max(static_cast<int>(yPos) -1,0); y < std::min(yPos + 2, m_lastGrid.GetHeight()); ++y)
      {
         sum += m_lastGrid.GetValue(x,y);
      }
   }
   sum -= m_lastGrid.GetValue(xPos,yPos);
   return sum;
}
