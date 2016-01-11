#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "Bogglesolution.h"

namespace boggle {

Bogglesolution::Bogglesolution() {
  scoringmode_ = 0;
  initialize();
}

void Bogglesolution::initialize() {
  points = 0;
  longestword.clear();
  longestword.push_back("");
  words.clear();
}

void Bogglesolution::addword(std::string word) {
  std::map<std::string, int>::iterator it = words.find(word);
  if (it == words.end()) {
    int p = points_(word);
    if(p > 0) {
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

int Bogglesolution::points_(std::string word) {
  int points = 0;
  switch (scoringmode_) {
    case 0: //standard (1-2=0, 3-4=1, 5=2, 6=3, 7=5, 8+=11)
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
      break;
    case 1: //big boggle (1-3=0, 4=1, 5=2, 6=3, 7=5, 8=11, 9+=2p/letter)
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
      break;
  }
  return points;
}
void Bogglesolution::setscoringmode(int scoringmode) {
  scoringmode_ = scoringmode;
}

void Bogglesolution::print() {
  std::cout << "Words: " << words.size() << "  Points: " << points << std::endl;
  std::cout << "Longest: " << longestword[0];
  for (unsigned int ii=1; ii<longestword.size(); ii++) {
    std::cout << ", " << longestword[ii];
  }
  std::cout << std::endl;

  int counter=0;
  for(std::map<std::string, int>::iterator it = words.begin(); it != words.end(); it++) {
    std::cout << std::setw(20) << it->first << "(" << it->second << ")" ;
    counter++;
    if(counter % 4 == 0)
      std::cout << std::endl;
    
  }
  std::cout << std::endl;
}
} // namespace boggle
