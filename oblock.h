#ifndef _OBLOCK_H_
#define _OBLOCK_H_

#include "block.h"
using namespace std;

class oblock: public Block {
    public:
    oblock(abc_board *b, int level, char type);
    bool initBlock(int x, int y) override;
    //void initNextBlock() override;
    void clockwise() override;
    void counterclockwise() override;
};


#endif
