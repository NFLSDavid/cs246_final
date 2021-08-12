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
#include "heavy.h"
#include "blind.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <map>
#include "window.h"
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


// 在printGameBoard里fill背景
void printGameBoard(Xwindow *w, abc_board* b1, abc_board* b2, int player) {
    //w->fillRectangle(0, 416, 242, 416, Xwindow::Black);
    
    if (w != nullptr) {
        w->fillRectangle(0, 30, 242, 470, Xwindow::Black);
        w->fillRectangle(256, 30, 242, 470, Xwindow::Black);
        b1->printBoard(w, 0);
        b2->printBoard(w, 1);
        w->fillRectangle(0, 20, 242, 10, Xwindow::White);
        w->fillRectangle(256, 20, 242, 10, Xwindow::White);
        w->fillRectangle(0,416,500,10, Xwindow::White);
        // 所有draw commands 都放在这里
    }

    b1->printLevelLine(w, 100, 10, 0);
    printRiver();
    b2->printLevelLine(w, 256 + 100, 10, 1);
    cout << endl;

    //cout << __LINE__ << std::endl; 
    /*Level1* obj;
    if ( b1->getLevel() == 0 ) {
        b1->printScoreLine();
    } else {
        obj = dynamic_cast<Level1*>( b1 );
        obj->printScoreLine();
    }*/

    b1->printScoreLine(w, 100, 20, 0);
    //cout << __LINE__ << std::endl; 
    printRiver();
    b2->printScoreLine(w, 256 + 100, 20, 1);
    cout << endl;
    printDivider();
    

    // so far so good

    
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 2; j++) {
            if (j == 0) {
                b1->printRows(i, w, player);
                printRiver();
            } else {
                b2->printRows(i, w, player);
                cout << endl;
            }
        }
    }

    printDivider();
    // divider还没draw
    cout << "Next:" << "      ";
    printRiver();
    cout << "Next:" << "      " << endl;

    for (int i = 20; i < 22; i++) {
        for (int j = 0; j < 2; j++) {
            if (j == 0) {
                b1->printRows(i, w, player);
                printRiver();
            } else {
                b2->printRows(i, w, player);
                cout << endl;
            }
        }
    }
}

// return什么还需要抉择


/*
-text runs the program in text-only mode. No graphics are displayed. The default behaviour (no -text) is to show
both text and graphics.
• -seed xxx sets the random number generator’s seed to xxx. If you don’t set the seed, you always get the same
random sequence every time you run the program. It’s good for testing, but not much fun.
• -scriptfile1 xxx Uses xxx instead of sequence1.txt as a source of blocks for level 0, for player 1.
• -scriptfile2 xxx Uses xxx instead of sequence2.txt as a source of blocks for level 0, for player 2.
• -startlevel n Starts the game in level n. The game starts in level 0 if this option is not supplied.
*/

bool processArgs(int argc, char** argv, shared_ptr<abc_board>& b1, shared_ptr<abc_board>& b2, Xwindow **w) {
    //int count = 0;
    if (argc > 3) {
        cout << "Invalid Command" << endl;
        return false;
    }

    if (argc == 2) {
        std::string curr = argv[1];
        if (curr == "-text") {
            *w = nullptr;
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
            srand(seed);
            // set seed
        } else if (curr == "-scriptfile1") {
            std::string filename = argv[i + 1];
            // filename作为参数pass进board里
            b1 = shared_ptr<abc_board>( new Board{filename} );
            
        } else if (curr == "-scriptfile2") {
            std::string filename = argv[i + 1];
            b2 = shared_ptr<abc_board>( new Board{filename} );
        } else if (curr == "-startlevel") {
            istringstream s{argv[i + 1]};
            int startlevel;
            s >> startlevel;  
            if (startlevel == 1) {
                b1 = shared_ptr<abc_board>( new Level1( b1 ) ); 
                b2 = shared_ptr<abc_board>( new Level1( b2 ) );
            } else if (startlevel == 2) {
                b1 = shared_ptr<abc_board>( new Level2( b1 ) ); 
                b2 = shared_ptr<abc_board>( new Level2( b2 ) );
            } else if (startlevel == 3) {
                b1 = shared_ptr<abc_board>( new Level3( b1 ) ); 
                b2 = shared_ptr<abc_board>( new Level3( b2 ) );
            } else if (startlevel == 4) {
                b1 = shared_ptr<abc_board>( new Level4( b1 ) ); 
                b2 = shared_ptr<abc_board>( new Level4( b2 ) );
            }
            
        }
    }

    return true;
}



