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
    virtual ~abc_board();
    // accessors:
    //virtual vector<shared_ptr<Block>> getActiveBlocks() const = 0;
    virtual char getGeneratedFront() const = 0;
    virtual int getLevel() const = 0;
    virtual char getNextType() const = 0;
    virtual int getHiScore() const = 0;
    virtual int getCurrentScore() const = 0;
    virtual vector <vector <shared_ptr<Cell>>> getBoard() const = 0;

    //mutators
    virtual void pushActiveBlocks(shared_ptr<Block> b) = 0; 
    virtual void pushBackToGenerated(char) = 0; 
    virtual void popGenerated() = 0; 
    virtual void setNext(char) = 0; // directly set nextBlockType
    virtual void setCurrentScore(int) = 0;
    virtual void setHiScore() = 0;

    // methods on the board:
    virtual void initAllCells() = 0;
    virtual void restart() = 0;
    virtual int clear() = 0;
    virtual void judge(int) = 0;
    virtual void initfs(string filename) = 0;
    virtual void print() = 0;
    /*virtual void force();
    virtual void blind();
    virtual void heavy();*/

    // methods to create blocks:
    virtual shared_ptr<Block> produceBlock(char c) = 0;
    virtual Block* getCurrBlock() = 0;
    virtual void popCurrBlock() = 0;
    virtual void pushCurrBlock(shared_ptr<Block> b) = 0;
    virtual void changeCurrBlock(char type) = 0;
    virtual bool newBlock() = 0;
    virtual void setNextType() = 0;
    virtual void clearNextDisplay() = 0;

    // methods to move blocks:
    virtual bool curRight() = 0;
    virtual bool curLeft() = 0;
    virtual void curDown() = 0;
    virtual void curCC() = 0;
    virtual void curC() = 0;
    virtual void curDrop() = 0;

    // for testing
    virtual void printBoard() = 0;
    virtual void printNextBlock(char) = 0;
    virtual void printLevelLine() = 0;
    virtual void printScoreLine() = 0;
    virtual void printRows(int r) = 0;
};

#endif
