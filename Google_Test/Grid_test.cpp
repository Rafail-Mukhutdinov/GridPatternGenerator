#include <gtest/gtest.h>
#include "../GridPatternGenerator/HorizontalVerticalGrid.h"
#include "../GridPatternGenerator/AllDirectionGrid.h"
#include "../GridPatternGenerator/Grid.h"

class GridTest : public Grid, public testing::Test
{
protected:
  // Вызывает конструктор базового класса Grid с размером сетки 4
  GridTest() : Grid(4) {}

  // Метод, который вызывается перед каждым тестом
  void SetUp() override
  {
    // Заполняем сетку символами * по диагонали
    for (int i = 0; i < N; ++i)
    {
      grid[i][i] = '*';
    }
  }

  // Метод, который вызывается после каждого теста
  void TearDown() override
  {
    // Очищаем сетку, заполняя ее символами -
    for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j < N; ++j)
      {
        grid[i][j] = '-';
      }
    }
  }

  // Добавляем чисто виртуальную функцию canPlace, чтобы сделать класс GridTest абстрактным
  virtual bool canPlace(int x, int y) = 0;
};

// Создаем подкласс GridTest для горизонтальной и вертикальной сетки
class HorizontalVerticalGridTest : public GridTest
{
protected:
  // Реализуем функцию canPlace, используя метод canPlaceHorizontalVertical из класса HorizontalVerticalGrid
  bool canPlace(int x, int y) override
  {
    HorizontalVerticalGrid hvg(N);
    hvg.getGrid() = grid;
    return hvg.canPlaceHorizontalVertical(x, y);
  }
};

TEST(GridTest, Constructor)
{
  std::unique_ptr<Grid> grid = std::make_unique<AllDirectionGrid>(5);
  EXPECT_EQ(grid->getN(), 5);
  for (int i = 0; i < 5; ++i)
  {
    for (int j = 0; j < 5; ++j)
    {
      EXPECT_EQ(grid->getGrid()[i][j], '-');
    }
  }
}

// Возвращает false для координат, выходящих за пределы сетки.
TEST_F(HorizontalVerticalGridTest, CanPlace_OutOfGrid)
{
  EXPECT_FALSE(canPlace(-1, 0));
  EXPECT_FALSE(canPlace(4, 0));
  EXPECT_FALSE(canPlace(0, -1));
  EXPECT_FALSE(canPlace(0, 4));
}

// Возвращает false для ячеек, уже занятых символом '*'
TEST_F(HorizontalVerticalGridTest, CanPlace_Occupied)
{
  grid[0][0] = '*';
  EXPECT_FALSE(canPlace(0, 0));
}

// Возвращает false для ячеек, в которых уже есть два символа '*' в строке.
TEST_F(HorizontalVerticalGridTest, CanPlace_TooManyStarsInRow)
{
  for (int i = 0; i < 2; ++i)
  {
    grid[0][i] = '*';
  }
  EXPECT_FALSE(canPlace(0, 2));
}

// Возвращает false для ячеек, в которых уже есть два символа '*' в том же столбце.
TEST_F(HorizontalVerticalGridTest, CanPlace_TooManyStarsInColumn)
{
  for (int i = 0; i < 2; ++i)
  {
    grid[i][0] = '*';
  }
  EXPECT_FALSE(canPlace(2, 0));
}
