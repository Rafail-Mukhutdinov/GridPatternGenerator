#include "HorizontalVerticalGrid.h"

HorizontalVerticalGrid::HorizontalVerticalGrid(int N) : Grid(N) {}

bool HorizontalVerticalGrid::canPlace(int x, int y)
{
    return canPlaceHorizontalVertical(x, y);
}
