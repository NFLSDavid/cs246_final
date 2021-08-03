#include "szblock.h"
using namespace std;

szblock::szblock(Board *b, char type) : Block{b, type} {}

bool szblock::initBlock() {
    if (type == 'z') {
        p_array.emplace_back(make_pair(0, 2));
        p_array.emplace_back(make_pair(1, 2));
        p_array.emplace_back(make_pair(1, 3));
        p_array.emplace_back(make_pair(2, 3));
    } else {
        p_array.emplace_back(make_pair(1, 2));
        p_array.emplace_back(make_pair(1, 3));
        p_array.emplace_back(make_pair(0, 3));
        p_array.emplace_back(make_pair(2, 2));
    }
    

    valid = checkValidMove();
    if (valid) {
        setTrue();
        p = make_pair(0, 3);
        return true;
    }
    return false;
}


bool szblock::judgeGraph() {
    int len = p_array.size();
    int x0 = p.first;
    int y0 = p.second;
    for (int i = 0; i < len; ++i) {
        int x = p_array.at(i).first;
        int y = p_array.at(i).second;
        if (x0 == x && y0 == y) {
            return false; // when z vertical
        }
    }
    return true;
}


void szblock::moveClockwise() {
    /*if (!judgeGraph()) { // vertical
        ++p_array.at(2).first;
        ++p_array.at(3).first;
        p_array.at(3).second += 2;
    } else { // horizontal
        --p_array.at(2).first;
        --p_array.at(3).first;
        p_array.at(3).second -= 2;
    }*/

    // modified  
    if ((!judgeGraph() && type == 'z') || (judgeGraph() && type == 's')) { // z vertical/ s horizontal
        p_array.at(2).second += 2;
        p_array.at(3).first += 2;
    } else if ((!judgeGraph() && type == 's') || (judgeGraph() && type == 'z')){ // horizontal
        p_array.at(2).second -= 2;
        p_array.at(3).first -= 2;
    }
    
}


void szblock::clockwise() {
    setFalse();
    moveClockwise();
    valid = checkValidMove();
    if (valid == false) {
        moveClockwise();
        valid = true;
    }
    setTrue();
}

void szblock::counterclockwise() {
    clockwise();
}
