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
    public:
        void newBlock() override;
        void setNextType() override;
};

#endif
