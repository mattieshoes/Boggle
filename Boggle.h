#ifndef BOGGLE_H
#define BOGGLE_H

#include <vector>
#include <string>
#include <map>

namespace boggle {

class Bogglesolution {
 public:
  Bogglesolution();
  Bogglesolution(int scoringMode);
  void addword(std::string word);
  int points;
  std::vector<std::string> longestword;
  std::map<std::string,int> words;
 private:
  void initialize_();
  int scoringMode_;
};

struct DictEntry {
  char letter;
  bool isword;
  unsigned int parent;
  std::map<char, unsigned int> children;
};

class Boggleboard {
 public:
  Boggleboard();
  Boggleboard(std::string dictName);
  
  void roll();
  boggle::Bogglesolution solve();
  void print();
  void printdict();

 private:
  void initializedice_(int gameType);
  void initializedict_();
  void addtodict_(std::string word, unsigned int wordindex, unsigned int dictindex);
  void followdict_(std::string s, unsigned int dictindex);

  std::vector<std::string> dice;
  char board[100]; 

  std::string dictname_;
  std::vector<DictEntry> dict_;
  
};

} // namespace boggle
#endif
