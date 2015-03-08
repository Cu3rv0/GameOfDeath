#pragma once
#include "Grid.h"
#include <SFML/Graphics.hpp>
#include <vector>

class SFMLVisualGrid : public sf::Drawable,
                       public sf::Transformable,
                       public Grid
{
public:

   SFMLVisualGrid(unsigned int, unsigned int);
   
   void draw(sf::RenderTarget& target, sf::RenderStates states) const;

   void SetValue (unsigned int, unsigned int, unsigned short);

private:
   sf::VertexArray m_gridLines;


   void ConstructGrid();
   void ConstructVerticalLines();
   void ConstructHorizontalLines();
   void ConstructCircles();

   void DrawCircles(sf::RenderTarget& target, sf::RenderStates states) const;
   static const unsigned int SquareSideInPX = 30;
   static const unsigned int LineWidthInPX = 2;
   static const unsigned int CircleRadiusInPX = 8;
   std::vector<std::vector<sf::CircleShape> > m_circleVector;
};
