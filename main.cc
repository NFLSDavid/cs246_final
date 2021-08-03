#include "board.h"
#include <string>
#include "iblock.h"
#include "zblock.h"
#include "oblock.h"
#include <iostream>
using namespace std;

int main() {
    shared_ptr<Board> b1 = make_shared<Board>();
    b1->initAllCells();
    iblock b = iblock{b1.get(), 'I'};
    zblock z = zblock{b1.get(), 'Z'};
    
    //b.initBlock();
    b.initBlock();
    b1->printBoard();
    string cmd;
    while (true) {
        cin >> cmd;
        
        if (cmd == "right") {
            //b.setFalse();
            b.right();
            
        } else if (cmd == "left") {
            b.left();
        } else if (cmd == "down") {
            b.down();
        } else if (cmd == "counterclockwise") {
            b.counterclockwise();
        } else if (cmd == "clockwise") {
            b.clockwise();
        }
        b1->printBoard();
    } 

}