// delete this function if not working 
void changeLevel(bool up, shared_ptr<abc_board>& b) {
    if (up) {
        if (b->getLevel() == 0) {
            //std::cout << __LINE__ << std::endl;
            b = shared_ptr<abc_board>( new Level1( b ) );
            //*b = make_shared<Level1>((*b).get());  // b.get() abc_board *
            //std::cout << __LINE__ << std::endl;
        } else if (b->getLevel() == 1) {
            b = shared_ptr<abc_board>( new Level2( b ) );
        } else if (b->getLevel() == 2) {
            b = shared_ptr<abc_board>( new Level3( b ) );
        } else if (b->getLevel() == 3) {
            b = shared_ptr<abc_board>( new Level4( b ) );
        }
    } else {
        if (b->getLevel() == 1) {
            //std::cout << __LINE__ << std::endl;
            b = shared_ptr<abc_board>( new Level0( b ) );
            //*b = make_shared<Level1>((*b).get());  // b.get() abc_board *
            //std::cout << __LINE__ << std::endl;
        } else if (b->getLevel() == 2) {
            b = shared_ptr<abc_board>( new Level1( b ) );
        } else if (b->getLevel() == 3) {
            b = shared_ptr<abc_board>( new Level2( b ) );
        } else if (b->getLevel() == 4) {
            b = shared_ptr<abc_board>( new Level3( b ) );
        }
    }
}


// void changeLevel(bool up, abc_board** b) {
//     if (up) {
//         if ((*b)->getLevel() == 0) {
            
//             *b = new Level1(*b);  // b.get() abc_board *
//         } else if ((*b)->getLevel() == 1) {
//             *b = new Level2(*b);
//         } else if ((*b)->getLevel() == 2) {
//             *b = new Level3(*b);
//         } else if ((*b)->getLevel() == 3) {
//             *b = new Level4(*b);
//         }
//         return;
//     } else {
//          if ((*b)->getLevel() == 1) {
            
//             *b = new Level0(*b);  // b.get() abc_board *
//         } else if ((*b)->getLevel() == 2) {
//             *b = new Level1(*b);
//         } else if ((*b)->getLevel() == 3) {
//             *b = new Level2(*b);
//         } else if ((*b)->getLevel() == 4) {
//             *b = new Level3(*b);
//         }
//     }
// }


void changeCurrentBlock(abc_board** player, string cmd) {
   if (cmd == "I") {
        (*player)->changeCurrBlock('I');
    } else if (cmd == "J") {
        (*player)->changeCurrBlock('J');
    } else if (cmd == "T") {
        (*player)->changeCurrBlock('T');
    } else if (cmd == "L") {
        (*player)->changeCurrBlock('L');
    } else if (cmd == "S") {
        (*player)->changeCurrBlock('S');
    } else if (cmd == "Z") {
        (*player)->changeCurrBlock('Z');
    } else if (cmd == "O") {
        (*player)->changeCurrBlock('O');
    } 
}

void changeCurrentBlock(shared_ptr<abc_board>* player, string cmd) {
   if (cmd == "I") {
        (*player)->changeCurrBlock('I');
    } else if (cmd == "J") {
        (*player)->changeCurrBlock('J');
    } else if (cmd == "T") {
        (*player)->changeCurrBlock('T');
    } else if (cmd == "L") {
        (*player)->changeCurrBlock('L');
    } else if (cmd == "S") {
        (*player)->changeCurrBlock('S');
    } else if (cmd == "Z") {
        (*player)->changeCurrBlock('Z');
    } else if (cmd == "O") {
        (*player)->changeCurrBlock('O');
    } 
}

// void drawBoard(Xwindow *w, shared_ptr<abc_board> b1, shared_ptr<abc_board> b2) {
//     /*b1->printLevelLine();
//     printRiver();
//     b2->printLevelLine();
//     cout << endl;

