#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "Boggle.h"

namespace boggle {


void DictEntry::print() {
  std::cout << "\tletter: " << letter << std::endl;
  std::cout << "\tisword: " << isword << std::endl;
  std::cout << "\tparent: " << parent << std::endl;
  for (std::map<char, unsigned int>::iterator it=children.begin(); it != children.end(); it++) {
    std::cout << "\t\tChild: " << it->first << " " << it->second << std::endl;
  }

}

//////////////////////////////////////////////////////////////////////////////////////////////////
// Boggle solution implementation
//////////////////////////////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////////////////////////////
// Boggle board implementation
//////////////////////////////////////////////////////////////////////////////////////////////////
Boggleboard::Boggleboard() {
  solution_.setscoringmode(0);
  initializeoffsets_(10);
  dictname_ = "dict.txt";
  initializedict_();
  srand(time(NULL));
  initializedice_(1);
  roll();
}
Boggleboard::Boggleboard(std::string dictName) {
  solution_.setscoringmode(0);
  initializeoffsets_(10);
  dictname_ = dictName;
  initializedict_();
  srand(time(NULL));
  roll();
}

void Boggleboard::initializeoffsets_(int dimension) {
  offset_[0] = -dimension - 1;
  offset_[1] = -dimension;
  offset_[2] = -dimension+1;
  offset_[3] = -1;
  offset_[4] = 1;
  offset_[5] = dimension-1;
  offset_[6] = dimension;
  offset_[7] = dimension+1;
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

void Boggleboard::usedice(int dicemode) {
  initializedice_(dicemode);
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
    if (board[index] != (char)0) {
      if(board[index] == 'Q') {
        std::cout << " Qu ";
      } else {
        std::cout << " " << board[index] << "  ";
      }
    }
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
    while (getline(dictfile, line))
      if(line.size() > 0) {
        if (line[line.size() - 1] == '\r')
          line.erase(line.size() - 1);
        addtodict_(line, 0, 0);
      }
    dictfile.close();
  }
  else {
    std::cout << "Can't open dictionary file (" << dictname_ << ")" << std::endl;
    exit(1);
  }
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

void Boggleboard::setscoringmode(int scoringmode) {
  solution_.setscoringmode(scoringmode);
}

bool Boggleboard::setboard(std::string s) {
//TODO: implement
  return false;
}

Bogglesolution Boggleboard::solve() {
//std::cout << "solve called" << std::endl;
  for (int i=0;i<100;i++) {
    if (board[i] == (char)0)
      used[i] = true;
    else
      used[i] = false;
  }
  solution_.initialize();

  for (int index = 0; index < 100; ++index) {
    if(board[index] != (char)0) {
      std::string s(1, board[index]);
      int dindex= getnewdictindex_(0, board[index]);
      if (board[index] == 'Q') {
        s.push_back('U');
        dindex = getnewdictindex_(dindex, 'U');
      }
      if(dindex > 0) {
        used[index] = true;
        solve_(s, index, dindex);
        used[index] = false;
      }
    }
  }
  return solution_;
}

void Boggleboard::solve_(std::string current, int boardindex, int dictindex) {
  if(dict_[dictindex].isword) {
    solution_.addword(current);
  } else {
    //dict_[dictindex].print();
  }
  for (int direction = 0; direction<8;direction++) {
    int newboardindex = boardindex + offset_[direction];
    if(!used[newboardindex]) {
      char letter = board[newboardindex];
      int newdictindex = getnewdictindex_(dictindex, letter);
      if(letter == 'Q' && newdictindex > 0)
        newdictindex = getnewdictindex_(newdictindex, 'U');
      if(newdictindex > 0) {
        used[newboardindex] = true;
        current.push_back(letter);
        if (letter == 'Q')
          current.push_back('U');
        solve_(current, newboardindex, newdictindex);
        current.erase(current.size() - 1);
        if(letter == 'Q')
          current.erase(current.size() -1 );
        used[newboardindex] = false;
      }
    }
  }
}

int Boggleboard::getnewdictindex_(int currentindex, char letter) {
  std::map<char, unsigned int>::iterator it = dict_[currentindex].children.find(letter);
  if(it == dict_[currentindex].children.end()) {
    return 0;
  }
  return it->second;
}
} // namespace boggle
