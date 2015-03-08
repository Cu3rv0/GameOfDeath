#include "SFMLVisualGrid.h"

using namespace std;
using namespace sf;

SFMLVisualGrid::SFMLVisualGrid(unsigned int width, unsigned int height):
   Grid::Grid(width,height),
   m_gridLines(sf::Quads,4*(width+height)),
   m_circleVector(width,vector<CircleShape>(height,CircleShape(CircleRadiusInPX)))
{
   ConstructGrid();
   setOrigin(sf::Vector2f((width * SquareSideInPX)/2,(height * SquareSideInPX)/2));
}

void SFMLVisualGrid::ConstructVerticalLines()
{
   for(auto x = 0; x != m_width; ++x)
   {
      m_gridLines[4*x].position = sf::Vector2f(x * SquareSideInPX,0);
      m_gridLines[4*x + 1].position = sf::Vector2f(x * SquareSideInPX + LineWidthInPX,0);
      m_gridLines[4*x + 2].position = sf::Vector2f(x * SquareSideInPX + LineWidthInPX,
                                                   (m_height - 1) * SquareSideInPX + LineWidthInPX);
      m_gridLines[4*x + 3].position = sf::Vector2f(x * SquareSideInPX,
                                                   (m_height - 1) * SquareSideInPX + LineWidthInPX);
   }
}

void SFMLVisualGrid::ConstructHorizontalLines()
{
   for(auto y = 0; y != m_height; ++y)
   {
      m_gridLines[4*(y + m_width)].position = sf::Vector2f(0, y * SquareSideInPX);
      m_gridLines[4*(y + m_width) + 1].position = sf::Vector2f(0, y * SquareSideInPX + LineWidthInPX);
      m_gridLines[4*(y + m_width) + 2].position = sf::Vector2f((m_width -1) * SquareSideInPX + LineWidthInPX,
                                                                   y * SquareSideInPX + LineWidthInPX);
      m_gridLines[4*(y + m_width) + 3].position = sf::Vector2f((m_width -1) * SquareSideInPX + LineWidthInPX,
                                                                   y * SquareSideInPX);
   }
}

void SFMLVisualGrid::ConstructCircles()
{
   for(auto x = 0; x != m_width; x++)
   {
      for(auto y = 0; y != m_height; y++)
      {
         m_circleVector[x][y].setFillColor(sf::Color::Blue);
         m_circleVector[x][y].setOrigin(sf::Vector2f(CircleRadiusInPX,CircleRadiusInPX));
         m_circleVector[x][y].setPosition(sf::Vector2f(x*SquareSideInPX + LineWidthInPX/2,
                                                       y*SquareSideInPX + LineWidthInPX/2));
      }
   }
       
}

void SFMLVisualGrid::ConstructGrid()
{
   ConstructVerticalLines();
   ConstructHorizontalLines();
   ConstructCircles();
}

void SFMLVisualGrid::DrawCircles(RenderTarget& target, RenderStates states) const
{
   for(auto x = 0; x != m_width; x++)
   {
      for(auto y = 0; y != m_height; y++)
      {
         if (GetValue(x,y) == 1 )
         {
            target.draw(m_circleVector[x][y],states);
         }
      }
   }
}

void SFMLVisualGrid::draw(RenderTarget& target, RenderStates states) const
{
   states.transform *= getTransform();
   
   target.draw(m_gridLines,states);
   DrawCircles(target,states);
}

void SFMLVisualGrid::SetValue (unsigned int x, unsigned int y, unsigned short value)
{
   Grid::SetValue(x,y,value);
}
