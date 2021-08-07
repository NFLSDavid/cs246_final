#include "level.h"
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

Level::Level(abc_board *c): component{c} {}

int Level::getHiScore() const {
    return component->getHiScore();
}

int Level::getCurrentScore() const {
    return component->getCurrentScore();
}

void Level::setCurrentScore(int s) {
    component->setCurrentScore(s);
}

void Level::setHiScore() {
    component->setHiScore();
}

vector <vector <shared_ptr<Cell>>> Level::getBoard() const {
    return component->getBoard();
}

void Level::setNext(char c) {
    component->setNext(c);
}

void Level::pushBackToGenerated(char c) {
    component->pushBackToGenerated(c);
}

void Level::popGenerated() {
    component->popGenerated();
}

void Level::pushActiveBlocks(shared_ptr<Block> b) {
    component->pushActiveBlocks(b);
}

char Level::getGeneratedFront() const {
    return component->getGeneratedFront();
}

char Level::getNextType() const {
    cout << "entered level's nexttype" << endl;
    return component->getNextType();
}

Block* Level::getCurrBlock() {
    return component->getCurrBlock();
}

void Level::heavyOne() {
    if (getCurrBlock()->getLevel() == 3 || getCurrBlock()->getLevel() == 4) {
        getCurrBlock()->down();
    }
}

bool Level::curRight() {
    getCurrBlock()->right();
    heavyOne();
    return true;
}

bool Level::curLeft() {
    getCurrBlock()->left();
    heavyOne();
    return true;
}

void Level::curDown() {
    getCurrBlock()->down();
    heavyOne();
}

void Level::curCC() {
    getCurrBlock()->counterclockwise();
    heavyOne();
}

void Level::curC() {
    getCurrBlock()->clockwise();
    heavyOne();
}

void Level::curDrop() {
    component->curDrop();
}

void Level::initAllCells() {
    component->initAllCells();
}

void Level::restart() {
    component->restart();
}

int Level::clear() {
    return component->clear();
}

void Level::printBoard() {
    component->printBoard();
}

shared_ptr<Block> Level::produceBlock(char c) {
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
    return b;
    /*cout << "Block is generated at Level: " << getLevel() << endl;
    return b;
    return component->produceBlock(c);
    cout << "pass through " << getLevel() << endl;*/
}

void Level::popCurrBlock() {
    component->popCurrBlock();
}

void Level::pushCurrBlock(shared_ptr<Block> b) {
    component->pushCurrBlock(b);
}

void Level::changeCurrBlock(char type) {
    component->changeCurrBlock(type);
}

void Level::printNextBlock(char c) {
    component->printNextBlock(c);
} 
    
void Level::print() {
    component->print();
}

void Level::initfs(string filename) {
    component->initfs(filename);
}

void Level::clearNextDisplay() {
    component->clearNextDisplay();
}
   
void Level::printLevelLine() {
    cout << "Level:" << setw(5) << getLevel();
}

void Level::printScoreLine() {
    cout << "Score:" << setw(5) << getCurrentScore();
    //component->printScoreLine();
}
    
void Level::printRows(int r) {
    component->printRows(r);
}

Level::~Level() {}
