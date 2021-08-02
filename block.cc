#include "block.h"
#include "board.h"
#include "cell.h"

using namespace std;

Block::Block(Board *b, char type): abc_block{b}, type{type} {
    valid = checkValidMove();   // we check if valid after we constructed the block, if false, game OVER
    if (valid) {
        int len = p_array.size();
        for (int i = 0; i < len; ++i) {
            int x = p_array.at(i).first;
            int y = p_array.at(i).second;
            this->b->cells.at(y).at(x).get()->setState(true);
            // this->b->cells.at(y).at(x)->setState(true);
        }
    }
    p = make_pair(0, 3);
}

void Block::setFalse() {
    int len = p_array.size();
    for (int i = 0; i < len; ++i) {
        int x = p_array.at(i).first;
        int y = p_array.at(i).second;
        this->b->cells.at(y).at(x).get()->setState(true);
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
    int len = p_array.size();
    for (int i = 0; i < len; ++i) {
        int x = p_array.at(i).first;
        int y = p_array.at(i).second;  
        Cell *c = this->b->cells.at(y).at(x).get();
        if (x < 0 || y < 0 || 
            x > 10 || y > 17) {  // whether fall out of the board
            return false;
        } else if (c->getState() == true) {  // whether it collides with other already occupied cells
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
        --p_array.at(i).first;
    }
}

void Block::moveUp() {
    int len = p_array.size();
    for (int i = 0; i < len; ++i) {
        --p_array.at(i).second;
    }
}

void Block::moveLeft() {
    int len = p_array.size();
    for (int i = 0; i < len; ++i) {
        ++p_array.at(i).second;
    }
}
////////////////////////////////////////////


void Block::left() {
    int len = p_array.size();
    setFalse();
    moveLeft();
    valid = checkValidMove();
    if (valid == false) {
        moveRight();
        valid = true;
    }
    setTrue();
}

void Block::right() {
    int len = p_array.size();
    setFalse();
    moveRight();
    valid = checkValidMove();
    if (valid == false) {
        moveLeft();
        valid = true;
    }
    setTrue();
}

void Block::up() {
    int len = p_array.size();
    setFalse();
    moveUp();
    valid = checkValidMove();
    if (valid == false) {
        moveDown();
        valid = true;
    }
    setTrue();
}

void Block::down() {
    int len = p_array.size();
    moveDown();
    valid = checkValidMove();
    if (valid == false) {
        moveUp();
        valid = true;
    } 
    setTrue();
}
