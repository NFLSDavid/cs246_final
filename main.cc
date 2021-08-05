#include "board.h"
#include <string>
#include "szblock.h"
#include "iblock.h"
#include "tblock.h"
#include "oblock.h"
#include "jblock.h"
#include <iostream>
using namespace std;

void printRiver() {
    cout << "       ";
}

void printDivider() {
    
    for (int i = 0; i < 11; i++) {
        cout << '_';
    }
    printRiver();
    for (int i = 0; i < 11; i++) {
        cout << '_';
    }
    cout << endl;
}

void printGameBoard(Board *b1, Board *b2) {
    b1->printLevelLine();
    printRiver();
    b2->printLevelLine();
    cout << endl;

    b1->printScoreLine();
    printRiver();
    b2->printScoreLine();
    cout << endl;

    printDivider();

    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 2; j++) {
            if (j == 0) {
                b1->printRows(i);
                printRiver();
            } else {
                b2->printRows(i);
                cout << endl;
            }
        }
    }

    printDivider();
    cout << "Next:" << "      ";
    printRiver();
    cout << "Next:" << "      " << endl;

    for (int i = 20; i < 22; i++) {
        for (int j = 0; j < 2; j++) {
            if (j == 0) {
                b1->printRows(i);
                printRiver();
            } else {
                b2->printRows(i);
                cout << endl;
            }
        }
    }
}


int main() {
    //shared_ptr<Board> b1 = make_shared<Board>("biquadris_sequence1.txt");
    shared_ptr<Board> b1 = make_shared<Board>("biquadris_sequence1.txt");
    shared_ptr<Board> b2 = make_shared<Board>("allO.txt");
    b1->initAllCells();
    b2->initAllCells();
    b1->setNextType();
    b2->setNextType();
    //b1->update();
    //cout << "Player1 Go" << endl;

    //printGameBoard(b1.get(), b2.get());
    bool continueGame = true;
    shared_ptr<Board> player;
    string cmd;
    while (continueGame) {
        for (int i = 0; i < 2; i++) {
            if (i == 0) {
                player = b1;
                cout << "Player1 Go" << endl;
                
                if (!player->newBlock()) {
                    continueGame = false;
                    break;
                } // have a new block

                printGameBoard(b1.get(), b2.get());
                
            } else {
                player = b2;
                cout << "Player2 Go" << endl;
                if (!player->newBlock()) {
                    continueGame = false;
                    break;
                }
                printGameBoard(b1.get(), b2.get());
            }

            while (true) {
                cin >> cmd;

                if (cmd == "right") {
                    player->curRight();               
                } else if (cmd == "left") {
                    player->curLeft();
                } else if (cmd == "down") {
                    player->curDown();
                } else if (cmd == "counterclockwise") {
                    player->curCC();
                } else if (cmd == "clockwise") {
                    player->curC();
                } else if (cmd == "I") {
                    player->changeCurrBlock('I');
                } else if (cmd == "J") {
                    player->changeCurrBlock('J');
                } else if (cmd == "T") {
                    player->changeCurrBlock('T');
                } else if (cmd == "L") {
                    player->changeCurrBlock('L');
                } else if (cmd == "S") {
                    player->changeCurrBlock('S');
                } else if (cmd == "Z") {
                    player->changeCurrBlock('Z');
                } else if (cmd == "O") {
                    player->changeCurrBlock('O');
                } else if (cmd == "drop") {
                    player->curDrop();
                    //player->update();
                    break;
                } else if (cmd == "levelup") {
                    
                } else if (cmd == "leveldown") {
                    
                }

                else if (cmd == "random") {
                    
                }  else if (cmd == "norandom") {
                    string filename;
                    cin >> filename;
                    b1->initfs(filename);
                }
                printGameBoard(b1.get(), b2.get());
            } 
        }
    }
}



// garbage code
/*iblock b = iblock{b1.get(), 'I'};
    szblock z = szblock{b1.get(), 'Z'};
    szblock s = szblock{b1.get(), 'S'};
    tblock t = tblock(b1.get(), 'T');
    //jblock j = jblock(b1.get(), 'J');
    Block *j = new jblock{b1.get(), 'J'};
    //b.initBlock();
    //j->initBlock(0,3);
    //b1->printBoard();*/


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