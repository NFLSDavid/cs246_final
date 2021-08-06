#include "level2.h"
#include <cstdlib>

Level2::Level2(abc_board *c) : Level{c} {}

int Level2::getLevel() const {
    return 2;
}

bool Level2::newBlock() {
    char c = getNextType();
    auto b = produceBlock(c);
    pushActiveBlocks(b);
    bool successful = b->initBlock(0, 3);
    setNextType();
    return successful;
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
    auto b = produceBlock(c);
    clearNextDisplay();
    b->initBlock(0, 21);
    setNext(c);
}

void Level2::judge(int) {}
