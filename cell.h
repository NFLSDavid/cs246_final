#ifndef __CELL_H__
#define __CELL_H__

class Cell {
    int x, y;   // x, y (0,0)
    bool isBlinded;
    bool occupied;
    char type;

    public:
    Cell(int x, int y, char type);
    int getX();
    int getY();
    void setX(int);
    void setY(int);

    char getType();
    void setType(char t);

    void turnOff();
    void turnOn();
    bool getState();
    void setState(bool);
    
    void blind();
    void unblind();

    void draw();
    void undraw();

    void print();  // print 
    
};

#endif