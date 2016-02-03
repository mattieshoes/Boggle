#ifndef BOGGLE_SOLUTION_H
#define BOGGLE_SOLUTION_H

#include <vector>
#include <string>
#include <map>

namespace boggle {

class Solution {
 public:
    enum ScoringMode { BOGGLE, BIGBOGGLE, SCRABBLE };
    Solution();
    void addWord(std::string word);
    void setScoringMode(ScoringMode s);
    void initialize();
    void print();
    int points;
    std::vector<std::string> longestword;
    std::map<std::string,int> words;
 private:
    int points_(std::string word);
    std::map<char,int> scrabblevalues;
    ScoringMode scoring;
};
} // namespace boggle
#endif
