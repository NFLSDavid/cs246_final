#include "level1.h"
#include <cstdlib>
#include <iostream>
Level1::Level1(abc_board *c) : Level{c} {}

int Level1::getLevel() const {
    return 1;
}

bool Level1::newBlock() {
    char c = getNextType();
    auto b = produceBlock(c);
    pushActiveBlocks(b);
    bool successful = b->initBlock(0, 3);
    setNextType();
    return successful;
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

void Level1::judge(int) {}
