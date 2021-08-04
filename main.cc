#include "board.h"
#include <string>
#include "szblock.h"
#include "iblock.h"
#include "tblock.h"
#include "oblock.h"
#include "jblock.h"
#include <iostream>
using namespace std;

int main() {
    shared_ptr<Board> b1 = make_shared<Board>();
    b1->initAllCells();
    iblock b = iblock{b1.get(), 'I'};
    szblock z = szblock{b1.get(), 'Z'};
    szblock s = szblock{b1.get(), 'S'};
    tblock t = tblock(b1.get(), 'T');
    //jblock j = jblock(b1.get(), 'J');
    Block *j = new jblock{b1.get(), 'J'};
    //b.initBlock();
    j->initBlock(0,3);
    b1->printBoard();
    string cmd;
    while (true) {
        cin >> cmd;
        
        if (cmd == "right") {
            //b.setFalse();
            j->right();
            
        } else if (cmd == "left") {
            j->left();
        } else if (cmd == "down") {
            j->down();
        } else if (cmd == "counterclockwise") {
            j->counterclockwise();
        } else if (cmd == "clockwise") {
            j->clockwise();
        } else if (cmd == "I") {
            j->setFalse();  // currBlock setFalse(disappear)
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
