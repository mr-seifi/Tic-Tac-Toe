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
    int isEnd() const;
    bool isEqual() const;
    const Player &getWinner() const;
    void playerTurn();

private:
    unsigned int set;
    std::pair<Player, Player> players;
    Board board;
};


#endif //TIC_TAC_TOE_GAME_H