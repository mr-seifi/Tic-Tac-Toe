#ifndef TIC_TAC_TOE_PLAYER_H
#define TIC_TAC_TOE_PLAYER_H

#include <iostream>
class Player {
public:
    Player();
    explicit Player(std::string, unsigned int = 0, bool = false);
    void setName(std::string);
    std::string getName() const;
    void setScore(unsigned int);
    unsigned int getScore() const;
    void setIsAI(bool);
    bool getIsAI() const;

private:
    std::string name;
    unsigned int score;
    bool isAI;
};


#endif //TIC_TAC_TOE_PLAYER_H
