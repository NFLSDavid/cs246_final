#include "level.h"
#include <string>
using namespace std;

Level::Level(abc_board *c): component{c} {}

void Level::curRight() {
    component->getCurrBlock()->right();
}


void Level::curLeft() {
    component->getCurrBlock()->left();
}


void Level::curDown() {
    component->getCurrBlock()->down();
}


void Level::curCC() {
    component->getCurrBlock()->counterclockwise();
}


void Level::curC() {
    component->getCurrBlock()->clockwise();
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

void Level::clear() {
    component->clear();
}

void Level::printBoard() {
    component->printBoard();
}

shared_ptr<Block> Level::produceBlock(char c) {
    return component->produceBlock(c);
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

shared_ptr<Block> Level::produceBlock(char c){
    return component->produceBlock(c);
}

void Level::initfs(string filename) {
    component->initfs(filename);
}

void Level::clearNextDisplay() {
    component->clearNextDisplay();
}
   
void Level::printLevelLine() {
    component->printLevelLine();
}

void Level::printScoreLine() {
    component->printScoreLine();
}
    
void Level::printRows(int r) {
    component->printRows(r);
}

Level::~Level() {}
