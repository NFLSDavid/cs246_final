#include "heavy.h"
using namespace std;

Heavy::Heavy(abc_board *c) : Level{c}, isHeavy{true} {}

int Heavy::getLevel() const {
    return component->getLevel();
}

bool Heavy::newBlock() {
    return component->newBlock();
}

void Heavy::setNextType() {
    component->setNextType();
}

void Heavy::judge(int n) {
    component->judge(n);
}

void Heavy::curDrop() {
    component->curDrop();
    if (isHeavy) {
        isHeavy = false;
    }
}

bool Heavy::curLeft() {
    bool b = component->curLeft();
    
    if (isHeavy) {
        if (getCurrBlock()->down()) {
            if (!getCurrBlock()->down()) {
                curDrop();
                return false;
            }
            return true;
        } else {
            curDrop();
            return false;
        }
    }
    return true;
}

bool Heavy::curRight() {
    bool b = component->curRight();
    if (isHeavy) {
        if (getCurrBlock()->down()) {
            if (!getCurrBlock()->down()) {
                curDrop();
                return false;
            }
            return true;
        } else {
            curDrop();
            return false;
        }
    }
    return true;
}
