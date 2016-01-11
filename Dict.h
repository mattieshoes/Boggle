#ifndef DICT_H
#define DICT_H

#include <vector>
#include <string>
#include <map>

namespace boggle {

struct DictEntry {
  char letter;
  bool isword;
  unsigned int parent;
  std::map<char, unsigned int> children;
  void print();
};

class Dict {
 public:
  Dict();
  Dict(std::string DictionaryFile);
  void print();
  int getnextindex(unsigned int CurrentIndex, char letter);
  bool isword(unsigned int Index);
 private:
  void print_(std::string Prefix, unsigned int Index);
  void initialize_(std::string DictionaryFile);
  void addtodict_(std::string Word, unsigned int WordIndex, unsigned int DictIndex);
  std::vector<DictEntry> dict_;
};

} // namespace boggle
#endif
