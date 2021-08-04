#include "tblock.h"
using namespace std;

tblock::tblock(Board *b, char type) : Block{b, type} {}

bool tblock::initBlock(int x, int y) {
    /*p_array.emplace_back(make_pair(1, 2));
    p_array.emplace_back(make_pair(0, 2));
    p_array.emplace_back(make_pair(1, 3));
    p_array.emplace_back(make_pair(2, 2));*/
    // x = 0; y = 3
    p = make_pair(x, y);
    p_array.emplace_back(make_pair(x + 1, y - 1));
    p_array.emplace_back(make_pair(x, y - 1));
    p_array.emplace_back(make_pair(x + 1, y));
    p_array.emplace_back(make_pair(x + 2, y - 1));
    valid = checkValidMove();
    if (valid) {
        setTrue();
        //p = make_pair(x, y);
        return true;
    }
    return false;
}

bool tblock::pOccupied() {
    int len = p_array.size();
    int x0 = p.first;
    int y0 = p.second;
    for (int i = 0; i < len; ++i) {
        int x = p_array.at(i).first;
        int y = p_array.at(i).second;
        if (x0 == x && y0 == y) {
            return true;
        }
    }
    return false;
}

char tblock::judgeGraph() {
    int len = p_array.size();
    int x0 = p.first;
    int y0 = p.second;
    if (pOccupied()) {
        for (int i = 0; i < len; ++i) {
            int x = p_array.at(i).first;
            int y = p_array.at(i).second;
            if (x == x0 && y == y0 - 1) {
                return '4';
            }
        }
        return '3';
    } else {
        for (int i = 0; i < len; ++i) {
            int x = p_array.at(i).first;
            int y = p_array.at(i).second;
            if (x == x0 + 1 && y == y0 - 2) {
                return '2';
            }
        }
        return '1';
    }
}

void tblock::moveClockwise() {
    char now = judgeGraph();
    if (now == '1') {
        --p_array.at(3).first;
        --p_array.at(3).second;
    } else if (now == '2') {
        ++p_array.at(1).second;
        ++p_array.at(3).first;
        p_array.at(3).second += 2;
    } else if (now == '3') {
        --p_array.at(2).first;
        --p_array.at(2).second;
        p_array.at(3).first -= 2;
        p_array.at(3).second -= 2;
    } else if (now == '4') {
        ++p_array.at(2).first;
        ++p_array.at(2).second;
        p_array.at(3).first += 2;
        ++p_array.at(3).second;
        --p_array.at(1).second;
    }
}

void tblock::moveCounterClockwise() {
    char now = judgeGraph();
    if (now == '2') {
        ++p_array.at(3).first;
        ++p_array.at(3).second;
    } else if (now == '3') {
        --p_array.at(1).second;
        --p_array.at(3).first;
        p_array.at(3).second -= 2;
    } else if (now == '4') {
        ++p_array.at(2).first;
        ++p_array.at(2).second;
        p_array.at(3).first += 2;
        p_array.at(3).second += 2;
    } else if (now == '1') {
        --p_array.at(2).first;
        --p_array.at(2).second;
        p_array.at(3).first -= 2;
        --p_array.at(3).second;
        ++p_array.at(1).second;
    }
}

void tblock::clockwise() {
    setFalse();
    moveClockwise();
    valid = checkValidMove();
    if (valid == false) {
        moveCounterClockwise();
        valid = true;
    }
    setTrue();
}

void tblock::counterclockwise() {
    setFalse();
    moveCounterClockwise();
    valid = checkValidMove();
    if (valid == false) {
        moveClockwise();
        valid = true;
    }
    setTrue();
}
