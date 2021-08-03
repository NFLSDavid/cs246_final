//#include "abc_block.h"
#include "board.h"

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

class Level: public Board {
    public:
        virtual void currClockwise();
        virtual void currCounterclockwise();

        virtual void currLeft();
        virtual void currRight();
        virtual void currDown();
        void drop();
        void clear();
        virtual ~Level();
    protected:
        Level(Board *c);
        Board *component;
};
