#include "board.h"
#include "cell.h"
using namespace std;

void Board::initAllCells() {
    for (int i = 0; i < 18; ++i) {
        vector<shared_ptr<Cell>> row;
        for (int j = 0; j < 11; ++j) {
            auto c = make_shared<Cell>(j, i, ' ');
            //Cell *c = new Cell{j, i, ' '};
            row.push_back(c);
        }
        cells.push_back(row);
    }
}

Board::~Board() {}

void Board::restart() {
    active_blocks.clear();
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 11; ++j) {
            cells.at(i).at(j).get()->turnOff();
        }
    }
}

// 
bool Board::checkfull(int row_num) {
    for (int i = 0; i < 11; ++i) {
        if (!cells.at(row_num).at(i).get()->getState()) {
            return false;
        }
    }
    return true;
}

void Board::clear() {
    int num = 0;
    for (int i = 0; i < 18; ++i) {
        if (checkfull(i)) {
            ++num;
            
        }
    }
}
