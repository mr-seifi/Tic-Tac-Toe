#ifndef TIC_TAC_TOE_BOARD_H
#define TIC_TAC_TOE_BOARD_H

#include <iostream>
#include <vector>
class Board {
public:
    Board();
    void turn(unsigned int, char);
    void show() const;

private:
    std::vector<char> board;
};


#endif //TIC_TAC_TOE_BOARD_H
