#ifndef _T_BLOCK_H_
#define _T_BLOCK_H_

#include "block.h" 
using namespace std;

class tblock : public Block {
    public:
    tblock(Board *b, char type);
    bool initBlock() override;
    void clockwise() override;
    void counterclockwise() override;

    private:
    bool judgeGraph(); // return true if vertical
    void moveClockwise();
};


#endif
