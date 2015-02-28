#include <vector>
#include <string>

class Grid
{
public:
   Grid(unsigned int,unsigned int);

   unsigned short GetValue(unsigned int, unsigned int) const;
   void SetValue (unsigned int, unsigned int, unsigned short);

   unsigned int GetHeigth() const;
   unsigned int GetWidth() const;

   std::string GetGridString() const;

private:
   const unsigned int m_height;
   const unsigned int m_width;
   std::vector<std::vector<unsigned short> > m_values;   

};
