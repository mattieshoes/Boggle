#ifndef BOGGLE_DICE_H
#define BOGGLE_DICE_H

#include <vector>
#include <string>

namespace boggle {

class Dice {
 public:
    enum DiceSet { ORIGINAL, UPDATED, BIGBOGGLE, BOGGLEDELUXE };
    std::string roll();
    void print();
    bool setDice(std::string s);
    bool setDice(DiceSet d);
    std::vector<std::string> dice;
};
} // namespace boggle
#endif
