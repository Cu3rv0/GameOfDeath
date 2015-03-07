#include "Grid.h"
#include <SFML/Graphics.hpp>
#include <vector>

class SFMLVisualGrid : public sf::Drawable, public Grid
{
public:

   SFMLVisualGrid(unsigned int, unsigned int);
   
   void draw(sf::RenderTarget& target, sf::RenderStates states) const {}


private:
   sf::VertexArray m_gridLines;

   unsigned int m_squareWidth;
   unsigned int m_squareHeight;
};
