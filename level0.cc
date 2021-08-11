#include "level0.h"

Level0::Level0(std::shared_ptr<abc_board> c) : Level{c} {}

int Level0::getLevel() const {
    return 0;
}

void Level0::setNextType() {
    setNext(getGeneratedFront());
    popGenerated();
    auto b = produceBlock(getNextType());
    clearNextDisplay();
    b->initBlock(0, 21);
}

bool Level0::newBlock() {
    pushBackToGenerated(getNextType());
    //toBeGenerated.push(nextBlockType);
    auto b = produceBlock(getNextType());
    pushActiveBlocks(b);
    bool s = b->initBlock(0, 3);
    setNextType();
    return s;
}

void Level0::judge(int) {}
