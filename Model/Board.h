#ifndef TIC_TAC_TOE_BOARD_H
#define TIC_TAC_TOE_BOARD_H

#include <iostream>
#include <vector>
class Board {
    friend std::ostream &operator<<(std::ostream&, const Board&); // Overload << operator to show board in output stream
public:
    Board(); // Board constructor
    void turn(unsigned int, char); // turn method has 2 arguments, one for position point and another for player notation
    std::string toString() const; // convert board to string
    std::string toOutput() const; // convert board to show that in output stream
    bool isFill(unsigned int) const; // return is map fill or not

private:
    std::vector<char> board;
};


#endif //TIC_TAC_TOE_BOARD_H
