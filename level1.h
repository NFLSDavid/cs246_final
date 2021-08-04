#ifndef _LEVEL1_H_
#define _LEVEL1_H_

#include <vector>
#include <memory>
#include <queue>
#include <string>
#include "level.h"

using namespace std;

class Cell;
class Block;
class Level1: public Level {
    
    shared_ptr<Block> produceBlock(char);
    bool checkfull(int row_num);

    public:
    Level1();
    //void update();
    void newBlock() override;
    void printNextBlock() override;
    //void initAllCells();
    //void restart();
    //void clear();
    //void print();
    /*void force();
    void blind();
    void heavy();*/

    /*void curRight();
    void curLeft();
    void curDown();
    void curCC();
    void curC();
    void curDrop();*/

    // for testing
    //void printBoard();
    ~Level1();
};

#endif
