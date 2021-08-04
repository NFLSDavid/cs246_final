#include "board.h"
#include "cell.h"
#include "szblock.h"
#include "iblock.h"
#include "tblock.h"
#include "oblock.h"
#include "jblock.h"
#include "lblock.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

Board::Board(string filename) : filename{filename}, level{0}, score{0} {
    std::ifstream infile{"biquadris_sequence1.txt"};
    char blockType;
    while ( true ) {
        infile >> blockType;
        toBeGenerated.push(blockType);
        if ( infile.fail() ) break;
    }

}

void Board::initAllCells() {
    for (int i = 0; i < 18 + 4; i++) {  // reserve 4 for the next
        vector<shared_ptr<Cell>> row;
        for (int j = 0; j < 11; j++) {
            auto c = make_shared<Cell>(j, i, ' ');
            row.push_back(c);
        }
        cells.push_back(row);
    }
}

shared_ptr<Block> Board::produceBlock(char c) {
    shared_ptr<Block> b;
    if (c == 'Z' || c == 'S') {
        b = make_shared<szblock>(this, c);
    } else if (c == 'I') {
        b = make_shared<iblock>(this, c);
    } else if (c == 'J') {
        b = make_shared<jblock>(this, c);
    } else if (c == 'L') {
        b = make_shared<lblock>(this, c);
    } else if (c == 'O') {
        b = make_shared<oblock>(this, c);
    }  else {
        b = make_shared<tblock>(this, c);
    }
    return b;
}

void Board::newBlock() {
    char blockType = toBeGenerated.front();
    toBeGenerated.pop();
    toBeGenerated.push(blockType);
    auto b = produceBlock(blockType);
    active_blocks.push_back(b);
    b->initBlock(0, 3);
}

/*void Board::nextBlock() {
    char blockType = toBeGenerated.front();
    nextBlock = produceBlock(blockType);
    //nextBlock = b;

}*/



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

void Board::printBoard() {
    int rows  = cells.size();
    int cols = cells.at(0).size();
    cout << "Level:" << setw(5) << level << endl;
    cout << "Score:" << setw(5) << score << endl;
    for (int i = 0; i < 11; i++) {
        cout << '_';
    }
    cout << endl;

    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 11; j++) {
            cout << cells.at(i).at(j).get()->getType();
        }
        cout << endl;
    }

    for (int i = 0; i < 11; i++) {
        cout << '_';
    }
    cout << endl;
    cout << "Next:" << endl;

    auto b = produceBlock(toBeGenerated.front());
    b->initBlock(0, 21);
    for (int i = 20; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << cells.at(i).at(j).get()->getType();
        }
        cout << endl;
    }
    b->setFalse();

}

 void Board::update() {
     newBlock();
     printBoard();
 }

void Board::curRight() {
    active_blocks.back()->right();
}

void Board::curLeft()  {
    active_blocks.back()->left();
}

void Board::curDown() {
    active_blocks.back()->down();
}

void Board::curCC() {
    active_blocks.back()->counterclockwise();
}

void Board::curC() {
    active_blocks.back()->clockwise();
}

void Board::curDrop() {
    active_blocks.back()->drop();
}