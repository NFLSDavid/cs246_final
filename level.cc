#include "level.h"

Level::Level(abc_board *c): component{c} {}

void Level::curCC() {
    component->curCC();
}

void Level::curC() {
    component->curC();
}

void Level::curLeft() {
    component->curLeft();
}

void Level::curRight() {
    component->curRight();
}

void Level::curDown() {
    component->curDown();
}


void Level::curDrop() {
    component->curDrop();
}


void Level::initAllCells() {
    component->initAllCells();
}

void Level::newBlock() {
    component->newBlock();
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

 void Level::update() {
     component->update();
 }

 std::shared_ptr<Block> Level::produceBlock(char c) {
     component->produceBlock(c);
 }
