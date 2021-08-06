#include "board.h"
#include <string>
#include "szblock.h"
#include "iblock.h"
#include "tblock.h"
#include "oblock.h"
#include "jblock.h"
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include <iostream>
#include <sstream>
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

void printGameBoard(abc_board *b1, abc_board *b2) {
    b1->printLevelLine();
    printRiver();
    b2->printLevelLine();
    cout << endl;

    b1->printScoreLine();
    printRiver();
    b2->printScoreLine();
    cout << endl;
    printDivider();

    // so far so good

    
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


/*
-text runs the program in text-only mode. No graphics are displayed. The default behaviour (no -text) is to show
both text and graphics.
• -seed xxx sets the random number generator’s seed to xxx. If you don’t set the seed, you always get the same
random sequence every time you run the program. It’s good for testing, but not much fun.
• -scriptfile1 xxx Uses xxx instead of sequence1.txt as a source of blocks for level 0, for player 1.
• -scriptfile2 xxx Uses xxx instead of sequence2.txt as a source of blocks for level 0, for player 2.
• -startlevel n Starts the game in level n. The game starts in level 0 if this option is not supplied.
*/
/*
bool processArgs(int argc, char** argv) {
    //int count = 0;
    if (argc > 3) {
        cout << "Invalid Command" << endl;
    }

    if (argc == 2) {
        std::string curr = argv[1];
        if (curr == "-text") {
             // do not show graphical display
        } else {
            cout << "Invalid Command" << endl;
        }
    }

    // argc == 3
    for (int i = 1; i < argc; i++) {
        std::string curr = argv[i];
        if (curr == "-seed") {
            istringstream s{argv[i + 1]};
            int seed;
            s >> seed;
            // set seed
        } else if (curr == "-scriptfile1") {
            std::string filename = argv[i + 1];
            // filename作为参数pass进board里
            
        } else if (curr == "-scriptfile1") {
            std::string filename = argv[i + 1];
            
        } else if (curr == "-startlevel") {
            istringstream s{argv[i + 1]};
            int startlevel;
            s >> startlevel;    
        }
        if ( curr[0] == '-') {
            if (curr[1] == 'c') {
                flags[0] = true;
                flagStr[0] = curr.substr(2);
            } else if (curr[1] == 'd') {
                flags[1] = true;
                flagStr[0] = curr.substr(2);
            } else if (curr[1] == 'f') {
                flags[2] = true;
                flagStr[1] = curr.substr(2); // we start at the index where the numbers come out
            } else {
                cerr << "the program only takes in -c, -f, -d flags" << endl;
                return false;
            }
        } else {
            if (count == 0) {
                *infile = new ifstream( argv[i] );
                count += 1;
            } else {
                *outfile = new ofstream( argv[i]);
            }
        }
    }

    return true;
}*/


shared_ptr<abc_board> changeLevel(bool up, shared_ptr<abc_board> b) {
    if (up) {
        if (b->getLevel() == 0) {
            
            b = make_shared<Level1>(b.get());  // b.get() abc_board *
        } else if (b->getLevel() == 1) {
            b = make_shared<Level2>(b.get());
        } else if (b->getLevel() == 2) {
            b = make_shared<Level3>(b.get());
        } else if (b->getLevel() == 3) {
            b = make_shared<Level4>(b.get());
        }
        return b;
    } else {
        if (b->getLevel() == 1) {
            b = make_shared<Level0>(b.get());
        } else if (b->getLevel() == 2) {
            b = make_shared<Level1>(b.get());
        } else if (b->getLevel() == 3) {
            b = make_shared<Level2>(b.get());
        } else if (b->getLevel() == 4) {
            b = make_shared<Level3>(b.get());
        } 
        return b;
    }
}

void changeLevel(bool up, abc_board** b) {
    if (up) {
        if ((*b)->getLevel() == 0) {
            
            *b = new Level1(*b);  // b.get() abc_board *
        } else if ((*b)->getLevel() == 1) {
            *b = new Level2(*b);
        } else if ((*b)->getLevel() == 2) {
            *b = new Level3(*b);
        } else if ((*b)->getLevel() == 3) {
            *b = new Level4(*b);
        }
        return;
    } /*else {
        if (b->getLevel() == 1) {
            b = make_shared<Level0>(b.get());
        } else if (b->getLevel() == 2) {
            b = make_shared<Level1>(b.get());
        } else if (b->getLevel() == 3) {
            b = make_shared<Level2>(b.get());
        } else if (b->getLevel() == 4) {
            b = make_shared<Level3>(b.get());
        } 
        return b;
    }*/
}



int main(int argc, char* argv[]) {
    //shared_ptr<Board> b1 = make_shared<Board>("biquadris_sequence1.txt");
    //istringstream filePlayer1 
    /*shared_ptr<abc_board> b1 = make_shared<Board>("biquadris_sequence1.txt");
    shared_ptr<abc_board> b2 = make_shared<Board>("biquadris_sequence2.txt");*/

    abc_board *b1 = new Board{"biquadris_sequence1.txt"};
    abc_board *b2 = new Board{"biquadris_sequence2.txt"};
    b1 = new Level4(b1);
    b1->initAllCells();
    b2->initAllCells();
    b1->setNextType();
    b2->setNextType();
    //cout << b1->getNextType();
    //b1->update();
    //cout << "Player1 Go" << endl;

    //printGameBoard(b1.get(), b2.get());
    bool continueGame = true;
    abc_board* player;
    string cmd;
    while (continueGame) {
        for (int i = 0; i < 2; i++) {
            if (i == 0) {
                player = b1;
                cout << "Player1 Go" << endl;
                
                if (!player->newBlock()) {
                    cout << "called";
                    continueGame = false;
                    break;
                } // have a new block
        
                printGameBoard(b1, b2);
                
            } else {
                player = b2;
                cout << "Player2 Go" << endl;
                if (!player->newBlock()) {
                    continueGame = false;
                    break;
                }
                printGameBoard(b1, b2);
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
                    int linesCleared = player->clear();
                    player->judge(linesCleared);
                    //player->update();
                    break;
                } else if (cmd == "levelup") {
                    //player = new Level1(player);
                    changeLevel(true, &player);
                } else if (cmd == "leveldown") {
                    //player = changeLevel(false, player);
                }

                else if (cmd == "random") {
                    
                }  else if (cmd == "norandom") {
                    string filename;
                    cin >> filename;
                    b1->initfs(filename);
                }

                if (i == 0) {
                    b1 = player;
                } else {
                    b2 = player;
                }
                printGameBoard(b1, b2);
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