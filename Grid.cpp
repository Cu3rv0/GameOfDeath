#include "Grid.h"

Grid::Grid(unsigned int height, unsigned int width) :
   m_values(width,std::vector<unsigned short>(height,0)),
   m_width(width),
   m_height(height)
{
}

unsigned short Grid::GetValue(unsigned int x, unsigned int y) const{
  return m_values[x][y];
}


void Grid::SetValue (unsigned int x, unsigned int y, unsigned short value){
   m_values.at(x).at(y) = value;
}

std::string Grid::GetGridString() const {
   std::string gridString;
   for (auto x = 0; x != m_width; x++) {
      for (auto y = 0; y != m_height; y++) {
         gridString += m_values[x][y] ? '*' : '.';
      }
      gridString += '\n';
   }
   return gridString;
}

unsigned int Grid::GetHeigth() const {
   return m_height;
}

unsigned int Grid::GetWidth() const {
   return m_width;
}
