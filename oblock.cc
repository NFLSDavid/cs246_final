#include "oblock.h"
using namespace std;

oblock::oblock(Board *b, char type) : Block{b, type} {}

bool oblock::initBlock() {
    p_array.emplace_back(make_pair(0, 3));
    p_array.emplace_back(make_pair(1, 3));
    p_array.emplace_back(make_pair(1, 2));
    p_array.emplace_back(make_pair(0, 2));

    valid = checkValidMove();
    if (valid) {
        setTrue();
        p = make_pair(0, 3);
        return true;
    }
    return false;
}

void oblock::clockwise() {}

void oblock::counterclockwise() {}
