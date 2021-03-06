#include "iblock.h"
using namespace std;

iblock::iblock(abc_board *b, int level, char type) : Block{b, level, type} {}

bool iblock::initBlock(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        p_array.emplace_back(make_pair(x, y));
        x++;
    }
    x -= 4;
    p = make_pair(x, y);
   
    valid = checkValidMove();
    if (valid) {
        setTrue();
        //p = make_pair(x, y);
        return true;
    }
    return false;
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
            p_array.at(i).second = y0 - i;
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
