#ifndef BOGGLE_H
#define BOGGLE_H

#include <vector>
#include <string>
#include <map>

namespace boggle {

class Bogglesolution {
 public:
  Bogglesolution();
  void addword(std::string word);
  void setscoringmode(int mode);
  void initialize();
  void print();
  int points;
  std::vector<std::string> longestword;
  std::map<std::string,int> words;
 private:
  int points_(std::string word);
  int scoringmode_;
};

struct DictEntry {
  char letter;
  bool isword;
  unsigned int parent;
  std::map<char, unsigned int> children;
  void print();
};

class Boggleboard {
 public:
  Boggleboard();
  Boggleboard(std::string dictName);
  
  void roll();
  void print();
  void printdict();
  bool setboard(std::string s);
  void usedice(int dicemode);
  void setscoringmode(int scoringmode);
  Bogglesolution solve();

 private:
  void initializedice_(int gameType);
  void initializedict_();
  void initializeoffsets_(int dimension);
  void addtodict_(std::string word, unsigned int wordindex, unsigned int dictindex);
  void followdict_(std::string s, unsigned int dictindex);
  void solve_(std::string current, int boardindex, int dictindex);
  int getnewdictindex_(int currentindex, char letter);

  std::vector<std::string> dice;
  char board[100]; 
  bool used[100];

  std::string dictname_;
  std::vector<DictEntry> dict_;
  int offset_[8];
  Bogglesolution solution_;
  
};

} // namespace boggle
#endif
