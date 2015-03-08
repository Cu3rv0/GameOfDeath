#pragma once


class GameInterface 
{
public:
   virtual ~GameInterface() {}

   virtual void Run() = 0;
};
