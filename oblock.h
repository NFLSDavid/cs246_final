#ifndef _OBLOCK_H_
#define _OBLOCK_H_

#include "block.h"
using namespace std;

class oblock : public Block {
    public:
    oblock(Board *b, char type);
    bool initBlock() override;
    void clockwise() override;
    void counterclockwise() override;
};


#endif
