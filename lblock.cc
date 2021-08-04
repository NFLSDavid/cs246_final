#include "lblock.h"
using namespace std;

lblock::lblock(Board *b, char type) : Block{b, type} {}

bool lblock::initBlock(int x, int y) {
    p_array.emplace_back(make_pair(x, y));
    p_array.emplace_back(make_pair(x + 1, y));
    p_array.emplace_back(make_pair(x + 2, y));
    p_array.emplace_back(make_pair(x + 2, y - 1));
    p = make_pair(x, y);
    valid = checkValidMove();
    if (valid) {
        setTrue();
        //p = make_pair(x, y);
        return true;
    }
    return false;
}


/*void lblock::initNextBlock() {
    int x = 0;
    int y = 20;
    p_array.emplace_back(make_pair(x, y));
    p_array.emplace_back(make_pair(x + 1, y));
    p_array.emplace_back(make_pair(x + 2, y));
    p_array.emplace_back(make_pair(x + 2, y - 1));
    setTrue();
}*/


bool lblock::pOccupied() {
    int len = p_array.size();
    int x0 = p.first + 1;
    int y0 = p.second - 1;
    for (int i = 0; i < len; ++i) {
        int x = p_array.at(i).first;
        int y = p_array.at(i).second;
        if (x0 == x && y0 == y) {
            return true;
        }
    }
    return false;
}

char lblock::judgeGraph() {
    int len = p_array.size();
    int x0 = p.first;
    int y0 = p.second;
    if (pOccupied()) {
        for (int i = 0; i < len; ++i) {
            int x = p_array.at(i).first;
            int y = p_array.at(i).second;
            if (x == x0 && y == y0 - 1) {
                return '3';
            }
        }
        return '4';
    } else {
        for (int i = 0; i < len; ++i) {
            int x = p_array.at(i).first;
            int y = p_array.at(i).second;
            if (x == x0 && y == y0 - 2) {
                return '2';
            }
        }
        return '1';
    }
}

void lblock::moveClockwise() {
    char now = judgeGraph();
    if (now == '1') {
        p_array.at(2).first -= 2;
        --p_array.at(2).second;
        p_array.at(3).first -= 2;
        --p_array.at(3).second;
    } else if (now == '2') {
        --p_array.at(1).second;
        p_array.at(3).first += 2;
        ++p_array.at(3).second;
    } else if (now == '3') {
        ++p_array.at(0).first;
        --p_array.at(2).second;
        --p_array.at(3).first;
        --p_array.at(3).second;
    } else if (now == '4') {
        --p_array.at(0).first;
        ++p_array.at(1).second;
        p_array.at(2).first += 2;
        p_array.at(2).second += 2;
        ++p_array.at(3).first;
        ++p_array.at(3).second;
    }
}

void lblock::moveCounterClockwise() {
    char now = judgeGraph();
    if (now == '2') {
        p_array.at(2).first += 2;
        ++p_array.at(2).second;
        p_array.at(3).first += 2;
        ++p_array.at(3).second;
    } else if (now == '3') {
        ++p_array.at(1).second;
        p_array.at(3).first -= 2;
        --p_array.at(3).second;
    } else if (now == '4') {
        --p_array.at(0).first;
        ++p_array.at(2).second;
        ++p_array.at(3).first;
        ++p_array.at(3).second;
    } else if (now == '1') {
        ++p_array.at(0).first;
        --p_array.at(1).second;
        p_array.at(2).first -= 2;
        p_array.at(2).second -= 2;
        --p_array.at(3).first;
        --p_array.at(3).second;
    }
}

void lblock::clockwise() {
    setFalse();
    moveClockwise();
    valid = checkValidMove();
    if (valid == false) {
        moveCounterClockwise();
        valid = true;
    }
    setTrue();
}

void lblock::counterclockwise() {
    setFalse();
    moveCounterClockwise();
    valid = checkValidMove();
    if (valid == false) {
        moveClockwise();
        valid = true;
    }
    setTrue();
}
