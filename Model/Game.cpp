#include "Game.h"
#include <stdexcept>

using namespace std;

Game::Game()
{
    set = 1;
}

Game::Game(const Player &p1, const Player &p2, const Board &b)
{
    set = 1;
    players.first = p1;
    players.second = p2;
    board = b;
}

const Player &Game::whoTurn() const
{
    if(set % 2 == 0)
        return players.second;
    return players.first;
}

void Game::playerTurn()
{
    Player player = whoTurn();

}

bool Game::isEnd() const
{

}