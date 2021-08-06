#include "jblock.h"
using namespace std;

jblock::jblock(abc_board *b, int level, char type) : Block{b, level, type} {}

bool jblock::initBlock(int x, int y) {
    p_array.emplace_back(make_pair(x, y - 1));
    p_array.emplace_back(make_pair(x, y));
    p_array.emplace_back(make_pair(x + 1, y));
    p_array.emplace_back(make_pair(x + 2, y));
    p = make_pair(x, y);
    
    valid = checkValidMove();
    if (valid) {
        setTrue();
        //p = make_pair(x, y);
        return true;
    }
    return false;
}


/*void jblock::initNextBlock() {
    int x = 0;
    int y = 20;
    p_array.emplace_back(make_pair(x, y - 1));
    p_array.emplace_back(make_pair(x, y));
    p_array.emplace_back(make_pair(x + 1, y));
    p_array.emplace_back(make_pair(x + 2, y));
    setTrue();
}*/


bool jblock::pOccupied() {
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

char jblock::judgeGraph() {
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

void jblock::moveClockwise() {
    char now = judgeGraph();
    if (now == '1') {
        --p_array.at(2).first;
        p_array.at(2).second -= 2;
        --p_array.at(3).first;
        p_array.at(3).second -= 2;
    } else if (now == '2') {
        ++p_array.at(1).first;
        --p_array.at(1).second;
        p_array.at(2).first += 2;
        ++p_array.at(2).second;
        ++p_array.at(3).first;
        p_array.at(3).second += 2;
    } else if (now == '3') {
        ++p_array.at(0).second;
        --p_array.at(2).first;
        --p_array.at(2).second;
        --p_array.at(3).first;
    } else if (now == '4') {
        --p_array.at(0).second;
        --p_array.at(1).first;
        ++p_array.at(1).second;
        p_array.at(2).second += 2;
        ++p_array.at(3).first;
    }
}

void jblock::moveCounterClockwise() {
    char now = judgeGraph();
    if (now == '2') {
        ++p_array.at(2).first;
        p_array.at(2).second += 2;
        ++p_array.at(3).first;
        p_array.at(3).second += 2;
    } else if (now == '3') {
        --p_array.at(1).first;
        ++p_array.at(1).second;
        p_array.at(2).first -= 2;
        --p_array.at(2).second;
        --p_array.at(3).first;
        p_array.at(3).second -= 2;
    } else if (now == '4') {
        --p_array.at(0).second;
        ++p_array.at(2).first;
        ++p_array.at(2).second;
        ++p_array.at(3).first;
    } else if (now == '1') {
        ++p_array.at(0).second;
        ++p_array.at(1).first;
        --p_array.at(1).second;
        p_array.at(2).second -= 2;
        --p_array.at(3).first;
    }
}

void jblock::clockwise() {
    setFalse();
    moveClockwise();
    valid = checkValidMove();
    if (valid == false) {
        moveCounterClockwise();
        valid = true;
    }
    setTrue();
}

void jblock::counterclockwise() {
    setFalse();
    moveCounterClockwise();
    valid = checkValidMove();
    if (valid == false) {
        moveClockwise();
        valid = true;
    }
    setTrue();
}
