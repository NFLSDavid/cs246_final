#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>
#include <memory>
#include <queue>
#include <string>
#include "abc_board.h"
#include "block.h"
using namespace std;

class Cell;
//class Block;
class Board: public abc_board {
    private:
    string filename;
    char nextBlockType;
    queue <char> toBeGenerated;
    vector <shared_ptr<Block>> active_blocks;
    
    
    int level;
    int currentScore;          //可能要改改
    int hiScore;               // 在call restart的时候，我会compare currentScore和hiScore, 然后把
                               // 更高的score存在hiScore里
    bool checkfull(int row_num);

    // helpers to print board
    
    public:
    vector <vector <shared_ptr<Cell>>> cells;
    Xwindow *w;
    Board(string filenname);
    ~Board();

    // accessors:
    char getGeneratedFront() const override;
    int getLevel() const override;
    char getNextType() const override;
    int getHiScore() const override;
    int getCurrentScore() const override;
    vector <vector <shared_ptr<Cell>>> getBoard() const override;

    //mutators
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
    void judge(int) override;
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
    bool newBlock() override;
    void setNextType() override;
    void clearNextDisplay() override;

    // methods to move blocks:
    bool curRight() override;
    bool curLeft() override;
    void curDown() override;
    void curCC() override;
    void curC() override;
    void curDrop() override;

    // for testing
    void printBoard(Xwindow *w, int player) override;
    void printNextBlock(char) override;
    void printLevelLine(Xwindow *w, int lc_x, int lc_y, int player) override;
    void printScoreLine(Xwindow *w, int lc_x, int lc_y, int player) override;
    void printRows(int r, Xwindow *w, int player) override;
};

#endif
