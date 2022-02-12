/*
* Parser.cpp first gets the user's input, then it parses that input, printing
* out the number of alphabetic and non-alphabetic characters, the average of
* integers in the string, how many pairs of letters there were, and and the
* number of instances of letters there were in the input string. Parser.cpp
* then outputs this information into output.txt
*/

#include "Parser.h"

/*
setUserInput()
This function prompts the user for a stirng, then saves that string
@param N/A
@return N/A
*/
void Parser::setUserInput() {
  cout << "Enter a string: " << endl;
  getline(cin, m_userString);
}

/*
getAlphabet()
This function counts the number of letters in the user's string.
@param N/A
@return returns an integer alpha
*/
int Parser::getAlphabet() {
  int alpha = 0;
  for (int i = 0; i < m_userString.length(); ++i) {
    if (isalpha(m_userString.at(i))) {
      alpha++;
    }
  }
  return alpha;
}

/*
getNonAlphabet()
This function returns the number of numbers in the user's stirng.
@param N/A
@return returns an integer Nalpha
*/
int Parser::getNonAlphabet() {
  int Nalpha = 0;
  for (int i = 0; i < m_userString.length(); ++i) {
    if (!isalpha(m_userString.at(i))) {
      Nalpha++;
    }
  }
  return Nalpha;
}

/*
getAverage()
This function computes the average of the numbers in the user's input by
casting each number from a stirng to a temporary int value. It then adds this
value to an average variable, which is then divided by the number of times this
operation was performed.
@param N/A
@return returns double avg
*/
double Parser::getAverage() {
  int avg = 0;
  double counter = 0.0;
  int tempVal;
  for (int i = 0; i < m_userString.length(); ++i) {
    if (isdigit(m_userString.at(i))) {
      tempVal = m_userString.at(i) - '0'; // fix for type-casting
      avg += tempVal;
      ++counter;
    }
  }
  return (avg / counter);
}

/*
getPairs()
This function finds how many times a letter is repeated sequentially. It
compares the current character to a temporary value, if they match there is a
sequential pair, then the temporary value is assigned to the next character.
@param N/A
@return returns int numPairs
*/
int Parser::getPairs() {
  int numPairs = 0;
  char tempVal;
  for (int i = 0; i < m_userString.length(); ++i) {
    if (isalpha(m_userString.at(i))) {
      if (m_userString.at(i) == tempVal) {
        numPairs++;
      }
      tempVal = m_userString.at(i);
    }
  }
  return numPairs;
}

/*
toString()
This function formats the output of all the other functions.
@param N/A
@return returns string s.
*/
string Parser::toString() {
  string s = "";
  s += getNumOccurances();
  s += "alphabets:" + to_string(getAlphabet()) + "\n";
  s += "non-alphabets:" + to_string(getNonAlphabet()) + "\n";
  s += "average:" + to_string(getAverage()) + "\n";
  s += "pairs:" + to_string(getPairs());
  return s;
}

/*
printToFile()
This function prints the formated output of toString() into a file named
output.txt
@param N/A
@return N/A
*/
void Parser::printToFile() {
  ofstream newFile;
  newFile.open("output.txt");
  newFile << toString() << "\n";
  newFile.close();
}

/*
getNumOccurances()
This function parses the user's input for the number of times a letter is used.
@param N/A
@return a string ret
*/
string Parser::getNumOccurances() {
  string ret = "";
  for (int i = 0; i < m_userString.length(); i++) {
    switch (tolower(m_userString.at(i))) {
      case 'a':
        m_a++;
        continue;
      case 'b':
        m_b++;
        continue;
      case 'c':
        m_c++;
        continue;
      case 'd':
        m_d++;
        continue;
      case 'e':
        m_e++;
        continue;
      case 'f':
        m_f++;
        continue;
      case 'g':
        m_g++;
        continue;
      case 'h':
        m_h++;
        continue;
      case 'i':
        m_i++;
        continue;
      case 'j':
        m_j++;
        continue;
      case 'k':
        m_k++;
        continue;
      case 'l':
        m_l++;
        continue;
      case 'm':
        m_m++;
        continue;
      case 'n':
        m_n++;
        continue;
      case 'o':
        m_o++;
        continue;
      case 'p':
        m_p++;
        continue;
      case 'q':
        m_q++;
        continue;
      case 'r':
        m_r++;
        continue;
      case 's':
        m_s++;
        continue;
      case 't':
        m_t++;
        continue;
      case 'u':
        m_u++;
        continue;
      case 'v':
        m_v++;
        continue;
      case 'w':
        m_w++;
        continue;
      case 'x':
        m_x++;
        continue;
      case 'y':
        m_y++;
        continue;
      case 'z':
        m_z++;
        continue;
      default:
        continue;
    }
  }
  ret += "a:" + to_string(m_a) + "\n";
  ret += "b:" + to_string(m_b) + "\n";
  ret += "c:" + to_string(m_c) + "\n";
  ret += "d:" + to_string(m_d) + "\n";
  ret += "e:" + to_string(m_e) + "\n";
  ret += "f:" + to_string(m_f) + "\n";
  ret += "g:" + to_string(m_g) + "\n";
  ret += "h:" + to_string(m_h) + "\n";
  ret += "i:" + to_string(m_i) + "\n";
  ret += "j:" + to_string(m_j) + "\n";
  ret += "k:" + to_string(m_k) + "\n";
  ret += "l:" + to_string(m_l) + "\n";
  ret += "m:" + to_string(m_m) + "\n";
  ret += "n:" + to_string(m_n) + "\n";
  ret += "o:" + to_string(m_o) + "\n";
  ret += "p:" + to_string(m_p) + "\n";
  ret += "q:" + to_string(m_q) + "\n";
  ret += "r:" + to_string(m_r) + "\n";
  ret += "s:" + to_string(m_s) + "\n";
  ret += "t:" + to_string(m_t) + "\n";
  ret += "u:" + to_string(m_u) + "\n";
  ret += "v:" + to_string(m_v) + "\n";
  ret += "w:" + to_string(m_w) + "\n";
  ret += "x:" + to_string(m_x) + "\n";
  ret += "y:" + to_string(m_y) + "\n";
  ret += "z:" + to_string(m_z) + "\n";

  return ret;
}
