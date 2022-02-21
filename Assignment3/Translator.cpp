#include "Translator.h"
#include "Model.h"
#include <iostream>

Translator::Translator() {}
Translator::~Translator() {}

string Translator::translateEnglishWord(string word){
  Model model;
  string ret = "";
  char temp;

  for (int i = 0; i < word.length(); ++i) {
    if (word.at(i) == temp) {
      ret.pop_back();
      ret += model.translateDoubleCharacter(word.at(i));
    }
    else if (word.at(i) != temp){
      ret += model.translateStringCharacter(word.at(i));
    }
    temp = word.at(i);
  }
  return ret;
}

string Translator::translateEnglishSentence(string sent){
  Translator translator;
  string retSentence = "";
  string word = "";
  for (int i = 0; i < sent.size(); ++i) {
    if (sent.at(i) == ' ' || sent.at(i) == '!' || sent.at(i) == '.' || sent.at(i) == '?' || sent.at(i) == ',' || sent.at(i) == ';' || sent.at(i) == ':' || sent.at(i) == '\n') {
      retSentence += translator.translateEnglishWord(word);
      word = "";
    }
    word += sent.at(i);
    if (i == sent.size() - 1) { 
      retSentence += translator.translateEnglishWord(word);
    }
  }
  return retSentence;
}
