#include "block.h"
#include "board.h"
#include "cell.h"
#include <iostream>
using namespace std;

Block::~Block() {}

Block::Block(abc_board *b, int level, char type): b{b}, level{level}, activeNum{4}, type{type} {}

void Block::initNextBlock() {
    int len = p_array.size();
    for (int i = 0; i < len; ++i) {
        int x = p_array.at(i).first;
        int y = p_array.at(i).second;
        this->b->getBoard().at(y).at(x).get()->setType(type);
    }
}

int Block::getLevel() {
    return level;
}

void Block::drawBlock(Xwindow *w, int player) {
    for (int i = 0; i < p_array.size(); i++) {
        int x = p_array.at(i).first;
        int y = p_array.at(i).second;
        this->b->getBoard().at(y).at(x).get()->draw(w, player);
    }
}

void Block::undrawBlock(Xwindow *w, int player) {
    for (int i = 0; i < 4; i++) {
        int x = p_array.at(i).first;
        int y = p_array.at(i).second;
        this->b->getBoard().at(y).at(x).get()->draw(w, player);
    }
}

void Block::setFalse() {
    int len = p_array.size();
    for (int i = 0; i < len; ++i) {
        int x = p_array.at(i).first;
        int y = p_array.at(i).second;
        this->b->getBoard().at(y).at(x).get()->setState(false);
        this->b->getBoard().at(y).at(x).get()->setType(' ');
    }
}

void Block::setTrue() {
    int len = p_array.size();
    for (int i = 0; i < len; ++i) {
        int x = p_array.at(i).first;
        int y = p_array.at(i).second;
        this->b->getBoard().at(y).at(x).get()->setState(true);
        this->b->getBoard().at(y).at(x).get()->setType(type);
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

        Cell *c = this->b->getBoard().at(y).at(x).get();
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
    //cout << valid << endl;
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

bool Block::down() {
    bool s = true;
    setFalse();
    moveDown();
    valid = checkValidMove();
    if (valid == false) {
        moveUp();
        valid = true;
        s = false;
    } 
    setTrue();
    p.second += 1;
    return s;
}

shared_ptr<point> Block::getLeftCorner() {
    auto s = make_shared<point>(p.first, p.second);
    return s;
}



// return true if the block is fully cleared
bool Block::dropRow(int r) {
    int len = p_array.size();
    for (int i = 0; i < len; ++i) {
        point pi = p_array.at(i);
        if (r == pi.first) {
            --activeNum;           
            p_array.erase(p_array.begin() + i);
            if (activeNum == 0) {
                return false;
            }
        }
    }
    
    len = p_array.size();
    for (int j = 0; j < len; ++j) {
        point pj = p_array.at(j);
        if (pj.second < r) {
            ++p_array.at(j).second;
        }
    }
    return true;
}


