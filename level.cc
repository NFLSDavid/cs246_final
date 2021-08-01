#include "level.h"

Level::Level(abc_block *c): component{c} {}

void Level::clockwise() {
    component->clockwise();
}

void Level::counterclockwise() {
    component->counterclockwise();
}

void Level::left() {
    component->left();
}

void Level::right() {
    component->right();
}

void Level::down() {
    component->down();
}

void Level::up() {
    component->up();
}

void Level::drop() {
    component->drop();
}
