#include "abc_block.h"
using namespace std;
#include <utility>
#include <vector>

typedef pair<int, int> point;

class Block: public abc_block {
    private:
    point p;
    bool checkValidMove();

    public:
    Block();
    virtual void clockwise() = 0;
    virtual void counterclockwise() = 0;
    void left();
    void right();
    void down();
    void up();
    void drop();
    virtual ~Block() = 0;
    
    protected:
    vector <point> p_array;
};
