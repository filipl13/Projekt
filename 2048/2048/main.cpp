#include <iostream>
#include "board.h"
#include <cstdlib>
#include <conio.h>
void clear_screen()
{
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}
void printBoard(const Board& board) {
    std::cout << "\n---------------------\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int v = board.getValue(i, j);
            if (v == 0)
                std::cout << ".\t";
            else
                std::cout << v << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << "---------------------\n";
}

int main() {
    Board board;
    char input;

    while (true) {
        clear_screen();

        printBoard(board);
        std::cout << "Score: " << board.getScore() << "\n\n";

        std::cout << "W = gore | A = lijevo | S = dolje | D = desno\n";
        std::cout << "R = reset | Q = izlaz\n";
        std::cout << "Unos: ";

        input = _getch();

        bool moved = false;

        if (input == 'a' || input == 'A') moved = board.moveLeft();
        else if (input == 'd' || input == 'D') moved = board.moveRight();
        else if (input == 'w' || input == 'W') moved = board.moveUp();
        else if (input == 's' || input == 'S') moved = board.moveDown();
        else if (input == 'r' || input == 'R') board.reset();
        else if (input == 'q' || input == 'Q') break;
    }

    return 0;
}
