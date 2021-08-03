#include "Board.h"
#include <stdexcept>

using namespace std;

Board::Board()
{
    board.push_back(' '); // dummy
    for(int i = 1; i <= 9; ++i)
        board.push_back(' ');
}

void Board::turn(unsigned int pos, char notation)
{
    if(pos > 9 || pos < 1)
        throw out_of_range("Turn in range of 3x3 Tic-Tac-Toe -> range: (1-9).");

    board[pos] = notation;
}

string Board::toString() const
{
    string res = "       |       |        \n   " + string(1, board[1]) + "   |   " + string(1, board[2]) + "   |   " + string(1, board[3]) +
            "    \n       |       |        \n-------|-------|--------\n       |       |        \n   " + string(1, board[4]) + "   |   " + string(1, board[5]) + "   |   " + string(1, board[6]) +
            "    \n       |       |        \n-------|-------|--------\n       |       |        \n   " + string(1, board[7]) + "   |   " + string(1, board[8]) + "   |   " + string(1, board[9]) +
            "    \n       |       |        ";

    return res;
}

ostream &operator<<(ostream &output, const Board &b)
{
    output << b.toString() << endl;
    return output;
}