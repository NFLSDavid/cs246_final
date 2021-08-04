#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>
#include <memory>
#include <queue>
#include <string>
//#include "block.h"

using namespace std;

class Cell;
class Block;
class Board {
    private:
    string filename;
    queue <char> toBeGenerated;
    vector <shared_ptr<Block>> active_blocks;
    //shared_ptr<Block> nextBlock;
    
    int level;
    int score;          //可能要改改
    shared_ptr<Block> produceBlock(char);
    bool checkfull(int row_num);

    public:
    vector <vector <shared_ptr<Cell>>> cells;

    Board(string filename);
    void update();
    void newBlock();
    void initAllCells();
    void restart();
    void clear();
    void print();
    void force();
    void blind();
    void heavy();

    void curRight();
    void curLeft();
    void curDown();
    void curCC();
    void curC();
    void curDrop();

    // for testing
    void printBoard();
    ~Board();
};

#endif
