#include "Player.h"

using namespace std;

unsigned int Player::lastId = 0;

Player::Player()
{
    id = ++lastId;
    setName("Player " + to_string(getId()));
    setIsAI(false);
}

Player::Player(string name, bool isAI)
{
    id = ++lastId;
    setName(name);
    setIsAI(isAI);
}

Player::Player(string name, char notation, bool isAI)
{
    id = ++lastId;
    setName(name);
    setNotation(notation);
    setIsAI(isAI);
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

void Player::setIsAI(bool ai)
{
    isAI = ai;
}

bool Player::getIsAI() const
{
    return isAI;
}

void Player::setNotation(char n)
{
    notation = n;
}

char Player::getNotation() const
{
    return notation;
}

istream &operator>>(istream &input, Player &p)
{
    cout << "Enter player" << p.getId() << " name: ";
    string name;
    input >> name;
    p.setName(name);

    string ai;
    cout << "Are you robot? ";
    input >> ai;
    if(ai == "yes")
        p.setIsAI(true);
    else
        p.setIsAI(false);

    char notation;
    cout << "Enter player" << p.getId() << " notation: ";
    input >> notation;
    p.setNotation(notation);

    return input;
}