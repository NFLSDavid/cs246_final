#ifndef _ABC_BOARD_H_
#define _ABC_BOARD_H_

#include <memory>
#include <vector>
#include "block.h"
using namespace std;
class Cell;
//class Block;
class abc_board {
    public:

    virtual Block* getCurrBlock() = 0;
    virtual void popCurrBlock() = 0;
    virtual void pushCurrBlock(shared_ptr<Block> b) = 0;
    virtual void changeCurrBlock(char type) = 0;
    virtual void newBlock() = 0;
    virtual void printNextBlock(char) = 0;
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
    virtual void initfs(string filename) = 0;
    virtual void setNextType() = 0;
    virtual void clearNextDisplay() = 0;

    virtual void printLevelLine() = 0;
    virtual void printScoreLine() = 0;
    virtual void printRows(int) = 0;
    virtual int getLevel() = 0;
    virtual char getNextType() = 0;
    virtual vector<shared_ptr<Block>> * getActiveBlocks() = 0;
    virtual ~abc_board();
};

#endif
