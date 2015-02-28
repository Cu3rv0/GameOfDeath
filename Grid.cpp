#include "Grid.h"

Grid::Grid(unsigned int height, unsigned int width) :
   m_values(height*width,0),
   m_width(width),
   m_height(height)
{
}

unsigned int Grid::CoordsToIndex(unsigned int x, unsigned int y) const {
   return y * m_width + x;
}

unsigned int Grid::IndexToX(unsigned int index) const {
   return index % m_width;
}

unsigned int Grid::IndexToY(unsigned int index) const {
   return index / m_width;
}

unsigned short Grid::GetValue(unsigned int x, unsigned int y) const{
   return m_values[CoordsToIndex(x,y)];
}


void Grid::SetValue (unsigned int x, unsigned int y, unsigned short value){
   m_values.at(CoordsToIndex(x,y)) = value;
}

std::string Grid::GetGridString() const {
   std::string gridString;
   for (auto x = 0; x != m_width; x++) {
      for (auto y = 0; y != m_height; y++) {
         gridString += m_values[CoordsToIndex(x,y)] ? '*' : '.';
      }
      gridString += '\n';
   }
   return gridString;
}

