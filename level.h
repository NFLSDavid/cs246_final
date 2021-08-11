#ifndef _LEVEL_H_
#define _LEVEL_H_
#include "abc_board.h"

class Level: public abc_board {
    public:
    // accessors:
    virtual ~Level();

    char getGeneratedFront() const override;
    virtual int getLevel() const = 0;
    char getNextType() const override;
    int getHiScore() const override;
    int getCurrentScore() const override;
    vector <vector <shared_ptr<Cell>>> getBoard() const override;

    //mutator
    void pushActiveBlocks(shared_ptr<Block> b) override; 
    void pushBackToGenerated(char) override; 
    void popGenerated() override; 
    void setNext(char) override; // directly set nextBlockType 
    void setCurrentScore(int) override;
    void setHiScore() override;

    // methods on the board:
    void initAllCells() override;
    void restart() override;
    int clear() override;
    //virtual void judge(int) = 0;
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
    //virtual bool newBlock() = 0;
    //virtual void setNextType() = 0;
    void clearNextDisplay() override;

    // methods to move blocks:
    virtual bool curRight() override;
    virtual bool curLeft() override;
    virtual void curDown() override;
    virtual void curCC() override;
    virtual void curC() override;
    void curDrop() override;
    void heavyOne();

    // for testing
    void printBoard() override;
    void printNextBlock(char) override;
    void printLevelLine() override;
    void printScoreLine() override;
    void printRows(int r) override;

    protected:
        // Level(abc_board *c);
        // abc_board *component;

        Level( std::shared_ptr<abc_board> c );
        std::shared_ptr<abc_board> component; 
        
};

#endif
