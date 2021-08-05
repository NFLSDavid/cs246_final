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
    public:
        void newBlock() override;
        void setNextType() override;
        void curRight() override;
        void curLeft() override;
        void curDown() override;
        void curCC() override;
        void curC() override;
        ~Level4();
    
    private:
        int countNotCleared;  //如果%5 = 0 且不等于0, 就drop (在每次drop函数的时候check并unpdate)

        bool dropStar(); // if dropped successfully, return true
    
};

#endif
