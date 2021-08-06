#include "level3.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>

Level3::Level3(abc_board *c) : Level{c} {}

int Level3::getLevel() const {
    return 3;
}

void Level3::init3(string name) {
    filename3 = name;
    random = false;
    ifstream infile{name};
    char blockType;
    while (true) {
        infile >> blockType;
        toBeGenerated3.push(blockType);
        if (infile.fail()) {
            break;
        }
    }
}

bool Level3::newBlock() {
    shared_ptr<Block> b;
    if (random) {
        char c = getNextType();
        b = produceBlock(c);
    } else {
        toBeGenerated3.push(getNextType());
        b = produceBlock(getNextType());
    }
    pushActiveBlocks(b);
    bool successful = b->initBlock(0, 3);
    setNextType();
    return successful;
}

void Level3::setNextType() {
    char c;
    if (random) {
        int i = rand() % 9;
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
    } else {
        c = toBeGenerated3.front();
        toBeGenerated3.pop();
    }
    auto b = produceBlock(c);
    clearNextDisplay();
    b->initBlock(0, 21);
    setNext(c);
}

void Level3::judge(int) {}

