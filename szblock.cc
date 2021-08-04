#include "szblock.h"
using namespace std;

szblock::szblock(Board *b, char type) : Block{b, type} {}

bool szblock::initBlock(int x, int y) {
    // x = 0, y = 3
    p = make_pair(x, y);
    if (type == 'Z') {
        p_array.emplace_back(make_pair(x, y-1));
        p_array.emplace_back(make_pair(x+1, y-1));
        p_array.emplace_back(make_pair(x+1, y));
        p_array.emplace_back(make_pair(x+2, y));
    } else {
        p_array.emplace_back(make_pair(x+1, y-1));
        p_array.emplace_back(make_pair(x+1, y));
        p_array.emplace_back(make_pair(x, y));
        p_array.emplace_back(make_pair(x+2, y-1));
    }
    

    valid = checkValidMove();
    if (valid) {
        setTrue();
        //p = make_pair(x, y);
        return true;
    }
    return false;
}


/*void szblock::initNextBlock() {
    int x = 0;
    int y = 20;
    if (type == 'Z') {
        p_array.emplace_back(make_pair(x, y-1));
        p_array.emplace_back(make_pair(x+1, y-1));
        p_array.emplace_back(make_pair(x+1, y));
        p_array.emplace_back(make_pair(x+2, y));
    } else {
        p_array.emplace_back(make_pair(x+1, y-1));
        p_array.emplace_back(make_pair(x+1, y));
        p_array.emplace_back(make_pair(x, y));
        p_array.emplace_back(make_pair(x+2, y-1));
    }
    setTrue();
}*/


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

    // modified  
    if ((!judgeGraph() && type == 'Z') || (judgeGraph() && type == 'S')) { // z vertical/ s horizontal
        p_array.at(2).second += 2;
        p_array.at(3).first += 2;
    } else if ((!judgeGraph() && type == 'S') || (judgeGraph() && type == 'Z')){ // horizontal
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
