#pragma once

#include <memory>
#include "GameOfLifeInterface.h"
#include "GridInterface.h"


class GameOfLife: public GameOfLifeInterface
{
public:

   GameOfLife(GridInterface&, GridInterface&);
  
   void AdvanceGeneration();
   void PrintGrid() const;

private:

   int NeighbourSum(unsigned int xPos, unsigned int yPos) const;

   GridInterface& m_grid;
   GridInterface& m_lastGrid;
   //VisualFrontEndInterface& m_visualFrontEnd;
};
