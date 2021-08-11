#ifndef _LEVEL0_H_
#define _LEVEL0_H_
#include "level.h"

class Level0: public Level {
    public: 
    Level0(std::shared_ptr<abc_board> c);
    int getLevel() const override;
    bool newBlock() override;
    void setNextType() override;
    void judge(int) override;
};

#endif
