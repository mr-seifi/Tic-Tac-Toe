#ifndef TIC_TAC_TOE_GAME_H
#define TIC_TAC_TOE_GAME_H

#include "Player.h"
#include "Board.h"
#include <utility>

class Game {
public:
    Game();
    Game(const Player&, const Player&, const Board&);
    const Player &whoTurn() const;
    int getCurrentResult() const;
    bool isEnd() const;
    bool isEqual() const;
    const Player &getWinner() const;
    bool playerTurn(); // ++PlayerScore
    const Board &getBoard();
    std::string getResult(unsigned int) const;
    std::vector<std::vector<double>> generatePData();
    static void play();
    static void autoPlay(unsigned int); // Change name of this to trainData

private:
    unsigned int set;
    std::pair<Player, Player> players;
    Board board;
};


#endif //TIC_TAC_TOE_GAME_H
