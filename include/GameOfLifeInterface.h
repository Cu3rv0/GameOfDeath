#pragma once

class GameOfLifeInterface 
{
public:
   virtual ~GameOfLifeInterface() {}

   virtual void AdvanceGeneration() = 0;

};
