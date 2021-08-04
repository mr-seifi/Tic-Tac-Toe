#ifndef TIC_TAC_TOE_GAME_H
#define TIC_TAC_TOE_GAME_H

#include "Player.h"
#include "Board.h"
#include <utility>

class Game {
public:
    Game();
    Game(Player, Player, Board);
    const Player &whoTurn();
    void turn();

private:
    std::pair<Player, Player> players;
    Board board;
};


#endif //TIC_TAC_TOE_GAME_H
