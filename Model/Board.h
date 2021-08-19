#ifndef TIC_TAC_TOE_BOARD_H
#define TIC_TAC_TOE_BOARD_H

#include <iostream>
#include <vector>
class Board {
    friend std::ostream &operator<<(std::ostream&, const Board&);
public:
    Board();
    void turn(unsigned int, char);
    std::string toString() const;
    std::string toOutput() const;
    bool isFill(unsigned int) const;

private:
    std::vector<char> board;
};


#endif //TIC_TAC_TOE_BOARD_H
