#include "level4.h"
#include <cstdlib>

void Level4::newBlock() {
    char c = component->getNextType();
    auto b = produceBlock(c);
    component->pushActiveBlocks(b);
    b->initBlock(0, 3);
    setNextType();
}

void Level4::setNextType() {
    int i = rand() % 9;
    char c;
    if (i == 0 || i == 1) {
        c = 'S';
    } else if (i ==  2 || i == 3) {
        c = 'Z';
    } else if (i == 4) {
        c = 'O';
    } else if (i == 5) {
        c = 'J';
    } else if (i == 6) {
        c = 'L';
    } else if (i == 7) {
        c = 'I';
    } else if (i == 8) {
        c = 'T';
    } 
    auto b = component->produceBlock(c);
    component->clearNextDisplay();
    b->initBlock(0, 21);
}


void Level4::curRight() {
    component->getCurrBlock()->right();
    component->getCurrBlock()->down();
}


void Level4::curLeft() {
    component->getCurrBlock()->left();
    component->getCurrBlock()->down();
}


void Level4::curDown() {
    component->getCurrBlock()->down();
    component->getCurrBlock()->down();
}


void Level4::curCC() {
    component->getCurrBlock()->counterclockwise();
    component->getCurrBlock()->down();
}


void Level4::curC() {
    component->getCurrBlock()->clockwise();
    component->getCurrBlock()->down();
}
