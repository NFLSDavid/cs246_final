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
    char nextBlock;
    queue <char> toBeGenerated;
    vector <shared_ptr<Block>> active_blocks;
    
    int level;
    int score;          //可能要改改
    bool checkfull(int row_num);

    public:
    vector <vector <shared_ptr<Cell>>> cells;

    Board(string filename);
    Block* getCurrBlock() override;
    void popCurrBlock() override;
    void pushCurrBlock(shared_ptr<Block> b) override;
    void update() override;
    shared_ptr<Block> produceBlock(char) override;
    void newBlock() override;
    void printNextBlock(char) override;
    void initAllCells() override;
    void restart() override;
    void clear() override;
    void print() override;
    /*void force();
    void blind();
    void heavy();*/

    void curRight() override;
    void curLeft() override;
    void curDown() override;
    void curCC() override;
    void curC() override;
    void curDrop() override;

    // for testing
    void printBoard() override;
    ~Board();
};

#endif
