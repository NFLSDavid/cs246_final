#include "level2.h"
#include <cstdlib>

void Level2::newBlock() {
    char c = component->getNextType();
    auto b = produceBlock(c);
    auto v = component->getActiveBlocks();
    v.push_back(b);
    b->initBlock(0, 3);
    setNextType();
}

void Level2::setNextType() {
    int i = rand() % 7;
    char c;
    if (i == 0) {
        c = 'S';
    } else if (i == 1) {
        c = 'Z';
    } else if (i == 2) {
        c = 'O';
    } else if (i == 3) {
        c = 'J';
    } else if (i == 4) {
        c = 'L';
    } else if (i == 5) {
        c = 'I';
    } else if (i == 6) {
        c = 'T';
    } 
    auto b = component->produceBlock(c);
    component->clearNextDisplay();
    b->initBlock(0, 21);
}
