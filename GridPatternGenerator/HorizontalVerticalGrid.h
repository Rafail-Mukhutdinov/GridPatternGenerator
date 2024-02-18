#include "Grid.h"

class HorizontalVerticalGrid : public Grid
{
public:
    HorizontalVerticalGrid(int N);
    bool canPlace(int x, int y) override;
};
