#ifndef _ZBLOCK_H_
#define _ZBLOCK_H_

#include "block.h" 
using namespace std;

class zblock : public Block {
    public:
    zblock(Board *b, char type);
    bool initBlock() override;
    void clockwise() override;
    void counterclockwise() override;

    private:
    bool judgeGraph(); // return true if vertical
    void moveClockwise();
};


#endif
