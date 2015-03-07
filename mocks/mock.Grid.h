#pragma once

#include <vector>
#include <string>
#include "GridInterface.h"


class MockGrid : public GridInterface
{
public:
   MockGrid(unsigned int,unsigned int);

   unsigned short GetValue(unsigned int, unsigned int) const;
   void SetValue (unsigned int, unsigned int, unsigned short);

   unsigned int GetHeight() const;
   unsigned int GetWidth() const;

   std::string GetGridString() const;
   const std::vector<std::vector<unsigned short> >& GetValues() const;

   GridInterface& operator=(const GridInterface& rhs);

private:
   unsigned int m_height;
   unsigned int m_width;
   std::vector<std::vector<unsigned short> > m_values;   

}
