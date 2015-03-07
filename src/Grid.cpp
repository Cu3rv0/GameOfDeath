#include "Grid.h"

using namespace std;

 
Grid::Grid(unsigned int width, unsigned int height) :
   m_values(width,std::vector<unsigned short>(height,0)),
   m_width(width),
   m_height(height)
{
}

unsigned short Grid::GetValue(unsigned int x, unsigned int y) const{
  return m_values.at(x).at(y);
}


void Grid::SetValue (unsigned int x, unsigned int y, unsigned short value){
   m_values.at(x).at(y) = value;
}

std::string Grid::GetGridString() const {
   std::string gridString;
   for (auto y = 0; y != m_height; y++) {
      for (auto x = 0; x != m_width; x++) {
         gridString += m_values[x][y] ? '*' : '.';
      }
      gridString += '\n';
   }
   return gridString;
}

unsigned int Grid::GetHeight() const {
   return m_height;
}

unsigned int Grid::GetWidth() const {
   return m_width;
}

const vector<vector<unsigned short> >& Grid::GetValues() const
{
   return m_values;
}


GridInterface& Grid::operator=(const GridInterface& rhs) 
{
   m_height = rhs.GetHeight();
   m_width = rhs.GetWidth();
   m_values = rhs.GetValues();
}
