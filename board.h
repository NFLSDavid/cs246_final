#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>
using namespace std;
class Cell;

class Board {
    public:
    vector <vector<Cell*>> cells;

    void initAllCells();
};

#endif
