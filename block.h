#ifndef _BLOCK_H_
#define _BLOCK_H_

using namespace std;
#include <utility>
#include <memory>
#include <vector>

typedef pair<int, int> point;
class Xwindow;
class abc_board;

class Block {
    private:
    abc_board *b;
    int level; 
    int activeNum;
    
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    
    public:
    Block(abc_board *b, int level, char type);

    // if we failed to init a new block, then we return false; and that could tell the game
    // to end; if true, then we successfully created a block
    virtual bool initBlock(int x, int y) = 0; 
    void initNextBlock();
    virtual void clockwise() = 0;
    virtual void counterclockwise() = 0;
    void left();
    void right();
    bool down();
    void drop();
    bool dropRow(int);

    void drawBlock(Xwindow *w, int player);
    void undrawBlock(Xwindow *w, int player);
    // getter
    int getLevel();
    // setter
    void setFalse();        // set False and set type to space
    void setTrue();
    shared_ptr<point> getLeftCorner();
    virtual ~Block();
    
    protected:
    vector <point> p_array;
    char type;
    point p;
    bool valid;
    //void setFalse();        // set False and set type to space
    //void setTrue();
    bool checkValidMove();

    
};

#endif
