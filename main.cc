#include "board.h"
#include <string>
#include "iblock.h"
#include <iostream>
using namespace std;

int main() {
    shared_ptr<Board> b1 = make_shared<Board>();
    b1->initAllCells();
    iblock b = iblock{b1.get(), 'I'};
    b.initBlock();
    b1->printBoard();
    /*string cmd;
    cin >> cmd;

    if (cmd == "right") {
        
    }*/


}