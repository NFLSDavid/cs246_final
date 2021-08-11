#ifndef _LEVEL4_H_
#define _LEVEL4_H_

#include <vector>
#include <memory>
#include <queue>
#include <string>
#include "level.h"

using namespace std;

class Cell;

class Block;

class Level4: public Level {
    private:
        bool clearedMinimum = false; // if cleared at least one row, true
        bool random = true;
        string filename4;
        queue <char> toBeGenerated4;
    public:
        //void init4(string name);
        void initfs(string name) override;
        int getLevel() const override;
        // Level4(abc_board *c);
        Level4( std::shared_ptr<abc_board> c ); 
        bool newBlock() override;
        void setNextType() override;
        //void curDrop() override;
        int countNotCleared = 0;  //如果%5 = 0 且不等于0, 就drop (在每次drop函数的时候check并unpdate)
        bool dropStar(); // if dropped successfully, return true
        void judge(int rowsCleared) override;
};

#endif
