#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>
#include <memory>
#include <queue>
#include <string>
#include "abc_board.h"

using namespace std;

class Cell;
class Block;
class Board: public abc_board {
    private:
    string filename;
    queue <char> toBeGenerated;
    vector <shared_ptr<Block>> active_blocks;
    //shared_ptr<Block> nextBlock;
    
    int level;
    int score;          //可能要改改
    bool checkfull(int row_num);

    public:
    vector <vector <shared_ptr<Cell>>> cells;

    Board(string filename);
    void update() override;
    shared_ptr<Block> produceBlock(char) override;
    void newBlock() override;
    void printNextBlock() override;
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
