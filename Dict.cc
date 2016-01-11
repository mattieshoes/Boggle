#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "Dict.h"

namespace boggle {

void DictEntry::print() {
  std::cout << "\tletter: " << letter << std::endl;
  std::cout << "\tisword: " << isword << std::endl;
  std::cout << "\tparent: " << parent << std::endl;
  for (std::map<char, unsigned int>::iterator it=children.begin(); it != children.end(); it++) {
    std::cout << "\t\tChild: " << it->first << " " << it->second << std::endl;
  }
}

Dict::Dict() {
  initialize_("dict.txt");
}
Dict::Dict(std::string DictionaryPath) {
  initialize_(DictionaryPath);
}

bool Dict::isword(unsigned int Index) {
  return dict_[Index].isword; 
}

void Dict::initialize_(std::string DictionaryFile) {
  dict_.clear();
  dict_.push_back(DictEntry());
  dict_[0].isword = false;
  dict_[0].parent = 0;
  dict_[0].letter = (char)0;

  std::ifstream dictfile(DictionaryFile);
  std::string line;
  if (dictfile.is_open()) {
    while (getline(dictfile, line))
      if (line.size() > 0) {
        if (line[line.size() - 1] == '\r')
          line.erase(line.size() - 1);
        addtodict_(line, 0, 0);
      }
    dictfile.close();
  }
  else {
    std::cout << "Can't open dictionary file (" << DictionaryFile << ")" << std::endl;
    exit(1);
  }
}

void Dict::addtodict_(std::string word, unsigned int wordindex, unsigned int dictindex) {
  if (wordindex == word.size()) {
    dict_[dictindex].isword = true;
    return;
  }
  if (dict_[dictindex].children.count(word[wordindex]) == 0) {
    dict_.push_back(DictEntry());
    dict_.back().letter = word[wordindex];
    dict_.back().parent = dictindex;
    dict_[dictindex].children[word[wordindex]] = dict_.size() - 1;
    addtodict_(word, wordindex+1, dict_.size() - 1);
  } else { // next letter exists in tree
    addtodict_(word, wordindex+1, dict_[dictindex].children[word[wordindex]]);
  }
}

void Dict::print() {
  print_("", 0);
}

void Dict::print_(std::string Prefix, unsigned int Index) {
  if (dict_[Index].isword)
    std::cout << Prefix << std::endl;
  std::map<char, unsigned int>::iterator it;
  for (it = dict_[Index].children.begin(); it != dict_[Index].children.end(); it++) {
    Prefix.push_back(it->first);
    print_(Prefix, it->second);
    Prefix.erase(Prefix.size()-1);
  }
}

int Dict::getnextindex(unsigned int currentindex, char letter) {
  std::map<char, unsigned int>::iterator it = dict_[currentindex].children.find(letter);
  if (it == dict_[currentindex].children.end())
    return 0;
  return it->second;
}
} // namespace boggle
