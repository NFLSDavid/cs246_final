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

Board::Board(string filename) : filename{filename}, level{0}, currentScore{0} {
    std::ifstream infile{filename};
    char blockType;
    while ( true ) {
        infile >> blockType;
        toBeGenerated.push(blockType);
        if (infile.fail()) break;
    }

}

Board::~Board() {}

/*vector<shared_ptr<Block>> Board::getActiveBlocks() const {
    return active_blocks;
}*/

void Board::judge(int) {}

int Board::getHiScore() const {
    return hiScore;
}

int Board::getCurrentScore() const {
    return currentScore;
}

void Board::setHiScore() {
    if (currentScore > hiScore) {
        hiScore = currentScore;
    }
}

void Board::setCurrentScore(int s) {
    currentScore = s;
}

vector <vector <shared_ptr<Cell>>> Board::getBoard() const {
    return cells;
}

char Board::getGeneratedFront() const {
    return toBeGenerated.front();
}

void Board::pushActiveBlocks(shared_ptr<Block> b) {
    active_blocks.push_back(b);
} 

void Board::pushBackToGenerated(char c) {
    toBeGenerated.push(c);
}  

void Board::popGenerated() {
    toBeGenerated.pop();
} 

void Board::setNext(char c) {
    nextBlockType = c;
} 

char Board::getNextType() const {
    return nextBlockType;
}

int Board::getLevel() const {
    return 0;
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

Block* Board::getCurrBlock() {
    return active_blocks[active_blocks.size() - 1].get();
}

void Board::popCurrBlock() {
    active_blocks.pop_back();
}

void Board::pushCurrBlock(shared_ptr<Block> b) {
    active_blocks.push_back(b);
}


void Board::changeCurrBlock(char type) {
    Block *curr = getCurrBlock();
    curr->setFalse();  // currBlock setFalse(disappear)

    auto i = produceBlock(type);
    cout << curr->getLeftCorner()->first << " " << curr->getLeftCorner()->second << endl;
    bool initStat = i->initBlock(curr->getLeftCorner()->first, curr->getLeftCorner()->second);
    if (!initStat) {  // if we failed to init this new block
        curr->setTrue();
    }  else {
        popCurrBlock();
        pushCurrBlock(i);
        //pop the original current block out
        //push the new block in instead
    }
}

shared_ptr<Block> Board::produceBlock(char c) {
    shared_ptr<Block> b;
    if (c == 'Z' || c == 'S') {
        b = make_shared<szblock>(this, getLevel(), c);
    } else if (c == 'I') {
        b = make_shared<iblock>(this, getLevel(), c);
    } else if (c == 'J') {
        b = make_shared<jblock>(this, getLevel(), c);
    } else if (c == 'L') {
        b = make_shared<lblock>(this, getLevel(), c);
    } else if (c == 'O') {
        b = make_shared<oblock>(this, getLevel(), c);
    }  else {
        b = make_shared<tblock>(this, getLevel(), c);
    }
    cout << "Block is generated at Level: " << getLevel() << endl;
    return b;
}

/*void Board::newBlock() {
    char blockType = toBeGenerated.front();
    toBeGenerated.pop();
    toBeGenerated.push(blockType);
    auto b = produceBlock(blockType);
    active_blocks.push_back(b);
    b->initBlock(0, 3);
}*/

void Board::clearNextDisplay() {
    int rows = cells.size();
    int cols = cells.at(0).size();
    for (int i = 20; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cells.at(i).at(j).get()->setType(' ');
        }
    }
}

void Board::setNextType() {
    nextBlockType = toBeGenerated.front();
    toBeGenerated.pop();
    auto b = produceBlock(nextBlockType);
    //active_blocks.push_back(b);
    clearNextDisplay();
    b->initBlock(0, 21);
}

bool Board::newBlock() {
    toBeGenerated.push(nextBlockType);
    auto b = produceBlock(nextBlockType);
    bool successful = b->initBlock(0, 3);
    if (successful) {
        active_blocks.push_back(b);
        setNextType();
    } 
    
    return successful;
}


/*void Board::nextBlock() {
    char blockType = toBeGenerated.front();
    nextBlock = produceBlock(blockType);
    //nextBlock = b;
}*/

void Board::restart() {
    active_blocks.clear();
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 11; ++j) {
            cells.at(i).at(j).get()->turnOff();
        }
    }

    setHiScore();
    currentScore = 0;
}

void Board::printNextBlock(char c) {
    int rows  = cells.size();
    int cols = cells.at(0).size();
    
    for (int i = 20; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << cells.at(i).at(j).get()->getType();
        }
        cout << endl;
    }
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

void Board::print() {}


/////////////////////////////////////////////////
bool Board::checkfull(int row_num) {
    for (int i = 0; i < 11; ++i) {
        if (!cells.at(row_num).at(i).get()->getState()) {
            return false;
        }
    }
    return true;
}


/*
when a line (or multiple lines) is cleared, you score points equal to (your current level, plus
number of lines) squared. (For example, clearing a line in level 2 is worth 9 points.) 

In addition, when a block is completely
removed from the screen (i.e., when all of its cells have disappeared) you score points equal to the level you were in when the
block was generated, plus one, squared. (For example if you got an O-block while on level 0, and cleared the O-block in level
3, you get 1 point.)
*/

/*int Board::getLinesCleared() {
    int numLines = 0;
    for (int i = 0; i < 18; ++i) {
        if (checkfull(i)) {
            ++numLines; // how many rows you have cleared
        }
    }
    return numLines;
}*/



// update linesCleared
int Board::clear() {
    vector <int> fullRows;
    int numLines = 0;
    for (int i = 0; i < 18; ++i) {
        if (checkfull(i)) {
            ++numLines; // how many rows you have cleared
            fullRows.emplace_back(i);
        }
    }
    if (numLines == 0) {
        return 0;
    }
    currentScore += (getLevel() + numLines) * (getLevel() + numLines);
    int len1 = fullRows.size();  // 可以消掉的rows （16， 17）
    int len2 = active_blocks.size();

    for (int i = 0; i < len1; i++) {
        int rowNum = fullRows.at(i);

        for (int j = rowNum; j > 0; --j) {
            for (int k = 0; k < 11; ++k) {
                char upType = cells.at(j - 1).at(k)->getType();
                char upOccupied = cells.at(j - 1).at(k)->getState();
                cells.at(j).at(k)->setType(upType);
                cells.at(j).at(k)->setState(upOccupied);
            }
        }

        for (int t = 0; t < len2; ++t) {
            if (!active_blocks.at(t)->dropRow(rowNum)) {
                currentScore += (active_blocks.at(t)->getLevel() + 1) * (active_blocks.at(t)->getLevel() + 1);
                active_blocks.erase(active_blocks.begin() + t);
            }
        }
        for (int k = 0; k < 11; ++k) {
            cells.at(0).at(k).get()->setState(false);
            cells.at(0).at(k).get()->setType(' ');
        }
    }

    return numLines;
}






void Board::initfs(string filename) {}

void Board::printLevelLine() {
    cout << "Level:" << setw(5) << getLevel();
}

void Board::printScoreLine() {
    cout << "Score:" << setw(5) << currentScore;
}

void Board::printRows(int i) {
    for (int j = 0; j < 11; j++) {
        cout << cells.at(i).at(j).get()->getType();
    }
}

void Board::printBoard() {
    //int rows  = cells.size();
    //int cols = cells.at(0).size();
    cout << "Level:" << setw(5) << level << endl;
    cout << "Score:" << setw(5) << currentScore << endl;
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

    printNextBlock('Z'); // not right

}
