#pragma once
#include <iostream>
#include <vector>

class Grid
{
protected:
    int N;                               // размер сетки
    std::vector<std::vector<char>> grid; // сетка
public:
    Grid(int N) : N(N), grid(N, std::vector<char>(N, '-')) {} // конструктор
    virtual bool canPlace(int x, int y) = 0;                  // чисто виртуальная функция
    bool canPlaceHorizontalVertical(int x, int y);            // общий метод для проверки горизонтальных и вертикальных линий
    void printGrid();                                         // функция для вывода сетки на экран
    void generateCombinations(int P, bool showGrids);         // функция для генерации всех комбинаций из P символов *
    int getN() const { return N; }                            // метод для получения размера сетки
    void backtrack(int x, int y, int P, int &count, bool showGrids);
    std::vector<std::vector<char>> &getGrid() { return grid; } // метод для получения сетки
};