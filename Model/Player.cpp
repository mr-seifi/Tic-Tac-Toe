#include "Player.h"

using namespace std;

unsigned int Player::lastId = 0;

Player::Player()
{
    id = ++lastId;
    setName("Player " + to_string(getId()));
    score = 0;
    setIsAI(false);
}

Player::Player(string name, bool isAI)
{
    id = ++lastId;
    setName(name);
    score = 0;
    setIsAI(isAI)
}