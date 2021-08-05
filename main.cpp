#include <iostream>
#include "Model/Game.h"
#include "Data/TrainingData.h"

using namespace std;

int main() {
    // overload comparison operators for player obj (score)

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
            if(game.playerTurn())
                cout << game.getBoard() << endl;
        }
        catch (exception &err)
        {
            cout << err.what() << endl;
        }
    }

    try
    {
        cout << game.getWinner().getName() << " is win!" << endl;
        TrainingData &dataStream = TrainingData::getInstance();
        dataStream.open();
        dataStream << game.getResult(1);
        dataStream.close();
    }
    catch (exception &err)
    {
        cout << err.what();
    }

    return 0;
}