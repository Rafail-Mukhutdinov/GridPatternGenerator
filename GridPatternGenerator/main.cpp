#include <iostream>
#include <vector>
#include "grid.h"
#include "allDirectionGrid.h"
#include "horizontalVerticalGrid.h"

int main()
{
    // Вводим размер сетки N
    int N;
    std::cout << "Введите размер сетки N: ";
    std::cin >> N;
    bool showGrids;
    std::cout << "Хотите ли вы видеть сетки с конструкциями? (true/false): ";
    std::cin >> std::boolalpha >> showGrids;

    // Выбрать метод расчета
    int method;
    std::cout << "Выберите метод расчета (1 - только горизонтальные и вертикальные узлы, 2 - все направления): ";
    std::cin >> method;

    // Создаем объект нужного класса в зависимости от выбора
    Grid *grid;
    if (method == 1)
    {
        grid = new HorizontalVerticalGrid(N);
    }
    else
    {
        grid = new AllDirectionGrid(N);
    }

    // Генерируем все комбинации из N символов
    grid->generateCombinations(N, showGrids);

    // Удаляем объект
    delete grid;

    return 0;
}