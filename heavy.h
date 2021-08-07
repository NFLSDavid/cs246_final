#ifndef _HEAVY_H_
#define _HEAVY_H_

#include <vector>
#include <memory>
#include <queue>
#include <string>
#include "level.h"

using namespace std;

class Cell;

class Block;

class Heavy: public Level {
    private:
        bool isHeavy;
    public:
        Heavy(abc_board *c);
        int getLevel() const override;
        bool newBlock() override;
        void setNextType() override;
        void judge(int) override;
        void curDrop() override;
        bool curLeft() override;
        bool curRight() override;
};

#endif
