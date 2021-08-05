#ifndef _SZBLOCK_H_
#define _SZBLOCK_H_

#include "block.h" 
using namespace std;

class szblock : public Block {
    public:
    szblock(Board *b, int level, char type);
    bool initBlock(int x, int y) override;
    //void initNextBlock() override;
    void clockwise() override;
    void counterclockwise() override;

    private:
    bool judgeGraph(); // return true if vertical
    void moveClockwise();
};


#endif
