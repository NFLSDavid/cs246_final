#include "abc_block.h"
using namespace std;
#include <utility>
#include <vector>

typedef pair<int, int> point;


class Block: public abc_block {
    private:
    int level;
    point p;
    bool checkValidMove();
    void setFalse();        // set False and set type to space
    void setTrue();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    
    public:
    Block(Board *b, char type);
    virtual void clockwise() = 0;
    virtual void counterclockwise() = 0;
    void left();
    void right();
    void down();
    //void up();
    void drop();
    virtual ~Block() = 0;
    
    protected:
    vector <point> p_array;
    char type;
};
