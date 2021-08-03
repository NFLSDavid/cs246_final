#include "board.h"
#include <string>
#include "szblock.h"
#include "iblock.h"
#include "tblock.h"
#include "oblock.h"
#include <iostream>
using namespace std;

int main() {
    shared_ptr<Board> b1 = make_shared<Board>();
    b1->initAllCells();
    iblock b = iblock{b1.get(), 'I'};
    szblock z = szblock{b1.get(), 'Z'};
    szblock s = szblock{b1.get(), 'S'};
    tblock t = tblock(b1.get(), 'T');
    //b.initBlock();
    s.initBlock(0,3);
    b1->printBoard();
    string cmd;
    while (true) {
        cin >> cmd;
        
        if (cmd == "right") {
            //b.setFalse();
            t.right();
            
        } else if (cmd == "left") {
            t.left();
        } else if (cmd == "down") {
            t.down();
        } else if (cmd == "counterclockwise") {
            t.counterclockwise();
        } else if (cmd == "clockwise") {
            t.clockwise();
        } else if (cmd == "I") {
            t.setFalse();  // currBlock setFalse(disappear)
            iblock *i = new iblock{b1.get(), 'I'};
            bool initStat = i->initBlock(t.getLeftCorner()->first, t.getLeftCorner()->second);
            if (!initStat) {  // if we failed to init this new block
                t.setTrue();
            } /* else {
                pop the original current block out
                push the new block in instead
            }*/
        }
        b1->printBoard();
    } 

}
