#include "AllDirectionGrid.h"

AllDirectionGrid::AllDirectionGrid(int N) : Grid(N) {}

bool AllDirectionGrid::canPlace(int x, int y)
{
    if (!canPlaceHorizontalVertical(x, y))
    {
        return false;
    }
    // Проверяем диагонали
    int diag1_count = 0, diag2_count = 0;
    for (int i = 0; i < N; ++i)
    {
        if (x + i < N && y + i < N && grid[x + i][y + i] == '*')
        {
            diag1_count++;
        }
        if (x - i >= 0 && y - i >= 0 && grid[x - i][y - i] == '*')
        {
            diag2_count++;
        }
    }
    if (diag1_count >= 2 || diag2_count >= 2)
    {
        return false;
    }
    // Если все проверки пройдены, то возвращаем true
    return true;
}
