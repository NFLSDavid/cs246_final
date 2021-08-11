#include "blind.h"
#include "cell.h"
using namespace std;

Blind::Blind(std::shared_ptr<abc_board> c) : Level{c}, isBlinded{true} {
    auto b = getBoard();
    for (int x = 0; x < 11; ++x) {
        for (int y = 0; y < 18; ++y) {
            if ((x >= 2 && x <= 8) || (y >= 5 && y <= 14)) {
                b.at(y).at(x).get()->blind();
            }
        }
    }
}

void Blind::unblind() {
    auto b = getBoard();
    isBlinded = false;
    for (int x = 0; x < 11; ++x) {
        for (int y = 0; y < 18; ++y) {
            b.at(y).at(x).get()->unblind();
        }
    }
}

int Blind::getLevel() const {
    return component->getLevel();
}

bool Blind::newBlock() {
    return component->newBlock();
}

void Blind::setNextType() {
    component->setNextType();
}

void Blind::judge(int n) {
    component->judge(n);
}

void Blind::curDrop() {
    component->curDrop();
    if (isBlinded) {
        unblind();
    }
}
