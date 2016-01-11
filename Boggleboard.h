#ifndef BOGGLEBOARD_H
#define BOGGLEBOARD_H

#include <vector>
#include <string>
#include <map>
#include "Dict.h"
#include "Bogglesolution.h"

namespace boggle {

class Boggleboard {
 public:
  Boggleboard();
  Boggleboard(std::string dictName);
  
  void roll();
  void print();
  bool setboard(std::string s);
  void usedice(int dicemode);
  void setscoringmode(int scoringmode);
  Bogglesolution solve();

 private:
  void initializedice_(int gameType);
  void initializeoffsets_(int dimension);
  void solve_(std::string current, int boardindex, int dictindex);

  std::vector<std::string> dice;
  char board[100]; 

  Dict dict_;
  int offset_[8];
  bool used[100];
  Bogglesolution solution_;
  
};

} // namespace boggle
#endif
