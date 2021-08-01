#include "board.h"
#include "cell.h"

void Board::initAllCells() {
    for (int i = 0; i < 18; i++) {
        vector<Cell*> row;
        for (int j = 0; j < 11; j++) {
            Cell *c = new Cell(j, i, ' ');
            row.push_back(c);
        }
        cells.push_back(row);
    }
}

