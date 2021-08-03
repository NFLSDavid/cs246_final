#include "iblock.h"
using namespace std;

iblock::iblock(Board *b, char type) : Block{b, type} {
    for (int i = 0; i < 4; ++i) {
        p_array.emplace_back(make_pair(i, 3));
    }
}

bool iblock::initBlock() {
    for (int i = 0; i < 4; ++i) {
        p_array.emplace_back(make_pair(i, 3));
    }
    valid = checkValidMove();
    if (valid) {
        setTrue();
        p = make_pair(0,3);
    }
}

void iblock::moveClockwise() {
    int len = p_array.size();
    int x0 = p_array.at(0).first;
    int y0 = p_array.at(0).second;

    if (x0 == p_array.at(1).first) {  // check if vertical
        for (int i = 0; i < len; ++i) {
            p_array.at(i).first = x0 + i;
            p_array.at(i).second = y0;
        }
    } else {
        for (int i = 0; i < len; ++i) {
            p_array.at(i).first = x0;
            p_array.at(i).second = y0 + i;
        }
    }
}


void iblock::clockwise() {
    setFalse();
    moveClockwise();
    valid = checkValidMove();
    if (valid == false) {
        moveClockwise();
        valid = true;
    }
    setTrue();
}

void iblock::counterclockwise() {
    clockwise();
}
