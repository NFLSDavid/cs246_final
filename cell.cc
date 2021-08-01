#include "cell.h"
#include <iostream>

Cell::Cell(int x, int y, char type): x{x}, y{y}, occupied{false}, type{type} {}

int Cell::getX() {
    return x;
}

int Cell::getY() {
    return y;
}

void Cell::turnOff() {
    occupied = false;
}

void Cell::turnOn() {
    occupied = true;
}

void Cell::draw() {

}
void Cell::undraw() {

}

void Cell::print() {

}
