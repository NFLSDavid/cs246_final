#ifndef _ABC_BOARD_H_
#define _ABC_BOARD_H_

#include <memory>
class Cell;
class Block;
class abc_board {
    public:

    virtual void update() = 0;
    virtual void newBlock() = 0;
    virtual void printNextBlock() = 0;
    virtual void initAllCells() = 0;
    virtual void restart() = 0;
    virtual void clear() = 0;
    virtual void print() = 0;
    /*virtual void force();
    virtual void blind();
    virtual void heavy();*/
    virtual std::shared_ptr<Block> produceBlock(char) = 0;

    virtual void curRight() = 0;
    virtual void curLeft() = 0;
    virtual void curDown() = 0;
    virtual void curCC() = 0;
    virtual void curC() = 0;
    virtual void curDrop() = 0;

    // for testing
    virtual void printBoard() = 0;
    ~abc_board();
};

#endif
