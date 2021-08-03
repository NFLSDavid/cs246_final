#include "board.h"
#include <string>
#include "szblock.h"
#include "iblock.h"

#include "oblock.h"
#include <iostream>
using namespace std;

int main() {
    shared_ptr<Board> b1 = make_shared<Board>();
    b1->initAllCells();
    iblock b = iblock{b1.get(), 'I'};
    szblock z = szblock{b1.get(), 'Z'};
    szblock s = szblock{b1.get(), 'S'};
    //b.initBlock();
    s.initBlock();
    b1->printBoard();
    string cmd;
    while (true) {
        cin >> cmd;
        
        if (cmd == "right") {
            //b.setFalse();
            s.right();
            
        } else if (cmd == "left") {
            s.left();
        } else if (cmd == "down") {
            s.down();
        } else if (cmd == "counterclockwise") {
            s.counterclockwise();
        } else if (cmd == "clockwise") {
            s.clockwise();
        }
        b1->printBoard();
    } 

}
