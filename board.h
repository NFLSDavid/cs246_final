#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>
#include <memory>
#include "block.h"

using namespace std;

class Cell;

class Board {
    private:
    vector <shared_ptr<Block>> active_blocks;
    bool checkfull(int row_num);
    int score = 0;

    public:
    vector <vector <shared_ptr<Cell>>> cells;

    void initAllCells();
    void restart();
    void clear();
    void print();
    void force();
    void blind();
    void heavy();
    ~Board();
};

#endif
