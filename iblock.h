#ifndef _I_BLOCK_
#define _I_BLOCK_

#include "block.h"
using namespace std;

class Board;

class iblock : public Block {
    public:
    iblock(Board *b, char type);
    bool initBlock() override;
    void clockwise() override;
    void counterclockwise() override;
    ~iblock();

    private:
    void moveClockwise();
    void moveCounterclockwise();
};


#endif
