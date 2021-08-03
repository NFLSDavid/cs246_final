//#include "abc_block.h"
using namespace std;
#include <utility>
#include <vector>

typedef pair<int, int> point;

class Board;

class Block/*: public abc_block*/ {
    private:
    
    Board *b;
    int level; 
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    
    public:
    Block(Board *b, char type);

    // if we failed to init a new block, then we return false; and that could tell the game
    // to end; if true, then we successfully created a block
    virtual bool initBlock() = 0; 

    virtual void clockwise() = 0;
    virtual void counterclockwise() = 0;
    void left();
    void right();
    void down();
    void drop();
    virtual ~Block() = 0;
    
    protected:
    vector <point> p_array;
    char type;
    point p;
    bool valid;
    void setFalse();        // set False and set type to space
    void setTrue();
    bool checkValidMove();
};
