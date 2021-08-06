#ifndef _LEVEL3_H_
#define _LEVEL3_H_

#include <vector>
#include <memory>
#include <queue>
#include <string>
#include "level.h"

using namespace std;

class Cell;

class Block;

class Level3: public Level {
    private:
        bool random = true;
        string filename3;
        queue <char> toBeGenerated3;
    public:
        void init3(string name);
        Level3(abc_board *c);
        int getLevel() const override;
        bool newBlock() override;
        void setNextType() override;
        void judge(int) override;
};

#endif
