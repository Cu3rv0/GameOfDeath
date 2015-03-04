#pragma once
#include <vector>

class GridInterface {

public:
   virtual ~GridInterface() {}
   
   virtual unsigned short GetValue(unsigned int, unsigned int) const = 0;
   virtual void SetValue (unsigned int, unsigned int, unsigned short) = 0;

   virtual unsigned int GetHeight() const = 0;
   virtual unsigned int GetWidth() const = 0;
   virtual std::string GetGridString() const = 0;
   virtual const std::vector<std::vector<unsigned short> >& GetValues() const = 0;
   
   virtual GridInterface& operator=(const GridInterface& rhs) = 0;

};
