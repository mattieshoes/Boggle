#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "Solution.h"

namespace boggle {

Solution::Solution() {
    setScoringMode(ScoringMode::BOGGLE);
    initialize();
}

void Solution::initialize() {
    points = 0;
    longestword.clear();
    longestword.push_back("");
    words.clear();
}

void Solution::addWord(std::string word) {
    std::map<std::string, int>::iterator it = words.find(word);
    if (it == words.end()) {
        int p = points_(word);
        if (p > 0) {
            words[word] = p;
            points += p;
        }
        if (word.size() > longestword[0].size()) {
            longestword.clear();
            longestword.push_back(word);
        }
        else if (word.size() == longestword[0].size()) {
            longestword.push_back(word);
        }
    } 
}

int Solution::points_(std::string word) {
    int points = 0;
    if (scoring == ScoringMode::BOGGLE) { //standard (1-2=0, 3-4=1, 5=2, 6=3, 7=5, 8+=11)
        if (word.size() >= 8)
            points += 11;
        else if (word.size() == 7)
            points += 5;
        else if (word.size() == 6)
            points += 3;
        else if (word.size() == 5)
            points += 2;
        else if (word.size() == 4)
            points += 1;
        else if (word.size() == 3)
            points += 1;
    } else if (scoring == ScoringMode::BIGBOGGLE) { 
               //(1-3=0, 4=1, 5=2, 6=3, 7=5, 8=11, 9+=2p/letter)
        if (word.size() > 8)
            points += 2 * word.size();
        else if (word.size() == 8)
            points += 11;
        else if (word.size() == 7)
            points += 5;
        else if (word.size() == 6)
            points += 3;
        else if (word.size() == 5)
            points += 2;
        else if (word.size() == 4)
            points += 1;
    } else if (scoring == ScoringMode::SCRABBLE) {
        for (unsigned int index = 0; index < word.size(); ++index)
            points += scrabblevalues[word[index]];
    }
    return points;
}
void Solution::setScoringMode(ScoringMode s) {
    scoring = s;
    if(scoring == ScoringMode::SCRABBLE) {
        scrabblevalues['A'] = 1; scrabblevalues['B'] = 3;  scrabblevalues['C'] = 3;
        scrabblevalues['D'] = 2; scrabblevalues['E'] = 1;  scrabblevalues['F'] = 4;
        scrabblevalues['G'] = 2; scrabblevalues['H'] = 4;  scrabblevalues['I'] = 1;
        scrabblevalues['J'] = 8; scrabblevalues['K'] = 5;  scrabblevalues['L'] = 1;
        scrabblevalues['M'] = 3; scrabblevalues['N'] = 1;  scrabblevalues['O'] = 1;
        scrabblevalues['P'] = 3; scrabblevalues['Q'] = 10; scrabblevalues['R'] = 1;
        scrabblevalues['S'] = 1; scrabblevalues['T'] = 1;  scrabblevalues['U'] = 1;
        scrabblevalues['V'] = 4; scrabblevalues['W'] = 4;  scrabblevalues['X'] = 8;
        scrabblevalues['Y'] = 4; scrabblevalues['Z'] = 10; 
    }
}

void Solution::print() {
    std::cout << "Words: " << words.size() << "  Points: " << points << std::endl;
    std::cout << "Longest: " << longestword[0];
    for (unsigned int ii=1; ii<longestword.size(); ii++)
        std::cout << ", " << longestword[ii];
    std::cout << std::endl;
    int counter=0;
    for (std::map<std::string, int>::iterator it = words.begin(); it != words.end(); it++) {
        std::cout << std::setw(12) << it->first << "(" << it->second << ")" ;
        counter++;
        if (counter % 5 == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}
} // namespace boggle
