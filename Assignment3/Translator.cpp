#include "Translator.h"
#include "Model.h"
#include <iostream>

Translator::Translator() {}
Translator::~Translator() {}

string Translator::translateEnglishWord(string word){
  // here check each letter of word
  Model model; // this is object of Model class to use translate functions
  string ret = "";
  for (int i = 0; i < word.size(); ++i) {
    char temp;
    if (word.at(i) == temp) {
      ret += model.translateDoubleCharacter(word.at(i));
    }
    else {
      word.at(i) == temp;
      ret += model.translateStringCharacter(word.at(i));
    }
  }
  return ret;
}

string Translator::translateEnglishSentence(string sent){
  // here extract each word in a sentence and call translateEnglishWord on it
  Translator translator;
  string word = "";
  for (int i = 0; i < sent.size(); ++i) {
    if (sent.at(i) == ' ' || sent.at(i) == '!' || sent.at(i) == '.' || sent.at(i) == '?' || sent.at(i) == ',' || sent.at(i) == ';' || sent.at(i) == ':') {
      return word;
    }
    word += sent.at(i);
  }
  return translator.translateEnglishWord(word);
}
