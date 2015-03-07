#pragma once

#include "VisualFrontEndInterface.h"

class AsciiVisualFrontEnd : public VisualFrontEndInterface
{
   public:

      AsciiVisualFrontEnd(GameOfLifeInterface& gameOfLife);
      void Draw();

   private:
      const GameOfLifeInterface& m_gameOfLife;
}
