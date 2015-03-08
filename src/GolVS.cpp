#include "gtest/gtest.h"
#include <iostream>
#include "GameOfLife.h"
#include <memory>
#include <SFML/Graphics.hpp>
#include "SFMLVisualGrid.h"
#include "SingleDemo.h"

static const unsigned int GRID = 12;
static const unsigned int RES_X = 800;
static const unsigned int RES_Y = 600;

using namespace std;

int main() 
{
   SingleDemo singleDemo(10,10);
   singleDemo.Run();

   return 0;

}
