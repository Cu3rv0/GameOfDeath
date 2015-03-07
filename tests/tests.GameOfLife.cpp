#include "gtest/gtest.h"
#include "GameOfLife.h"
#include <memory>
#include "Grid.h"

#define GRID_WIDTH 5
#define GRID_HEIGHT 5

using namespace std;

class GameOfLifeTests: public ::testing::Test
{
   public:
      
      unique_ptr<Grid> m_lifeGrid;
      unique_ptr<Grid> m_lastGrid;
      unique_ptr<GameOfLife> m_gameOfLife;

      GameOfLifeTests():
         m_lifeGrid(make_unique<Grid>(GRID_WIDTH,GRID_HEIGHT)),
         m_lastGrid(make_unique<Grid>(GRID_WIDTH,GRID_HEIGHT)),
         m_gameOfLife(make_unique<GameOfLife>(*m_lifeGrid,*m_lastGrid))
      {
      }
};

TEST_F(GameOfLifeTests, AdvanceGeneration_produces_correct_result_simple_example)
{
   //Given
   m_lifeGrid->SetValue(2,1,1);
   m_lifeGrid->SetValue(3,1,1);
   m_lifeGrid->SetValue(1,2,1);
   m_lifeGrid->SetValue(2,2,1);
   m_lifeGrid->SetValue(2,3,1);


   string original = ".....\n"
                     "..**.\n"
                     ".**..\n"
                     "..*..\n"
                     ".....\n";


   ASSERT_EQ(original,m_lifeGrid->GetGridString());

   //When
   m_gameOfLife->AdvanceGeneration();

   //Then
   string expected = ".....\n"
                     ".***.\n"
                     ".*...\n"
                     ".**..\n"
                     ".....\n";

   ASSERT_EQ(expected,m_lifeGrid->GetGridString());
   
}
