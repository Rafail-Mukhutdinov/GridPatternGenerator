#include "Grid.h"

class AllDirectionGrid : public Grid
{
public:
    AllDirectionGrid(int N);
    bool canPlace(int x, int y) override;
};
