#include "block.h"
#include "board.h"
#include "cell.h"
#include <iostream>
using namespace std;

Block::~Block() {}

Block::Block(Board *b, char type): b{b}, type{type} {
    /*valid = checkValidMove();   // we check if valid after we constructed the block, if false, game OVER
    if (valid) {
        int len = p_array.size();
        for (int i = 0; i < len; ++i) {
            int x = p_array.at(i).first;
            int y = p_array.at(i).second;
            this->b->cells.at(y).at(x).get()->setState(true);
            // this->b->cells.at(y).at(x)->setState(true);
        }
    }*/
    //p = make_pair(0, 3); 
}

void Block::initNextBlock() {
    int len = p_array.size();
    for (int i = 0; i < len; ++i) {
        int x = p_array.at(i).first;
        int y = p_array.at(i).second;
        this->b->cells.at(y).at(x).get()->setType(type);
    }
}

void Block::setFalse() {
    int len = p_array.size();
    for (int i = 0; i < len; ++i) {
        int x = p_array.at(i).first;
        int y = p_array.at(i).second;
        this->b->cells.at(y).at(x).get()->setState(false);
        this->b->cells.at(y).at(x).get()->setType(' ');
    }
}

void Block::setTrue() {
    int len = p_array.size();
    for (int i = 0; i < len; ++i) {
        int x = p_array.at(i).first;
        int y = p_array.at(i).second;
        this->b->cells.at(y).at(x).get()->setState(true);
        this->b->cells.at(y).at(x).get()->setType(type);
    }
}

// point(x, y) -> x,y 为坐标的x,y
// cells[i][j] -> i = y, j = x
bool Block::checkValidMove() {

    if (p.second == 21) {
        return true;
    }
    int len = p_array.size();
    for (int i = 0; i < len; ++i) {
        int x = p_array.at(i).first;
        int y = p_array.at(i).second;  

        
        if (x < 0 || y < 0 || 
            x > 10 || y > 17) {  // whether fall out of the board
            return false;
        }

        Cell *c = this->b->cells.at(y).at(x).get();
        if (c->getState() == true) {  // whether it collides with other already occupied cells
            return false;
        }
    }
    return true;
}

// helpers //////////////////////
void Block::moveLeft() {
    int len = p_array.size();
    for (int i = 0; i < len; ++i) {
        --p_array.at(i).first;
    }
}

void Block::moveRight() {
    int len = p_array.size();
    for (int i = 0; i < len; ++i) {
        ++p_array.at(i).first;
    }
}

void Block::moveUp() {
    int len = p_array.size();
    for (int i = 0; i < len; ++i) {
        --p_array.at(i).second;
    }
}

void Block::moveDown() {
    int len = p_array.size();
    for (int i = 0; i < len; ++i) {
        ++p_array.at(i).second;
    }
}
////////////////////////////////////////////


void Block::left() {
    setFalse();
    moveLeft();
    valid = checkValidMove();
    if (valid == false) {
        moveRight();
        valid = true;
    }
    setTrue();

    // newly added
    p.first -= 1;
}


void Block::right() {
    setFalse();
    moveRight();
    valid = checkValidMove();
    cout << valid << endl;
    if (valid == false) {
        moveLeft();
        valid = true;
    }
    setTrue();
    p.first += 1;
}

void Block::drop() {
    setFalse();
    while (valid) {  // valid刚开始都是true的
        moveDown();
        valid = checkValidMove();
    }
    moveUp();
    setTrue();
    valid = true;
}

void Block::down() {
    setFalse();
    moveDown();
    valid = checkValidMove();
    if (valid == false) {
        moveUp();
        valid = true;
    } 
    setTrue();
    p.second += 1;
}

shared_ptr<point> Block::getLeftCorner() {
    auto s = make_shared<point>(p.first, p.second);
    return s;
}
