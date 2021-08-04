#include <iostream>
#include "Model/Game.h"

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
        game.playerTurn();
    }
    cout << game.getWinner().getName() << " is win!" << endl;

    return 0;
}