#include "Game.h"
#include <stdexcept>

using namespace std;

Game::Game()
{
    set = 0;
}

Game::Game(const Player &p1, const Player &p2, const Board &b)
{
    if(p1.getNotation() == p2.getNotation())
        throw invalid_argument("Notations... they can't be equal.");

    for(int i = 0; i < 11; ++i)
        if(board.toString()[i] != '-' && board.toString()[i] != '/')
            throw invalid_argument("Your board should be empty.");

    set = 0; // Change this name
    players.first = p1;
    players.second = p2;
    board = b;
}

const Player &Game::whoTurn() const
{
    if(set % 2 == 0)
        return players.first;
    return players.second;
}

void Game::playerTurn()
{
    Player player = whoTurn();

    if(isEnd())
        throw invalid_argument("The game is over."); // operator<< for save results ... File << Game

    if(!player.getIsAI())
    {
        int t;
        cout << player.getName() << " turn's: ";
        cin >> t;
        try
        {
            board.turn(t, player.getNotation());
        }
        catch (invalid_argument &err)
        {
            cout << "You can't do this because position " << t << " isn't empty."
            << " Try again!" << endl;
            return;
        }
    }

    ++set;
}

int Game::getCurrentResult() const
{
    string result = board.toString();

    for(int i = 0, j = 0; i < 3; ++i)
    {
        if(result[0 + i] == result[4 + i] && result[4 + i] == result[8 + i] && result[i] != '-') // X--/X--/X--
            return i;
        if(result[i + j] == result[i + j + 1] && result[i + j + 1] == result[i + j + 2] && result[i + j] != '-') // XXX/---/---
            return i + j;
        if(i == 0) j += 3; else j += 2;
    }

    if((result[0] == result[5] && result[5] == result[10] && result[5] != '-')
    || (result[2] == result[5] && result[5] == result[8] && result[5] != '-')) // X--/-X-/--X
        return 5;

    if(set == 9)
        return 11; // End -> Equal

    return -1; // Not end
}

bool Game::isEnd() const
{
    if(getCurrentResult() == -1)
        return false;
    return true;
}

bool Game::isEqual() const
{
    if(getCurrentResult() == 11)
        return true;
    return false;
}

const Player &Game::getWinner() const
{
    if(!isEnd())
        throw invalid_argument("Play until the game is over.");

    if(isEqual())
        throw invalid_argument("The result is equal.");

    if(board.toString()[getCurrentResult()] == players.first.getNotation())
        return players.first;
    return players.second;
}

const Board &Game::getBoard()
{
    return board;
}