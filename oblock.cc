#include "oblock.h"
using namespace std;

oblock::oblock(Board *b, int level, char type) : Block{b, level, type} {}

bool oblock::initBlock(int x, int y) {
    // x = 0; y = 3
    p_array.emplace_back(make_pair(x, y));
    p_array.emplace_back(make_pair(x + 1, y));
    p_array.emplace_back(make_pair(x + 1, y - 1));
    p_array.emplace_back(make_pair(x, y - 1));
    p = make_pair(x, y);
    /*p_array.emplace_back(make_pair(0, 3));
    p_array.emplace_back(make_pair(1, 3));
    p_array.emplace_back(make_pair(1, 2));
    p_array.emplace_back(make_pair(0, 2));*/

    valid = checkValidMove();
    if (valid) {
        setTrue();
        //p = make_pair(x, y);
        return true;
    }
    return false;
}

/*void oblock::initNextBlock() {
    int x = 0;
    int y = 20;
    p_array.emplace_back(make_pair(x, y));
    p_array.emplace_back(make_pair(x + 1, y));
    p_array.emplace_back(make_pair(x + 1, y - 1));
    p_array.emplace_back(make_pair(x, y - 1));
    setTrue();
}*/

void oblock::clockwise() {}

void oblock::counterclockwise() {}
