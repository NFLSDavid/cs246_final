#include "cell.h"
#include <iostream>

Cell::Cell(int x, int y, char type): x{x}, y{y}, occupied{false}, type{type} {}

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

void Cell::turnOff() {
    occupied = false;
    type = ' ';
}

void Cell::turnOn() {
    occupied = true;
}

void Cell::draw() {

}
void Cell::undraw() {

}

void Cell::print() {
    std::cout << type;
    // the newline character will be added in the actual loop in the Board class
}
