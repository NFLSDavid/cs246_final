#include "abc_block.h"

class Level: public abc_block {
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
};
