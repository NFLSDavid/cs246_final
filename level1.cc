#include "level1.h"
#include <cstdlib>

void Level1::newBlock() {
    char c = component->getNextType();
    auto b = produceBlock(c);
    component->pushActiveBlocks(b);
    b->initBlock(0, 3);
    setNextType();
}

void Level1::setNextType() {
    int i = rand() % 12;
    char c;
    if (i == 0) {
        c = 'S';
    } else if (i == 1) {
        c = 'Z';
    } else if (i == 2 || i == 3) {
        c = 'O';
    } else if (i == 4 || i == 5) {
        c = 'J';
    } else if (i == 6 || i == 7) {
        c = 'L';
    } else if (i == 8 || i == 9) {
        c = 'I';
    } else if (i == 10 || i == 11) {
        c = 'T';
    } 
    auto b = component->produceBlock(c);
    component->clearNextDisplay();
    b->initBlock(0, 21);
}