//     b1->printScoreLine(); 
//     printRiver();
//     b2->printScoreLine();
//     cout << endl;

//     printDivider();*/

//     // so far so good

    
//     for (int i = 0; i < 18; i++) {
//         for (int j = 0; j < 2; j++) {
//             if (j == 0) {
//                 b1->printRows(i);
//                 printRiver();
//             } else {
//                 b2->printRows(i);
//                 cout << endl;
//             }
//         }
//     }

//     printDivider();
//     cout << "Next:" << "      ";
//     printRiver();
//     cout << "Next:" << "      " << endl;

//     for (int i = 20; i < 22; i++) {
//         for (int j = 0; j < 2; j++) {
//             if (j == 0) {
//                 b1->printRows(i);
//                 printRiver();
//             } else {
//                 b2->printRows(i);
//                 cout << endl;
//             }
//         }
//     }
// }
int main(int argc, char* argv[]) {
    
    //Xwindow *w = nullptr;
    
   //unique_ptr<Xwindow> w = make_unique<Xwindow>();
    
    // // w->fillRectangle(0, 30, 242, 470, Xwindow::Black);
    // // w->fillRectangle(256, 30, 242, 470, Xwindow::Black);
    
    //x.fillRectangle(0,0, 10,10, Xwindow::Blue);
    //x.drawString(10,10, "Level: ");
    //shared_ptr<Board> b1 = make_shared<Board>("biquadris_sequence1.txt");
    //istringstream filePlayer1 
    shared_ptr<abc_board> b1 = make_shared<Board>("biquadris_sequence1.txt");
    shared_ptr<abc_board> b2 = make_shared<Board>("biquadris_sequence2.txt");

    if (processArgs(argc, argv, b1, b2, nullptr) == false) {
        return 0;
    }
    // abc_board *b1 = new Board{"allO.txt"};
    // abc_board *b2 = new Board{"biquadris_sequence2.txt"};
    b1->initAllCells();
    b2->initAllCells();
    b1->setNextType();
    b2->setNextType();
    //cout << b1->getNextType();
    //b1->update();
    //cout << "Player1 Go" << endl;
    /*while (true) {
        cin >> cmd;

    }*/
    //printGameBoard(b1.get(), b2.get());
    bool continueGame = true;
    //abc_board* player;
    //shared_ptr<abc_board> player;
    string cmd;
    while (continueGame) {
        for (int i = 0; i < 2; i++) {
            shared_ptr<abc_board>& player = i == 0 ? b1 : b2;
            // player = i == 0 ? b1 : b2; 
            if (i == 0) {
                //player = b1;
                cout << "Player1 Go" << endl;
                
                if (!player->newBlock()) {
                    cout << "Player One Lost, Game Over!" << endl;
                    continueGame = false;
                    break;
                } // have a new block
                //printGameBoard(b1, b2);
                //cout << "starting to draw board" << endl;
                printGameBoard(nullptr, b1.get(), b2.get(), i);
                
            } else {
                //player = b2;
                cout << "Player2 Go" << endl;
                if (!player->newBlock()) {
                    continueGame = false;
                    break;
                }
                //printGameBoard(b1, b2);
                printGameBoard(nullptr, b1.get(), b2.get(), i);
            }
            bool restart = false;
            while (true) {
                cin >> cmd;
                int steps = 1;
                try {
                    steps = stoi(cmd) ;
                    cmd = cmd.substr(1);
                } catch (exception&) {
                    /* ... */
                }

                cout << "steps are: " << steps << endl;
                bool dropped = false;
                
                for (int j = 0; j < steps; j++) {
                    
                    if (cmd[0] == 'r') {
                        if (cmd[1] == 'a') {                            // random
                            player->initfs("");
                        } else if (cmd[1] == 'e') {                     // restart
                            //b1->restart();
                            //b2->restart();
                            shared_ptr<abc_board> b3 = make_shared<Board>("biquadris_sequence1.txt");
                            shared_ptr<abc_board> b4 = make_shared<Board>("biquadris_sequence2.txt");
                            b1 = b3;
                            b2 = b4;

                            b1->initAllCells();
                            b2->initAllCells();
                            b1->setNextType();
                            b2->setNextType();
                            restart = true;
                            break;
                        } else if (cmd[1] == 'i') {                     // right
                            bool successful = player->curRight();
                            if (!successful) {
                                int linesCleared = player->clear();
                                player->judge(linesCleared);
                                break;
                            }
                        }       
                    } else if (cmd[0] == 'l') {

                        if (cmd.substr(0,3) == "lef") {  // left
                            bool successful = player->curLeft();
                            // if 能往下(true)，nothing happens
                            // if not
                            if (!successful) {
                                int linesCleared = player->clear();
                                player->judge(linesCleared);
                                break;
                            }
                        } else if (cmd.substr(0,6) == "levelu") {  // levelup
                            changeLevel(true, player);
                        } else if (cmd.substr(0,6) == "leveld") {  // levelup
                            changeLevel(false, player);
                        }
                    
                    } else if (cmd[0] == 'd') {
                        if (cmd.substr(0,2) == "do") {              // down
                            player->curDown();
                        } else if (cmd.substr(0,2) == "dr") {              // drop

                            cout << "dropped the block" << endl;
                            player->curDrop();
                            int linesCleared = player->clear();
                            player->judge(linesCleared);
                            //player->update();

                            // print一下
                            //printGameBoard(b1, b2);
                            printGameBoard(nullptr, b1.get(), b2.get(), i);

                            
                            if (linesCleared >= 2) {
                                cout << "Enter the negative influence you want to impose on the opponent's board: ";
                                string inf;
                                cin >> inf;

                                if (inf[0] == 'h') {                                        // heavy
                                    if (i == 0) {
                                        b2 = shared_ptr<abc_board>( new Heavy( b2 ) );
                                    } else {
                                        b1 = shared_ptr<abc_board>( new Heavy( b1 ) );
                                    }
                                } else if (inf[0] == 'b') {                                 // blind
                                    if (i == 0) {
                                        b2 = shared_ptr<abc_board>( new Blind( b2 ) );
                                    } else {
                                        b1 = shared_ptr<abc_board>( new Blind( b1 ) );
                                    }
                                } else if (inf[0] == 'f') {                                 // force
                                    string changed;
                                    cin >> changed;
                                    if (i == 0) {
                                        changeCurrentBlock(&b2, changed);
                                    } else {
                                        changeCurrentBlock(&b1, changed);
                                    }    
                                }
                            }
                            dropped = true;
                            break;
                        }
                        
                    } else if (cmd[0] == 'c') {
                        if (cmd.substr(0,2) == "co") {
                            player->curC();
                        } else if (cmd.substr(0,2) == "cl") {
                            player->curCC();
                        }
                        
                    } else if (cmd == "I" || cmd == "J" || cmd == "T" || cmd == "L" ||  
                    cmd == "S" ||cmd == "Z" || cmd == "O") {
                        changeCurrentBlock(&player, cmd);
                                
                    } else if (cmd[0] == 'n') {
                        string filename;
                        cin >> filename;
                        player->initfs(filename);
                    } else if (cmd[0] == 'h') {
                        
                    }

                    
                    if (i == 0) {
                        b1 = player;
                    } else {
                        b2 = player;
                    }
                //printGameBoard(b1, b2);
                    printGameBoard(nullptr, b1.get(), b2.get(), i);
                }
                if (dropped || restart) {
                    break;
                }
                if (i == 0) {
                    b1 = player;
                } else {
                    b2 = player;
                }
            }
            if (restart) {
                restart = false;
                break;
            }
        }
        if (!continueGame) break;
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
                 



// if (cmd == "right") {
//                         bool successful = player->curRight();
//                         if (!successful) {
//                             int linesCleared = player->clear();
//                             player->judge(linesCleared);
//                             break;
//                         }               
//                     } else if (cmd == "left") {
//                         bool successful = player->curLeft();
//                         // if 能往下(true)，nothing happens
//                         // if not
//                         if (!successful) {
//                             int linesCleared = player->clear();
//                             player->judge(linesCleared);
//                             break;
//                         }

//                     } else if (cmd == "down") {
//                         player->curDown();
//                     } else if (cmd == "counterclockwise") {
//                         player->curCC();
//                     } else if (cmd == "clockwise") {
//                         player->curC();
//                     } else if (cmd == "I" || cmd == "J" || cmd == "T" || cmd == "L" ||  
//                     cmd == "S" ||cmd == "Z" || cmd == "O") {
//                         changeCurrentBlock(&player, cmd);
                                
//                     }
//                     /*else if (cmd == "I") {
//                         player->changeCurrBlock('I');
//                     } else if (cmd == "J") {
//                         player->changeCurrBlock('J');
//                     } else if (cmd == "T") {
//                         player->changeCurrBlock('T');
//                     } else if (cmd == "L") {
//                         player->changeCurrBlock('L');
//                     } else if (cmd == "S") {
//                         player->changeCurrBlock('S');
//                     } else if (cmd == "Z") {
//                         player->changeCurrBlock('Z');
//                     } else if (cmd == "O") {
//                         player->changeCurrBlock('O');
//                     } */else if (cmd == "drop") {
//                         player->curDrop();
//                         int linesCleared = player->clear();
//                         player->judge(linesCleared);
//                         //player->update();

//                         // print一下
//                         //printGameBoard(b1, b2);
//                         printGameBoard(b1.get(), b2.get());

                        
//                         if (linesCleared >= 2) {
//                             cout << "Enter the negative influence you want to impose on the opponent's board: ";
//                             string inf;
//                             cin >> inf;

//                             /*if (inf == "heavy") {
//                                 if (i == 0) {
//                                     b2 = new Heavy(b2);
//                                 } else {
//                                     b1 = new Heavy(b1);
//                                 }
//                             } else if (inf == "blind") {
//                                 if (i == 0) {
//                                     b2 = new Blind(b2);
//                                 } else {
//                                     b1 = new Blind(b1);
//                                 }
//                             } else if (inf == "force") {
//                                 string changed;
//                                 cin >> changed;
//                                 if (i == 0) {
//                                     changeCurrentBlock(&b2, changed);
//                                 } else {
//                                     changeCurrentBlock(&b1, changed);
//                                 }    
//                             }*/
//                         }
//                         break;
//                     } else if (cmd == "levelup") {
//                         //player = new Level1(player);
//                         changeLevel(true, player);
//                     } else if (cmd == "leveldown") {
//                         changeLevel(false, player);
//                     }

//                     else if (cmd == "random") {
//                         player->initfs("");
//                     }  else if (cmd == "norandom") {
//                         string filename;
//                         cin >> filename;
//                         player->initfs(filename);
//                     }

//                     if (i == 0) {
//                         b1 = player;
//                     } else {
//                         b2 = player;
//                     }
//                     //printGameBoard(b1, b2);
//                     //std::cout << __LINE__ << endl;
//                     printGameBoard(b1.get(), b2.get());
//                     //std::cout << __LINE__ << endl; 
//                 } 
        
//                 if (i == 0) {
//                     b1 = player;
//                 } else {
//                     b2 = player;
//                 }


// void changeLevel(bool up, shared_ptr<abc_board>* b) {
//     if (up) {
//         if ((*b)->getLevel() == 0) {
//             //std::cout << __LINE__ << std::endl;
//             *b = shared_ptr<abc_board>( new Level1( (*b).get() ) );
//             //*b = make_shared<Level1>((*b).get());  // b.get() abc_board *
//             //std::cout << __LINE__ << std::endl;
//         } else if ((*b)->getLevel() == 1) {
//             *b = make_shared<Level2>((*b).get());
//         } else if ((*b)->getLevel() == 2) {
//             (*b) = make_shared<Level3>((*b).get());
//         } else if ((*b)->getLevel() == 3) {
//             *b = make_shared<Level4>((*b).get());
//         }
//     } else {
//         if ((*b)->getLevel() == 1) {
//             *b = make_shared<Level0>((*b).get());
//         } else if ((*b)->getLevel() == 2) {
//             *b = make_shared<Level1>((*b).get());
//         } else if ((*b)->getLevel() == 3) {
//             *b = make_shared<Level2>((*b).get());
//         } else if ((*b)->getLevel() == 4) {
//             *b = make_shared<Level3>((*b).get());
//         }
//     }
// }