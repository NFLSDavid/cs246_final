//#include "abc_block.h"
#ifndef _LEVEL_H_
#define _LEVEL_H_
#include "abc_board.h"
/*class Level: public abc_block {
    public:
    virtual void clockwise();
    virtual void counterclockwise();

    virtual void left();
    virtual void right();
    virtual void down();
    virtual void up();
    void drop();
    virtual ~Level();

    protected:
    Level(abc_block *c);
    abc_block *component;
};*/

class Level: public abc_board {
    public:
    Block* getCurrBlock();
    void popCurrBlock();
    void pushCurrBlock(shared_ptr<Block> b);
    void changeCurrBlock(char type);
    void update();
    virtual void newBlock() = 0;
    void printNextBlock(char);
    void initAllCells();
    void restart();
    void clear();
    void print();
    /*virtual void force();
    virtual void blind();
    virtual void heavy();*/
    shared_ptr<Block> produceBlock(char);

    void curRight();
    void curLeft();
    void curDown();
    void curCC();
    void curC();
    void curDrop();

    // for testing
    void printBoard();
    void initfs(string filename);
    virtual void setNextType();
    void clearNextDisplay();
    void printLevelLine();
    void printScoreLine();
    void printRows(int);
    virtual ~Level();

    protected:
        Level(abc_board *c);
        abc_board *component;
};

#endif
