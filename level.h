//#include "abc_block.h"
#ifndef _LEVEL_H_
#define _LEVEL_H_
#include "abc_board.h"
/*class Level: public abc_block {
    public:
    virtual void clockwise();
    virtual void counterclockwise();

    virtual void left();
    virtual void right();
    virtual void down();
    virtual void up();
    void drop();
    virtual ~Level();

    protected:
    Level(abc_block *c);
    abc_block *component;
};*/

class Level: public abc_board {
    public:
        void update();
        std::shared_ptr<Block> produceBlock(char) override;
        virtual void newBlock() override;
        virtual void printNextBlock(char) override;
        void initAllCells() override;
        void restart() override;
        void clear() override;
        void print() override;
        /*void force();   
        void blind();   // maybe a decorator for each one
        void heavy();  // 需要好好考虑*/

        virtual void curRight() override;
        virtual void curLeft() override;
        virtual void curDown() override;
        virtual void curCC() override;
        virtual void curC() override;
        void curDrop() override;

        // for testing
        void printBoard() override;
        virtual ~Level();
    protected:
        Level(abc_board *c);
        abc_board *component;
};

#endif
