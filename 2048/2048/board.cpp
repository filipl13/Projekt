#include "board.h"
#include <cstdlib>

Board::Board() {
    reset();
}

void Board::reset() {
    score = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            grid[i][j] = 0;
        }
    }

    addRandomTile();
    addRandomTile();
}


int Board::getValue(int row, int col) const {
    return grid[row][col];
}

int Board::getScore() const {
    return score;
}

void Board::addRandomTile() {
    int emptyCells[16][2];
    int count = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] == 0) {
                emptyCells[count][0] = i;
                emptyCells[count][1] = j;
                count++;
            }
        }
    }

    if (count == 0) return;

    int r = rand() % count;
    int row = emptyCells[r][0];
    int col = emptyCells[r][1];

    grid[row][col] = 2;
}

bool Board::moveLeft() {
    bool moved = false;

    for (int row = 0; row < 4; row++) {
        int targetCol = 0;

        for (int col = 0; col < 4; col++) {
            if (grid[row][col] != 0) {
                if (col != targetCol) {
                    grid[row][targetCol] = grid[row][col];
                    grid[row][col] = 0;
                    moved = true;
                }
                targetCol++;
            }
        }
    }

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row][col] != 0 &&
                grid[row][col] == grid[row][col + 1]) {

                grid[row][col] *= 2;
                score += grid[row][col];
                grid[row][col + 1] = 0;
                moved = true;
            }
        }
    }

    for (int row = 0; row < 4; row++) {
        int targetCol = 0;

        for (int col = 0; col < 4; col++) {
            if (grid[row][col] != 0) {
                if (col != targetCol) {
                    grid[row][targetCol] = grid[row][col];
                    grid[row][col] = 0;
                }
                targetCol++;
            }
        }
    }

    if (moved) {
        addRandomTile();
    }

    return moved;
}

bool Board::moveRight() {
    rotateRight();
    rotateRight();
    bool moved = moveLeft();
    rotateRight();
    rotateRight();

    if (moved) addRandomTile();
    return moved;
}

bool Board::moveUp() {
    rotateRight();
    rotateRight();
    rotateRight();
    bool moved = moveLeft();
    rotateRight();

    if (moved) addRandomTile();
    return moved;
}

bool Board::moveDown() {
    rotateRight();
    bool moved = moveLeft();
    rotateRight();
    rotateRight();
    rotateRight();

    if (moved) addRandomTile();
    return moved;
}


void Board::rotateRight() {
    int temp[4][4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            temp[j][3 - i] = grid[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            grid[i][j] = temp[i][j];
        }
    }
}