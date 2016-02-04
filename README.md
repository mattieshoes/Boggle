# Boggle
A boggle solver written in c++

* Can use arbitrary dice -- Original, updated, big boggle, and boggle deluxe dice are hard coded in there as well
* Can use arbitrary dictionaries -- Using sowpods by default.
* Solution class can score using boggle or big boggle rules, or scrabble values
* Can solve arbitrary sized square boggle boards -- for instance, a 32x32 board, whatever

<pre>
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

    board.setBoard(dice.roll());
    board.print();
    board.solve(dict, solution);
    solution.print();

    return 0;
}

Should do something like this:

 I   R   M   U
 U   F   K   O
 G   B   C   D
 H   T   S   A
Words: 56  Points: 57
Longest: CODAS
         ACT(1)        ACTS(1)         ADO(1)         ADS(1)         BUG(1)
         BUR(1)        BURK(1)         CAD(1)        CADS(1)        CAST(1)
         COD(1)        CODA(1)       CODAS(2)        CODS(1)        DACK(1)
         DAS(1)         DOC(1)        DOCK(1)        DOCS(1)         DOM(1)
        DOUK(1)        DOUM(1)         FIR(1)        FIRK(1)        FIRM(1)
        FRUG(1)         FUB(1)        FUBS(1)         FUG(1)         FUR(1)
         GUB(1)        GUBS(1)         GUR(1)         IRK(1)         MOC(1)
        MOCK(1)        MOCS(1)         MOD(1)        MODS(1)         MOU(1)
         OCA(1)        OCAS(1)         ODA(1)        ODAS(1)         ODS(1)
         OUK(1)         RIF(1)         RUB(1)        RUBS(1)         RUG(1)
         SAC(1)        SACK(1)         SAD(1)        SADO(1)        SCAD(1)
         UGH(1)

</pre>
