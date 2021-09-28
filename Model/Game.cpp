#include "Game.h"
#include "../Data/TrainingData.h"
#include "../Data/OperationSystem.h"
#include <stdexcept>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <vector>

using namespace std;

Game::Game()
{
    srand(time(0));
    set = 0;
}

Game::Game(const Player &p1, const Player &p2, const Board &b)
{
    if(p1.getNotation() == p2.getNotation())
        throw invalid_argument("Notations... they can't be equal.");

    if(p1.getNotation() == '-' || p2.getNotation() == '-')
        throw invalid_argument("Notations... you can't select hyphen as notation.");

    srand(time(0));
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

bool Game::playerTurn()
{
    Player player = whoTurn();

    if(isEnd())
        throw invalid_argument("The game is over."); // operator<< for save results ... File << Game

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
            return false;
        }


        ++set;
        return true;
}

bool Game::computerTurn(bool isAI)
{
    Player player = whoTurn();

    if(isEnd())
        throw invalid_argument("The game is over."); // operator<< for save results ... File << Game

    if(isAI)
    {
        TrainingData &trainingData = TrainingData::getInstance();
        trainingData.open("../NeuralNetwork/realtimeData.mat", false);
        trainingData << this->getAllPossibleNextMoves();
        trainingData.close();
        OperationSystem &operationSystem = OperationSystem::getInstance();
        int pre = stoi(operationSystem.exec("octave ../NeuralNetwork/predictPos"));
        int currentPosition = 0;
        for(int i = 1; i <= 9; ++i)
        {
            if(!getBoard().isFill(i))
                ++currentPosition;
            if(currentPosition == pre)
            {
                currentPosition = i;
                break;
            }
        }
        try
        {
            board.turn(currentPosition, player.getNotation());
        }
        catch (invalid_argument &err)
        {
            return false;
        }
        cout << player.getName() << " turn's: " << currentPosition << endl;
    }
    else // Random choice
    {
        int t = rand() % 9 + 1;
        try
        {
            board.turn(t, player.getNotation());
        }
        catch (invalid_argument &err)
        {
            return false;
        }
        cout << player.getName() << " turn's: " << t << endl;
    }
    ++set;
    return true;
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
        j += 3;
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
        throw runtime_error("Play until the game is over.");

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


vector<vector<double>> Game::getAllPossibleNextMoves()
{
    if(isEnd())
        throw invalid_argument("The game was ended. Try again!");


    string boardRes = board.toString();
    string res = "";
    Player ourPlayer;
    Player theirPlayer;

    if(players.first.getIsAI())
    {
        ourPlayer = players.first;
        theirPlayer = players.second;
    }
    else if(players.second.getIsAI())
    {
        ourPlayer = players.second;
        theirPlayer = players.first;
    }
    else
        throw invalid_argument("Who is AI?");

    vector<double> currentSituation;
    for(int i = 0; i < 11; ++i)
    {
        if(i == 3 || i == 7)
            continue;

        if(boardRes[i] == '-')
            currentSituation.push_back(0);
        else if(boardRes[i] == ourPlayer.getNotation())
            currentSituation.push_back(1);
        else if(boardRes[i] == theirPlayer.getNotation())
            currentSituation.push_back(-1);
    }

    vector<vector<double>> allMovements;
    for(int i = 0; i < 9; ++i)
    {
        if(currentSituation[i] != 0)
            continue;

        currentSituation[i] = 1;
        allMovements.push_back(currentSituation);
        currentSituation[i] = 0;
    }

    return allMovements;
}

string Game::getResult(unsigned int playerNo) const
{
    if(playerNo != 1 && playerNo != 2)
        throw out_of_range("Whose result do you want?");

    if(!isEnd())
        throw invalid_argument("Play until the game is over.");

    string boardRes = board.toString();
    string res = "";

    Player ourPlayer;
    Player theirPlayer;
    if(playerNo == 1)
    {
        ourPlayer = players.first;
        theirPlayer = players.second;
    }
    else
    {
        ourPlayer = players.second;
        theirPlayer = players.first;
    }

    for(int i = 0; i < 11; ++i)
    {
        if(i == 3 || i == 7)
            continue;

        if(boardRes[i] == '-')
            res += "0";
        else if(boardRes[i] == ourPlayer.getNotation())
            res += "1";
        else if(boardRes[i] == theirPlayer.getNotation())
            res += "-1";

        res += " ";
    }

    if(isEqual())
    {
        res += "1 ";
        return res;
    }

    Player winnerPlayer = getWinner();
    if(winnerPlayer.getId() == ourPlayer.getId())
    {
        res += "1 ";
        return res;
    }

    res += "0 ";
    return res;
}

void Game::play()
{
    Player p1;
    cin >> p1;
    Player p2;
    cin >> p2;

    Board b;

    Game game(p1, p2, b);
    while(!game.isEnd())
    {
        try
        {
            Player currentPlayer = game.whoTurn();
            if(!currentPlayer.getIsAI())
            {
                if(game.playerTurn())
                    cout << game.getBoard() << endl;
            }
            else
                if(game.computerTurn(true))
                    cout << game.getBoard() << endl;


        }
        catch (exception &err)
        {
            cout << err.what() << endl;
        }
    }

    try
    {
        try
        {
            cout << game.getWinner().getName() << " wins!" << endl;
        }
        catch (exception &err)
        {
            cout << err.what() << endl;
        }

        /* TrainingData &dataStream = TrainingData::getInstance();
        dataStream.open("../NeuralNetwork/data.mat", true);
        dataStream << game.getResult(1);
        dataStream << game.getResult(2);
        dataStream.close(); */
    }
    catch (exception &err)
    {
        cout << err.what();
    }

}

void Game::trainingData(unsigned int num)
{
    for(int i = 0; i < num; ++i)
    {
        Player p1;
        p1.setName("Ai1");
        p1.setNotation('X');
        p1.setIsAI(true);
        Player p2;
        p2.setName("Ai2");
        p2.setNotation('O');
        p2.setIsAI(true);

        Board b;

        Game game(p1, p2, b);
        while(!game.isEnd())
        {
            try
            {
                if(game.computerTurn(false))
                    cout << game.getBoard() << endl;
            }
            catch (exception &err)
            {
                cout << err.what() << endl;
            }
        }

        try
        {
            try
            {
                cout << game.getWinner().getName() << " wins!" << endl;
            }
            catch (invalid_argument &err)
            {
                cout << "The result is equal!" << endl;
            }

            TrainingData &dataStream = TrainingData::getInstance();
            dataStream.open("../NeuralNetwork/data.mat", true);
            dataStream << game.getResult(1);
            dataStream << game.getResult(2);
            dataStream.close();
        }
        catch (exception &err)
        {
            cout << "Error occurred: " << err.what();
        }
        sleep(1);
    }
}

void Game::randomVsAI(unsigned int num)
{
    Player p1;
    p1.setName("Random");
    p1.setIsAI(true); // Change to setIsComputer
    p1.setNotation('X');
    Player p2;
    p2.setName("AI");
    p2.setIsAI(true); // Change to setIsComputer
    p2.setNotation('O');

    while(num != 0)
    {

        Board b;

        Game game(p1, p2, b);
        while(!game.isEnd())
        {
            try
            {
                Player currentPlayer = game.whoTurn();
                if(currentPlayer.getNotation() == 'X')
                {
                    if(game.computerTurn(false))
                        cout << game.getBoard() << endl;
                }
                else
                    if(game.computerTurn(true))
                        cout << game.getBoard() << endl;


            }
            catch (exception &err)
            {
                cout << err.what() << endl;
            }
        }

        try
        {
            ofstream outputStream("d.mat", ios::app);
            try
            {
                cout << game.getWinner().getName() << " wins!" << endl;
                if(game.getWinner().getName() == "Random")
                    outputStream << game.getWinner().getName() << " " << game.getResult(2) << endl;
                else
                    outputStream << game.getWinner().getName() << endl;
            }
            catch (exception &err)
            {
                cout << err.what() << endl;
            }

            outputStream << "draw\n";
            outputStream.close();
        }
        catch (exception &err)
        {
            cout << err.what();
        }
        --num;
    }

}
