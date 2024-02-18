#include "Grid.h"

void Grid::printGrid()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }
}

bool Grid::canPlaceHorizontalVertical(int x, int y)
{
    // Проверяем, не вышли ли мы за пределы сетки
    if (x < 0 || x >= N || y < 0 || y >= N)
    {
        return false;
    }
    // Проверяем, не занята ли уже эта позиция
    if (grid[x][y] == '*')
    {
        return false;
    }
    // Подсчитываем количество символов * в текущей строке и столбце
    int row_count = 0, col_count = 0;
    for (int i = 0; i < N; ++i)
    {
        if (grid[x][i] == '*')
        {
            row_count++;
        }
        if (grid[i][y] == '*')
        {
            col_count++;
        }
    }
    // Проверяем, не превышает ли количество символов * два
    if (row_count >= 2 || col_count >= 2)
    {
        return false;
    }
    // Если все проверки пройдены, то возвращаем true
    return true;
}

void Grid::generateCombinations(int P, bool showGrids)
{
    int total = 0;
    for (int P = 1; P <= N * N; ++P)
    {
        int count = 0;
        backtrack(0, 0, P, count, showGrids);
        total += count;
        std::cout << "Для P = " << P << " количество решений = " << count << "\n";
    }
    std::cout << "Сумма общих решений = " << total << "\n";
}

void Grid::backtrack(int x, int y, int P, int &count, bool showGrids)
{
    if (P == 0)
    {
        count++;
        if (showGrids)
        {
            printGrid();
            std::cout << "\n";
        }
        return;
    }
    // Если координаты выходят за пределы сетки, пропускаем итерацию.
    if (x >= N || y >= N)
    {
        return;
    }

    // Проверяем, если можно разместить символ в данной ячейке.
    if (canPlace(x, y))
    {
        // Размещаем символ.
        grid[x][y] = '*';

        // Рекурсивно вызываем backtrack для следующей позиции в той же строке.
        backtrack(x, y + 1, P - 1, count, showGrids);

        // Убираем символ, чтобы попробовать другие пути.
        grid[x][y] = '-';
    }

    // Рекурсивно вызываем backtrack для следующей позиции в следующей строке.
    backtrack(x + (y + 1) / N, (y + 1) % N, P, count, showGrids);
}
