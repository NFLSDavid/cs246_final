#ifndef _LEVEL2_H_
#define _LEVEL2_H_

#include <vector>
#include <memory>
#include <queue>
#include <string>
#include "level.h"

using namespace std;

class Cell;

class Block;

class Level2: public Level {
    public:
        Level2(abc_board *c);
        int getLevel() const override;
        bool newBlock() override;
        void setNextType() override;
        void judge(int) override;
};

#endif
