#include "level0.h"

void Level0::setNextType() {
    setNext(component->getGeneratedFront());
    component->popGenerated();
    auto b = component->produceBlock(component->getNextType());
    component->clearNextDisplay();
    b->initBlock(0, 21);
}

void Level0::newBlock() {
    component->pushBackToGenerated(component->getNextType());
    //toBeGenerated.push(nextBlockType);
    auto b = component->produceBlock(component->getNextType());
    component->pushActiveBlocks(b);
    b->initBlock(0, 3);
    setNextType();
}

