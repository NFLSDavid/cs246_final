#ifndef _T_BLOCK_H_
#define _T_BLOCK_H_

#include "block.h"
using namespace std;

class tblock : public Block {
    public:
    tblock(Board *b, int level, char type);
    bool initBlock(int x, int y) override;
    //void initNextBlock() override;
    void clockwise() override;
    void counterclockwise() override;

    private:
    void moveClockwise();
    void moveCounterClockwise();
    bool pOccupied();
    char judgeGraph();
};

#endif
