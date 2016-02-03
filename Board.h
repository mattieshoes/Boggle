#ifndef BOGGLE_BOARD_H
#define BOGGLE_BOARD_H

#include <vector>
#include <string>
#include <map>
#include "Dict.h"
#include "Solution.h"

namespace boggle {

class Board {
  public:
    bool setBoard(std::string s);
    void print();
    void solve(Dict &dict, Solution &solution);

  private:
    void setOffsets(int dimension);
    void search(std::string current, int boardIndex, int dictIndex, 
                Dict &dict, Solution &solution);
    std::vector<char> board; 
    std::vector<bool> used;
    int offset[8];
};
} // namespace boggle
#endif
