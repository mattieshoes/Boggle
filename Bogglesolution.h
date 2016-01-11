#ifndef BOGGLESOLUTION_H
#define BOGGLESOLUTION_H

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
} // namespace boggle
#endif
