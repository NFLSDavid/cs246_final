#ifndef __CELL_H__
#define __CELL_H__

class Cell {
    int x, y;   // x, y (0,0)
    bool occupied;
    char type;

    public:
    Cell(int x, int y, char type);
    int getX();
    int getY();
    void turnOff();

    void turnOn();

    void draw();
    void undraw();

    void print();
    
};

#endif
