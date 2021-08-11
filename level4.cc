#include "level4.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "cell.h"

//Level4::Level4(abc_board *c) : Level{c} {}

Level4::Level4(std::shared_ptr<abc_board> c ) : Level{c} {}

int Level4::getLevel() const {
    return 4;
}

void Level4::initfs(string name) {
    if (name.empty()){
        random = true;
        return;
    }
    filename4 = name;
    random = false;
    ifstream infile{name};
    char blockType;
    while (true) {
        infile >> blockType;
        toBeGenerated4.push(blockType);
        if (infile.fail()) {
            break;
        }
    }
}

// once newBlock return false, game ends
bool Level4::newBlock() {
    cout << "entered Level4's newBlock" << endl;
    shared_ptr<Block> b;
    if (random) {
        char c = getNextType();
        b = produceBlock(c);
        cout << c << "type" << endl;
    } else {
        toBeGenerated4.push(getNextType());
        b = produceBlock(getNextType());
    }
    

    bool successful = b->initBlock(0, 3);
    setNextType();
    return successful;
    if (successful) {
        cout << "successfully created" << endl;
        pushActiveBlocks(b);

        if (countNotCleared == 5) {
            countNotCleared = 1;
            if (!clearedMinimum) { // ckearedMinimum 本来就是false, 不用再set false了
                bool n = dropStar();
                if (!n) {  // dropStar失败
                    return false;
                } else {
                    return true;
                }
            } 
            // else no start is dropped
            clearedMinimum = false;
            return true;
        } else {
            ++countNotCleared;
            return true;    // block inited successfully and cleared at least one row
        }
    } else {
        cout << "failed to new" << endl;
        return false;
    }
}

void Level4::setNextType() {
    char c;
    if (random) {
        int i = rand() % 9;
        if (i == 0 || i == 1) {
            c = 'S';
        } else if (i ==  2 || i == 3) {
            c = 'Z';
        } else if (i == 4) {
            c = 'O';
        } else if (i == 5) {
            c = 'J';
        } else if (i == 6) {
            c = 'L';
        } else if (i == 7) {
            c = 'I';
        } else if (i == 8) {
            c = 'T';
        } 
    } else {
        c = toBeGenerated4.front();
        toBeGenerated4.pop();
    }
    auto b = produceBlock(c);
    clearNextDisplay();
    b->initBlock(0, 21);
    setNext(c);
}

bool Level4::dropStar() {
    //if (rows_cleared)
    for (int i = 17; i >= 0; --i) {
        Cell *p = getBoard().at(i).at(5).get();
        if (!p->getState()) {  // unoccupied
            p->setState(true);
            p->setType('*');
            clear();
            return true;
        }
    }
    
    return false;
    // clear again
}


// 放在curDrop() 之后

void Level4::judge(int row_cleared) {
    if (row_cleared > 0) {
        clearedMinimum = true;
    }
}


/*void Level4::curDrop() {
    component->curDrop();
    int rows_cleared = component->clear();
    if (rows_cleared == 0) {
        countNotCleared += 1;
    } else {
        countNotCleared = 0;
    }
    if (countNotCleared == 5) {
        dropStar();
    }

}*/
// 有n行被clear了
// 那为了看clearedMinimum是否为true, 我们要拿到clear的总行数，如果 > 0, 则true

// clear函数要变成return 总行数的函数

// 拿这个return的东西


 