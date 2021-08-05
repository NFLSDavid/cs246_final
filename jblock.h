#ifndef _JBLOCK_H_
#define _JBLOCK_H_

#include "block.h"
using namespace std;

class jblock : public Block {
    public:
    jblock(Board *b, int level, char type);
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
