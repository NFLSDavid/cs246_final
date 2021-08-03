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
    
    //b.initBlock();
    z.initBlock();
    b1->printBoard();
    string cmd;
    while (true) {
        cin >> cmd;
        
        if (cmd == "right") {
            //b.setFalse();
            z.right();
            
        } else if (cmd == "left") {
            z.left();
        } else if (cmd == "down") {
            z.down();
        } else if (cmd == "counterclockwise") {
            z.counterclockwise();
        } else if (cmd == "clockwise") {
            z.clockwise();
        }
        b1->printBoard();
    } 

}
