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
    const Board &getBoard();
    bool playerTurn(); // ++PlayerScore
    bool computerTurn(bool isAI);
    std::vector<std::vector<double>> getAllPossibleNextMoves(); // Only for AI works.
    std::string getResult(unsigned int) const;
    static void play();
    static void trainingData(unsigned int);

private:
    unsigned int set;
    std::pair<Player, Player> players;
    Board board;
};


#endif //TIC_TAC_TOE_GAME_H
