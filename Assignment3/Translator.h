using namespace std;
#include <string>

class Translator{
public:
  // implement constructor and destructor
  Translator();
  ~Translator();
  string translateEnglishWord(string word);
  string translateEnglishSentence(string sent);
};
