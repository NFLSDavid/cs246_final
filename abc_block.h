/*#ifndef __ABC_BLOCK_H__
#define __ABC_BLOCK_H__
using namespace std;

class Board;

class abc_block {
    protected:
    bool valid;
    
    public:
    Board *b;

    abc_block(Board *b);
    virtual void clockwise() = 0;
    virtual void counterclockwise() = 0;
    virtual void left() = 0;
    virtual void right() = 0;
    virtual void down() = 0;
    virtual void up() = 0;
    virtual void drop() = 0;
    virtual ~abc_block() = 0;
 };


#endif*/
