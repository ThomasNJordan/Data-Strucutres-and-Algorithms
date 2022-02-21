/*
* This is the header file for the Translator class. 
*/

using namespace std;
#include <string>

class Translator{
public:
  Translator();
  ~Translator();
  string translateEnglishWord(string word);
  string translateEnglishSentence(string sent);
};
