#ifndef _LBLOCK_H_
#define _LBLOCK_H_

#include "block.h"
using namespace std;

class lblock : public Block {
    public:
    lblock(Board *b, char type);
    bool initBlock(int x, int y) override;
    void clockwise() override;
    void counterclockwise() override;

    private:
    void moveClockwise();
    void moveCounterClockwise();
    bool pOccupied();
    char judgeGraph();
};

#endif
