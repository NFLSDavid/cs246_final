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
    //shared_ptr<Board> b1 = make_shared<Board>("biquadris_sequence1.txt");
    shared_ptr<Board> b1 = make_shared<Board>("biquadris_sequence1.txt");
    shared_ptr<Board> b2 = make_shared<Board>("allO.txt");
    b1->initAllCells();
    b2->initAllCells();
    b1->setNextType();
    b1->update();
    string cmd;
    while (true) {
        cin >> cmd;
        /*for (int i = 0; i < 2; i++) {
            Board *player;
            if (i == 0) {
                cout << "Player1 Go" << endl;
            } 
        }*/
        
        if (cmd == "right") {
            //b.setFalse();
            b1->curRight();
            
        } else if (cmd == "left") {
            b1->curLeft();
        } else if (cmd == "down") {
            b1->curDown();
        } else if (cmd == "counterclockwise") {
            b1->curCC();
        } else if (cmd == "clockwise") {
            b1->curC();
        } else if (cmd == "I") {
            /*Block *curr = b1->getCurrBlock();
            curr->setFalse();  // currBlock setFalse(disappear)
            auto i = make_shared<iblock>(b1.get(), 'I');
            bool initStat = i->initBlock(curr->getLeftCorner()->first, curr->getLeftCorner()->second);
            if (!initStat) {  // if we failed to init this new block
                curr->setTrue();
            }  else {
                b1->popCurrBlock();
                b1->pushCurrBlock(i);
                //pop the original current block out
                //push the new block in instead
            }*/
            b1->changeCurrBlock('I');
        } else if (cmd == "J") {
            b1->changeCurrBlock('J');
        } else if (cmd == "T") {
            b1->changeCurrBlock('T');
        } else if (cmd == "L") {
            b1->changeCurrBlock('L');
        } else if (cmd == "S") {
            b1->changeCurrBlock('S');
        } else if (cmd == "Z") {
            b1->changeCurrBlock('Z');
        } else if (cmd == "O") {
            b1->changeCurrBlock('O');
        } else if (cmd == "drop") {
            b1->curDrop();
            b1->update();


        } else if (cmd == "levelup") {

        } else if (cmd == "leveldown") {
            
        }

         else if (cmd == "random") {
            
        }  else if (cmd == "norandom") {
            string filename;
            cin >> filename;
            b1->initfs(filename);
        }
        b1->printBoard();
    } 

}

/*iblock b = iblock{b1.get(), 'I'};
    szblock z = szblock{b1.get(), 'Z'};
    szblock s = szblock{b1.get(), 'S'};
    tblock t = tblock(b1.get(), 'T');
    //jblock j = jblock(b1.get(), 'J');
    Block *j = new jblock{b1.get(), 'J'};
    //b.initBlock();
    //j->initBlock(0,3);
    //b1->printBoard();*/
