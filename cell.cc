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

void Cell::draw() {
    int side_length;
    int col = x * side_length;
    int row = y * side_length;
  /*int each_grid = 500/gridSize;
  int x = c * each_grid;
  int y = r * each_grid;
  
  w->fillRectangle(x,y,each_grid,each_grid, Xwindow::White);*/
  
}

// on->off (black)
void Cell::undraw() {
    int side_length;
    int col = x * side_length;
    int row = y * side_length;
    w->fillRectangle(x,y,side_length,side_length, Xwindow::Black);
}
