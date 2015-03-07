#include "gtest/gtest.h"
#include "Grid.h"
#include <memory>

using namespace std;

class GridTests: public ::testing::Test
{
public:
   unique_ptr<Grid> m_grid;

   GridTests():
      m_grid(make_unique<Grid>(3,4))
   {
   }
   ~GridTests() {}
};


TEST_F(GridTests, grid_returns_encoded_string_for_a_simple_shape)
{
   //Given
      const string expected = "..*\n"
                              ".*.\n"
                              "*..\n"
                              "...\n";
   //When
      m_grid->SetValue(0,2,1);
      m_grid->SetValue(1,1,1);
      m_grid->SetValue(2,0,1);
   //Then
      ASSERT_EQ(expected,m_grid->GetGridString());
}

//TEST_F(GridTests, grid_
