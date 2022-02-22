/*
* Translator.cpp parses the sentences and/or words from input, then passes then
* parsed data to the corresponding single or double letter function depending
* on context.
*/

#include "Translator.h"
#include "Model.h"
#include <iostream>

/*
* Default constructor
*/
Translator::Translator() {
  cout << "Translator object created!" << endl;
}
/*
* Destructor
*/
Translator::~Translator() {
  cout << "Translator object destroyed!" << endl;
}

/*
* translateEnglishWord
* This function parses characters in a word, then given the context
* of the characters, it calls either the single or double occurance
* function for that scenerio.
* @param string word
* @return string ret
*/
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

/*
* translateEnglishSentence
* This function parses an entire sentence from input, then parses the words from
* the sentence and passes those words into the translateEnglishWord function.
* @param string sent
* @return string retSentence
*/
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
    if (i == sent.size() - 1) { // account for no end punctuation
      retSentence += translator.translateEnglishWord(word);
    }
  }
  return retSentence;
}
