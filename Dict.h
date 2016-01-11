#ifndef DICT_H
#define DICT_H

#include <vector>
#include <string>
#include <map>

namespace boggle {

// DictEntry is a simple linked list structure of a letter in a word.
// The Dict class uses it

struct DictEntry {
  char letter;
  bool isword;
  unsigned int parent;
  std::map<char, unsigned int> children;
  void print();
};

// Dict is a linked-list representation of a dictionary in the form of a vector.
// By default, it uses "dict.txt" in the local directory
// print() walks the list and recreates the text version of the dictionary
// getnextindex is used to walk through the list
// isword(unsigned int) tells you whether that node in the list represents a full word.

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
