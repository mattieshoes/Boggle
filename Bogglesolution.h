#ifndef BOGGLESOLUTION_H
#define BOGGLESOLUTION_H

#include <vector>
#include <string>
#include <map>

namespace boggle {

// Bogglesolution keeps track of words and the scoring system for those words
// It'll also print a reasonably pretty list.  It does no legality checking, just scorekeeping.

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
  std::map<char,int> scrabblevalues;
  int scoringmode_;
};
} // namespace boggle
#endif
