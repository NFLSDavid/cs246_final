#ifndef _LEVEL_H_
#define _LEVEL_H_
#include "abc_board.h"

class Level: public abc_board {
    public:
    // accessors:
    
    char getGeneratedFront() const override;
    int getLevel() const override;
    char getNextType() const override;

    //mutator
    void pushActiveBlocks(shared_ptr<Block> b) override; 
    void pushBackToGenerated(char) override; 
    void popGenerated() override; 
    void setNext(char) override; // directly set nextBlockType 

    // methods on the board:
    void initAllCells() override;
    void restart() override;
    void clear() override;
    void initfs(string filename) override;
    void print() override;
    /*void force();
    void blind();
    void heavy();*/

    // methods to create blocks:
    shared_ptr<Block> produceBlock(char c) override;
    Block* getCurrBlock() override;
    void popCurrBlock() override;
    void pushCurrBlock(shared_ptr<Block> b) override;
    void changeCurrBlock(char type) override;
    virtual void newBlock() override = 0;
    virtual void setNextType() override = 0;
    void clearNextDisplay() override;

    // methods to move blocks:
    virtual void curRight() override;
    virtual void curLeft() override;
    virtual void curDown() override;
    virtual void curCC() override;
    virtual void curC() override;
    void curDrop() override;

    // for testing
    void printBoard() override;
    void printNextBlock(char) override;
    void printLevelLine() override;
    void printScoreLine() override;
    void printRows(int r) override;

    protected:
        Level(abc_board *c);
        abc_board *component;
};

#endif
