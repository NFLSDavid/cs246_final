#include "cell.h"
#include <iostream>
#include "window.h"
using namespace std;

Cell::Cell(int x, int y, char type): x{x}, y{y}, isBlinded(false), occupied{false}, type{type} {}

int Cell::getX() {
    return x;
}

int Cell::getY() {
    return y;
}

char Cell::getType() {
    return type;
}

void Cell::setType(char t) {
    type = t;
}

bool Cell::getState() {
    return occupied;
}

void Cell::setState(bool s) {
    occupied = s;
}

void Cell::setX(int x) {
    this->x = x;
}

void Cell::setY(int y) {
    this->y = y;
}

void Cell::turnOff() {
    occupied = false;
    type = ' ';
}

void Cell::turnOn() {
    occupied = true;
}

void Cell::unblind() {
    isBlinded = false;
}

void Cell::blind() {
    isBlinded = true;
}


void Cell::print() {
    if (!isBlinded) {
        cout << type;
    } else {
        cout << '?';
    }
    // the newline character will be added in the actual loop in the Board class
}

/*
Cell::Cell(const Cell & other) : x{other.x}, y{other.y}, occupied{other.occupied}, type{other.type} {}
Cell::Cell(Cell &&other) : x{other.x}, y{other.y}, occupied{other.occupied}, type{other.type} {}
Cell & Cell::operator=(const Cell &other) {
    Cell tmp {other};
    swap(x, tmp.x);
    swap(y, tmp.y);
    swap(occupied, tmp.occupied);
    swap(type, tmp.type);
    return *this;
}
Cell & Cell::operator=(Cell &&other) {
    swap(x, other.x);
    swap(y, other.y);
    swap(occupied, other.occupied);
    swap(type, other.type);
    return *this;
}
*/
// on->off (black)
void Cell::undraw(Xwindow *w, int player) {
    int side_length;
    int col = x * side_length;
    int row = y * side_length + 30;
    if (player == 1) {
        col += 254;
    }
    w->fillRectangle(x,y,side_length,side_length, Xwindow::Black);
}

void Cell::draw(Xwindow *w, int player) {
    if (!occupied) {
        w->fillRectangle(x,y + 30,20, 20, Xwindow::Black);
    }
    int side_length = 20;
    int col = x * side_length;
    int row = y * side_length + 30;
    if (player == 1) {
        col += 254;
    }
    if (getType() == 'I') {
       w->fillRectangle(col, row, side_length, side_length, Xwindow::Red);
    } else if (getType() == 'O') {
       w->fillRectangle(col, row, side_length, side_length, Xwindow::Blue);
    } else if (getType() == 'Z') {
       w->fillRectangle(col, row, side_length, side_length,Xwindow::Green);
    } else if (getType() == 'S') {
       w->fillRectangle(col, row, side_length, side_length,Xwindow::Gold);
    } else if (getType() == 'L') {
       w->fillRectangle(col, row, side_length, side_length,Xwindow::Orange);
    } else if (getType() == 'J') {
       w->fillRectangle(col, row, side_length, side_length,Xwindow::Purple);
    } else if (getType() == 'T') {
       w->fillRectangle(col, row, side_length, side_length,Xwindow::Brown);
    } 
}


