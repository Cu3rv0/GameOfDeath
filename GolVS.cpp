
#include <iostream>
#include "Grid.h"
#include "GameOfLife.h"
#include <memory>

using namespace std;

int main() 
{
   unique_ptr<Grid> grid(make_unique<Grid>(4,4));
   unique_ptr<Grid> lastGrid(make_unique<Grid>(4,4));

   grid->SetValue(2,2,1);
   grid->SetValue(2,3,1);
   grid->SetValue(1,2,1);
   grid->SetValue(1,3,1);
  
   GameOfLife gameOfLife(*grid,*lastGrid);
   gameOfLife.PrintGrid();
   gameOfLife.AdvanceGeneration();
   gameOfLife.PrintGrid();

}
