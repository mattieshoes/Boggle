#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "Boggle.h"

namespace boggle {


//////////////////////////////////////////////////////////////////////////////////////////////////
// Boggle solution implementation
//////////////////////////////////////////////////////////////////////////////////////////////////
Bogglesolution::Bogglesolution() {
  scoringMode_ = 0;
  initialize_();
}

Bogglesolution::Bogglesolution(int scoringMode) {
  scoringMode_ = scoringMode;
  initialize_();
}
void Bogglesolution::initialize_() {
  points = 0;
  longestword.push_back("");
  words.clear();
}

void Bogglesolution::addword(std::string word) {
  auto it = words.find(word);
  if (it != words.end()) {
    words[word] = words[word] + 1;
  } else { //new word
    words[word] = 1;
    if (word.size() > longestword[0].size()) {
      longestword.clear();
      longestword.push_back(word);
    }
    else if (word.size() == longestword[0].size()) {
      longestword.push_back(word);
    }
    switch (scoringMode_) {
      case 0: //standard (1-2=0, 3-4=1, 5=2, 6=3, 7=5, 8+=11)
        if (word.size() > 8)
          points += 11;
        else if (word.size() == 7)
          points += 5;
        else if (words.size() == 6)
          points += 3;
        else if (words.size() == 5)
          points += 2;
        else if (words.size() == 4)
          points += 1;
        else if (words.size() == 3)
          points += 1;
        break;
      case 1: //big boggle (1-3=0, 4=1, 5=2, 6=3, 7=5, 8=11, 9+=2p/letter)
        if (word.size() > 8)
          points += 2 * word.size();
        else if (word.size() == 8)
          points += 11;
        else if (word.size() == 7)
          points += 5;
        else if (words.size() == 6)
          points += 3;
        else if (words.size() == 5)
          points += 2;
        else if (words.size() == 4)
          points += 1;
        break;
      
    }
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// Boggle board implementation
//////////////////////////////////////////////////////////////////////////////////////////////////
Boggleboard::Boggleboard() {
  dictname_ = "dict.txt";
  initializedict_();
  srand(time(NULL));
  roll();
}
Boggleboard::Boggleboard(std::string dictName) {
  dictname_ = dictName;
  initializedict_();
  srand(time(NULL));
  roll();
}


void Boggleboard::roll() {  
  for (int ii=0; ii<100; ++ii)
    board[ii] = (char)0;

  int dimension = 0;
  if (dice.size() == 4)
    dimension = 2;
  else if (dice.size() == 9)
    dimension = 3;
  else if (dice.size() == 16)
    dimension = 4;
  else if (dice.size() == 25)
    dimension = 5;
  else if (dice.size() == 36)
    dimension = 6;
  else if (dice.size() == 49)
    dimension = 7;
  else if (dice.size() == 64)
    dimension = 8;

  std::vector<char> letters;

  //Roll all dice
  for (int ii=0; ii < dimension * dimension; ii++)
    letters.push_back(dice[ii][rand()%6]);

  //drop them in the appropriate squares
  for (int row=0; row < dimension; ++row) {
    for (int col=0; col < dimension; ++col) {
      int index = rand() % letters.size();
      board[row * 10 + col + 11] = letters[index];
      letters.erase(letters.begin()+index);
    }
  }
}

void Boggleboard::initializedice_(int gameType) {
  dice.clear();
  switch (gameType) {
    case 0: //Classic (4x4, pre-1986)
      dice.push_back("AACIOT");dice.push_back("ABILTY");
      dice.push_back("ABJMOQ");dice.push_back("ACDEMP");
      dice.push_back("ACELRS");dice.push_back("ADENVZ");
      dice.push_back("AHMORS");dice.push_back("BIFORX");
      dice.push_back("DENOSW");dice.push_back("DKNOTU");
      dice.push_back("EEFHIY");dice.push_back("EGKLUY");
      dice.push_back("EGINTV");dice.push_back("EHINPS");
      dice.push_back("ELPSTU");dice.push_back("GILRUW");
      break;
    case 1: //New (4x4, post-1986.  less awkward letter distribution)
      dice.push_back("AAEEGN"); dice.push_back("ABBJOO");
      dice.push_back("ACHOPS"); dice.push_back("AFFKPS");
      dice.push_back("AOOTTW"); dice.push_back("CIMOTU");
      dice.push_back("DEILRX"); dice.push_back("DELRVY");
      dice.push_back("DISTTY"); dice.push_back("EEGHNW");
      dice.push_back("EEINSU"); dice.push_back("EHRTVW");
      dice.push_back("EIOSST"); dice.push_back("ELRTTY");
      dice.push_back("HIMNUQ"); dice.push_back("HLNNRZ");
      break;
    case 2: //Big Boggle (5x5)
      dice.push_back("AAAFRS"); dice.push_back("AAEEEE"); dice.push_back("AAFIRS");
      dice.push_back("ADENNN"); dice.push_back("AEEEEM"); dice.push_back("AEEGMU");
      dice.push_back("AEGMNN"); dice.push_back("AFIRSY"); dice.push_back("BJKQXZ");
      dice.push_back("CCENST"); dice.push_back("CEIILT"); dice.push_back("CEILPT");
      dice.push_back("CEIPST"); dice.push_back("DDHNOT"); dice.push_back("DHHLOR");
      dice.push_back("DHLNOR"); dice.push_back("DHLNOR"); dice.push_back("EIIITT");
      dice.push_back("EMOTTT"); dice.push_back("ENSSSU"); dice.push_back("FIPRSY");
      dice.push_back("GORRVW"); dice.push_back("IPRRRY"); dice.push_back("NOOTUW");
      dice.push_back("OOOTTU"); 
      break;
    case 3: //Boggle Deluxe (5x5)
      dice.push_back("AAAFRS"); dice.push_back("AAEEEE"); dice.push_back("AAFIRS");
      dice.push_back("ADENNN"); dice.push_back("AEEEEM"); dice.push_back("AEEGMU");
      dice.push_back("AEGMNN"); dice.push_back("AFIRSY"); dice.push_back("BJKQXZ");
      dice.push_back("CCNSTW"); dice.push_back("CEIILT"); dice.push_back("CEILPT");
      dice.push_back("CEIPST"); dice.push_back("DDLNOR"); dice.push_back("DHHLOR");
      dice.push_back("DHHNOT"); dice.push_back("DHLNOR"); dice.push_back("EIIITT");
      dice.push_back("EMOTTT"); dice.push_back("ENSSSU"); dice.push_back("FIPRSY");
      dice.push_back("GORRVW"); dice.push_back("HIPRRY"); dice.push_back("NOOTUW");
      dice.push_back("OOOTTU"); 
      break;
  }
}

void Boggleboard::print() {
  for (int index=10; index<90; ++index) {
    if (board[index] != (char)0)
      std::cout << board[index];
    if (index % 10 == 9)
      std::cout << std::endl;
    if (index % 10 == 1 && board[index] == (char)0)
      break;
  }
}

void Boggleboard::initializedict_() {
  dict_.clear();
  dict_.push_back(DictEntry());
  dict_[0].isword = false;
  dict_[0].parent = 0;
  dict_[0].letter = (char)0;

  std::ifstream dictfile(dictname_);
  std::string line;
  if (dictfile.is_open()) {
    while (getline(dictfile, line)) {
//      std::cout << line << std::endl;
      if(line.size() > 0) {
        //line.erase(remove(line.begin(), line.end(), '\n'),line.end());
        addtodict_(line, 0, 0);
      }
    } 
    dictfile.close();
  }
  else {
    std::cout << "Can't open dictionary file (" << dictname_ << ")" << std::endl;
    exit(1);
  }
  std::cout << dict_.size() << std::endl;
}

void Boggleboard::addtodict_(std::string word, unsigned int wordindex, unsigned int dictindex) {

  if (wordindex == word.size()) {
    dict_[dictindex].isword = true;
    return;
  }
  if(dict_[dictindex].children.count(word[wordindex]) == 0) {
    dict_.push_back(DictEntry());
    dict_.back().letter = word[wordindex];
    dict_.back().parent = dictindex;
    dict_[dictindex].children[word[wordindex]] = dict_.size() - 1;
    addtodict_(word, wordindex+1, dict_.size() - 1);
  } else { // next letter exists in tree
    addtodict_(word, wordindex+1, dict_[dictindex].children[word[wordindex]]);
  }
}

void Boggleboard::printdict() {
  followdict_("", 0);
}
void Boggleboard::followdict_(std::string s, unsigned int dictindex) {
  if(dict_[dictindex].isword)
    std::cout << s << std::endl;

  std::map<char, unsigned int>::iterator it;
  for(it = dict_[dictindex].children.begin(); it != dict_[dictindex].children.end(); it++) {
    std::string n = s;
    n += it->first;
    followdict_(n, it->second);
  }
}


} // namespace boggle
