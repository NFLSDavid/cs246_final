#include "level1.h"
using namespace std;

void Level1::newBlock() {
    auto b = produceBlock(nextBlockType);
    active_blocks.push_back(b);
    b->initBlock(0, 3);
    setNextType();
}


