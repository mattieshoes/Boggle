#include <stdlib.h>
#include <string>
#include <iostream>
#include "Dice.h"

namespace boggle {

std::string Dice::roll() {  

    //roll all dice in order
    std::vector<char> letters;
    for (unsigned int ii=0; ii < dice.size(); ii++)
        letters.push_back(dice[ii][rand()%6]);

    //place the dice randomly
    std::string result = "";
    while (letters.size() > 0) {
        int index = rand() % letters.size();
        result += letters[index];
        letters.erase(letters.begin() + index);
    }
    return result;
}

bool Dice::setDice(DiceSet d) {
    if (d == DiceSet::ORIGINAL) { //original boggle dice, 4x4, pre-1986
        dice.clear();
        dice.push_back("AACIOT");dice.push_back("ABILTY");
        dice.push_back("ABJMOQ");dice.push_back("ACDEMP");
        dice.push_back("ACELRS");dice.push_back("ADENVZ");
        dice.push_back("AHMORS");dice.push_back("BIFORX");
        dice.push_back("DENOSW");dice.push_back("DKNOTU");
        dice.push_back("EEFHIY");dice.push_back("EGKLUY");
        dice.push_back("EGINTV");dice.push_back("EHINPS");
        dice.push_back("ELPSTU");dice.push_back("GILRUW");
        return true;
    } else if (d == DiceSet::UPDATED) { // 4x4 post-1986, less awkward letter distribution
        dice.clear();
        dice.push_back("AAEEGN"); dice.push_back("ABBJOO");
        dice.push_back("ACHOPS"); dice.push_back("AFFKPS");
        dice.push_back("AOOTTW"); dice.push_back("CIMOTU");
        dice.push_back("DEILRX"); dice.push_back("DELRVY");
        dice.push_back("DISTTY"); dice.push_back("EEGHNW");
        dice.push_back("EEINSU"); dice.push_back("EHRTVW");
        dice.push_back("EIOSST"); dice.push_back("ELRTTY");
        dice.push_back("HIMNUQ"); dice.push_back("HLNNRZ");
        return true;
    } else if (d == DiceSet::BIGBOGGLE) { // 5x5 "Big Boggle" set
        dice.clear();
        dice.push_back("AAAFRS"); dice.push_back("AAEEEE"); dice.push_back("AAFIRS");
        dice.push_back("ADENNN"); dice.push_back("AEEEEM"); dice.push_back("AEEGMU");
        dice.push_back("AEGMNN"); dice.push_back("AFIRSY"); dice.push_back("BJKQXZ");
        dice.push_back("CCENST"); dice.push_back("CEIILT"); dice.push_back("CEILPT");
        dice.push_back("CEIPST"); dice.push_back("DDHNOT"); dice.push_back("DHHLOR");
        dice.push_back("DHLNOR"); dice.push_back("DHLNOR"); dice.push_back("EIIITT");
        dice.push_back("EMOTTT"); dice.push_back("ENSSSU"); dice.push_back("FIPRSY");
        dice.push_back("GORRVW"); dice.push_back("IPRRRY"); dice.push_back("NOOTUW");
        dice.push_back("OOOTTU"); 
        return true;
    } else if (d == DiceSet::BOGGLEDELUXE) { // "Boggle Deluxe", 5x5
        dice.clear();
        dice.push_back("AAAFRS"); dice.push_back("AAEEEE"); dice.push_back("AAFIRS");
        dice.push_back("ADENNN"); dice.push_back("AEEEEM"); dice.push_back("AEEGMU");
        dice.push_back("AEGMNN"); dice.push_back("AFIRSY"); dice.push_back("BJKQXZ");
        dice.push_back("CCNSTW"); dice.push_back("CEIILT"); dice.push_back("CEILPT");
        dice.push_back("CEIPST"); dice.push_back("DDLNOR"); dice.push_back("DHHLOR");
        dice.push_back("DHHNOT"); dice.push_back("DHLNOR"); dice.push_back("EIIITT");
        dice.push_back("EMOTTT"); dice.push_back("ENSSSU"); dice.push_back("FIPRSY");
        dice.push_back("GORRVW"); dice.push_back("HIPRRY"); dice.push_back("NOOTUW");
        dice.push_back("OOOTTU"); 
        return true;
    }
    return false;
}

void Dice::print() {
    for (unsigned int ii=0; ii<dice.size(); ii++)
    std::cout << dice[ii] << std::endl;
}

bool Dice::setDice(std::string s) {
  
    if (s.size()%6 != 0)
        return false; 
    dice.clear();
    for (unsigned int ii=0; ii<s.size(); ii += 6)
        dice.push_back(s.substr(ii, 6));
    return true;
}
} // namespace boggle
