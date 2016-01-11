#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "Boggleboard.h"

namespace boggle {

Boggleboard::Boggleboard() {
  solution.setscoringmode(0);
  initializeoffsets_(10);
  srand(time(NULL));
  initializedice_(1);
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

  //drop a random die in each square
  for (int row=0; row < dimension; ++row) {
    for (int col=0; col < dimension; ++col) {
      int index = rand() % letters.size();
      board[row * 10 + col + 11] = letters[index];
      letters.erase(letters.begin()+index);
    }
  }
  solve();
}

void Boggleboard::usedice(int dicemode) {
  initializedice_(dicemode);
  roll();
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
      if (board[index] == 'Q') {
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

bool Boggleboard::setboard(std::string s) {
//TODO: implement
  return false;
}

void Boggleboard::solve() {
  for (int i=0;i<100;i++) {
    if (board[i] == (char)0)
      used[i] = true;
    else
      used[i] = false;
  }
  solution.initialize();

  for (int index = 0; index < 100; ++index) {
    if (board[index] != (char)0) {
      std::string s(1, board[index]);
      int dindex= dict_.getnextindex(0, board[index]);
      if (board[index] == 'Q') {
        s.push_back('U');
        dindex = dict_.getnextindex(dindex, 'U');
      }
      if (dindex > 0) {
        used[index] = true;
        solve_(s, index, dindex);
        used[index] = false;
      }
    }
  }
}

void Boggleboard::solve_(std::string current, int boardindex, int dictindex) {
  if (dict_.isword(dictindex))
    solution.addword(current);
  for (int direction = 0; direction<8; ++direction) {
    int newboardindex = boardindex + offset_[direction];
    if (!used[newboardindex]) {
      char letter = board[newboardindex];
      int newdictindex = dict_.getnextindex(dictindex, letter);
      if (letter == 'Q' && newdictindex > 0)
        newdictindex = dict_.getnextindex(newdictindex, 'U');
      if (newdictindex > 0) {
        used[newboardindex] = true;
        current.push_back(letter);
        if (letter == 'Q')
          current.push_back('U');
        solve_(current, newboardindex, newdictindex);
        current.erase(current.size() - 1);
        if (letter == 'Q')
          current.erase(current.size() -1 );
        used[newboardindex] = false;
      }
    }
  }
}
} // namespace boggle
