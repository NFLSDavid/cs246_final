#ifndef _BLIND_H_
#define _BLIND_H_

#include <vector>
#include <memory>
#include <queue>
#include <string>
#include "level.h"

using namespace std;

class Cell;

class Block;

class Blind: public Level {
    private:
        bool isBlinded;  // the board isBlinded
    public:
        Blind(std::shared_ptr<abc_board> c);
        void unblind();
        int getLevel() const override;
        bool newBlock() override;
        void setNextType() override;
        void judge(int) override;
        void curDrop() override;
};

#endif
