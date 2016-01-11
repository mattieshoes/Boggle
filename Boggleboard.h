#ifndef BOGGLEBOARD_H
#define BOGGLEBOARD_H

#include <vector>
#include <string>
#include <map>
#include "Dict.h"
#include "Bogglesolution.h"

namespace boggle {

// Boggleboard stores the board itself
// Currently, the board can be anything from 1x1 to 8x8
// roll() generates a random board using the dice set specified
// setboard() takes a string and turns it into a board
//    For instance, AECGFJEAERSTPIOR
//    Should be a square number (4, 9, 16, 25, 36, 49, 64)
// usedice()
//    0 -> Old standard boggle dice
//    1 -> New standard boggle dice (changed in the mid 80's)
//    2 -> Big boggle dice (5x5 board)
//    3 -> Boggle deluxe dice (5x5 board)
//  solve() does the initial setup for solving.
//  solve_() is the depth-first recursive function

class Boggleboard {
 public:
  Boggleboard();
  void roll();
  void print();
  bool setboard(std::string s);
  void usedice(int dicemode);
  Bogglesolution solution;

 private:
  void initializedice_(int gameType);
  void initializeoffsets_(int dimension);
  void solve();
  void solve_(std::string current, int boardindex, int dictindex);
  std::vector<std::string> dice;
  char board[100]; 
  Dict dict_;
  int offset_[8];
  bool used[100];
};
} // namespace boggle
#endif
