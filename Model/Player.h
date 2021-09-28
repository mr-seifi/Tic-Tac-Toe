#ifndef TIC_TAC_TOE_PLAYER_H
#define TIC_TAC_TOE_PLAYER_H

#include <iostream>
class Player {
    friend std::istream &operator>>(std::istream&, Player&); // Overload >> operator to get player information easier
public:
    Player(); // Player constructor
    explicit Player(std::string, bool = false); // Overload Player constructor
    Player(std::string, char, bool = false); // Overload Player constructor
    unsigned int getId() const; // return player id
    void setName(std::string); // set player id
    std::string getName() const; // return player name
    void setIsAI(bool); // set player is bot or not (T/F)
    bool getIsAI() const; // return player is bot or not (T/F)
    void setNotation(char); // set player notation
    char getNotation() const; // return player notation

private:
    unsigned int id;
    std::string name;
    bool isAI;
    char notation;
    static unsigned int lastId;
};


#endif //TIC_TAC_TOE_PLAYER_H
