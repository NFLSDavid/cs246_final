#include "zblock.h"
using namespace std;

zblock::zblock(Board *b, char type) : Block{b, type} {}

bool zblock::initBlock() {
    p_array.emplace_back(make_pair(0, 2));
    p_array.emplace_back(make_pair(1, 2));
    p_array.emplace_back(make_pair(1, 3));
    p_array.emplace_back(make_pair(2, 3));

    valid = checkValidMove();
    if (valid) {
        setTrue();
        p = make_pair(0, 3);
        return true;
    }
    return false;
}

bool zblock::judgeGraph() {
    int len = p_array.size();
    int x0 = p.first;
    int y0 = p.second;
    for (int i = 0; i < len; ++i) {
        int x = p_array.at(i).first;
        int y = p_array.at(i).second;
        if (x0 == x && y0 == y) {
            return false;
        }
    }
    return true;
}

void zblock::moveClockwise() {
    if (judgeGraph()) { // vertical
        ++p_array.at(2).first;
        ++p_array.at(3).first;
        p_array.at(3).second += 2;
    } else { // horizontal
        --p_array.at(2).first;
        --p_array.at(3).first;
        p_array.at(3).second -= 2;
    }
}


void zblock::clockwise() {
    setFalse();
    moveClockwise();
    valid = checkValidMove();
    if (valid == false) {
        moveClockwise();
        valid = true;
    }
    setTrue();
}

void zblock::counterclockwise() {
    clockwise();
}
