#include <iostream>

#include "Dict.h"
#include "Dice.h"
#include "Board.h"
#include "Solution.h"

int main() {

    boggle::Dict dict;
    boggle::Dice dice;
    boggle::Board board;
    boggle::Solution solution;

    dice.setDice(boggle::Dice::DiceSet::ORIGINAL);
    solution.setScoringMode(boggle::Solution::ScoringMode::BOGGLE);

    for (int ii = 0; ii < 10000; ii++) {
        board.setBoard(dice.roll());
        board.solve(dict, solution);
    }

    return 0;
}
