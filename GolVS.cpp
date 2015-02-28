
#include <iostream>
#include "Grid.h"

int main() {
   Grid grid(4,4);
   grid.SetValue(2,2,1);
   std::cout << grid.GetGridString();
}
