#ifndef _LEVEL1_H_
#define _LEVEL1_H_

#include <vector>
#include <memory>
#include <queue>
#include <string>
#include "level.h"

using namespace std;

class Cell;

class Block;

class Level1: public Level {
    public:
        //void update();
        //shared_ptr<Block> produceBlock(char) override;
        virtual void newBlock() override;
        virtual void setNextType() override;
        
        /*virtual void printNextBlock(char) override;
        void initAllCells() override;
        void restart() override;
        void clear() override;*/
        /*void force();   
        void blind();   // maybe a decorator for each one
        void heavy();  // 需要好好考虑*/

        /*virtual void curRight() override;
        virtual void curLeft() override;
        virtual void curDown() override;
        virtual void curCC() override;
        virtual void curC() override;
        void curDrop() override;*/

        // for testing
        //void printBoard() override;
        ~Level1();
};

#endif
