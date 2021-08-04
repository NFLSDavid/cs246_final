#ifndef _IBLOCK_H_
#define _IBLOCK_H_

#include "block.h"
using namespace std;

class iblock : public Block {
    public:
    iblock(Board *b, char type);
    bool initBlock(int x, int y) override;
    //void initNextBlock() override;
    void clockwise() override;
    void counterclockwise() override;

    private:
    void moveClockwise();
};


#endif
