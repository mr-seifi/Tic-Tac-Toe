#ifndef TIC_TAC_TOE_GAME_H
#define TIC_TAC_TOE_GAME_H

#include "Player.h"
#include "Board.h"
#include <utility>

class Game {
public:
    Game(); // Game constructor
    Game(const Player&, const Player&, const Board&); // Overload Game constructor
    const Player &whoTurn() const; // return player who should turn now
    int getCurrentResult() const; // check the game is over or not and who wins
    bool isEnd() const; // return a bool that indicates the game is over or not
    bool isEqual() const; // return a bool that indicates the game is equal or not
    const Player &getWinner() const; // return winner player at the end of the game
    const Board &getBoard(); // return current board in the middle or end of play
    bool playerTurn(); // wait for player who wants to turn
    bool computerTurn(bool isAI); // wait (immediately) for computer who wants to turn
    static void randomVsAI(unsigned int); // this method is for train data to feed neural network (random vs AI)
    std::vector<std::vector<double>> getAllPossibleNextMoves(); // get all possible at next moves
    std::string getResult(unsigned int) const; // return play result as string type
    static void play(); // play method prepare environment to start the game
    static void trainingData(unsigned int); // this method is for train data to feed neural network (random vs random)

private:
    unsigned int set;
    std::pair<Player, Player> players;
    Board board;
};


#endif //TIC_TAC_TOE_GAME_H
