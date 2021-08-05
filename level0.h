#ifndef _LEVEL0_H_
#define _LEVEL0_H_
#include "level.h"
class Level0: public Level {
    void newBlock() override;
    void setNextType() override;
};

#endif
