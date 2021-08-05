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
    public:
        void newBlock() override;
        void setNextType() override;
        void curRight() override;
        void curLeft() override;
        void curDown() override;
        void curCC() override;
        void curC() override;
        ~Level3();
    private:
        void heavyOne();
};

#endif
