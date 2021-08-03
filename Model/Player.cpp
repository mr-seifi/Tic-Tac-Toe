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

unsigned int Player::getId() const
{
    return id;
}

void Player::setName(string n)
{
    name = n;
}

string Player::getName() const
{
    return name;
}

void Player::scoreIncrement()
{
    score += 100;
}

unsigned int Player::getScore() const
{
    return score;
}

void Player::setIsAI(bool ai)
{
    isAI = ai;
}

bool Player::getIsAI() const
{
    return isAI;
}