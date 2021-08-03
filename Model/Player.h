#ifndef TIC_TAC_TOE_PLAYER_H
#define TIC_TAC_TOE_PLAYER_H

#include <iostream>
class Player {
public:
    Player();
    explicit Player(std::string, bool = false);
    unsigned int getId() const;
    void setName(std::string);
    std::string getName() const;
    void scoreIncrement();
    unsigned int getScore() const;
    void setIsAI(bool);
    bool getIsAI() const;

private:
    unsigned int id;
    std::string name;
    unsigned int score;
    bool isAI;
    static unsigned int lastId;
};


#endif //TIC_TAC_TOE_PLAYER_H