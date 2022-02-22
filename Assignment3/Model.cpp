/*
* Model.cpp parses individual characters and replaces them with their phonetic
* counterparts. It maintains case by implementing each letter twice. It also
* provides the logic to handle an input if it comes from a double letter.
*/

#include "Model.h"
#include <iostream>
#include <string>

using namespace std;

/*
* Default constructor
*/
Model::Model() {
  cout << "Model object created!" << endl;
}

/*
* Destructor
*/
Model::~Model() {
  cout << "Model object destroyed!" << endl;
}

/*
* translateStringCharacter
* Returns the corresponding phonetic string for the given character.
* @param char c
* @return phonetic string
*/
string Model::translateStringCharacter(char c){
  // Lower case
  if (c == 'b') {
    return "bub";
  }
  if (c == 'c') {
    return "cash";
  }
  if (c == 'd') {
    return "dud";
  }
  if (c == 'f') {
    return "fuf";
  }
  if (c == 'g') {
    return "gug";
  }
  if (c == 'h') {
    return "hash";
  }
  if (c == 'j') {
    return "jay";
  }
  if (c == 'k') {
    return "kuck";
  }
  if (c == 'l') {
    return "lul";
  }
  if (c == 'm') {
    return "mum";
  }
  if (c == 'n') {
    return "num";
  }
  if (c == 'p') {
    return "pub";
  }
  if (c == 'q') {
    return "quack";
  }
  if (c == 'r') {
    return "rug";
  }
  if (c == 's') {
    return "sus";
  }
  if (c == 't') {
    return "tut";
  }
  if (c == 'v') {
    return "vuv";
  }
  if (c == 'w') {
    return "wack";
  }
  if (c == 'x') {
    return "ex";
  }
  if (c == 'y') {
    return "yub";
  }
  if (c == 'z') {
    return "zub";
  }
  // Upper Case
  if (c == 'B') {
    return "Bub";
  }
  if (c == 'C') {
    return "Cash";
  }
  if (c == 'D') {
    return "Dud";
  }
  if (c == 'F') {
    return "Fuf";
  }
  if (c == 'G') {
    return "Gug";
  }
  if (c == 'H') {
    return "Hash";
  }
  if (c == 'J') {
    return "Jay";
  }
  if (c == 'K') {
    return "Kuck";
  }
  if (c == 'L') {
    return "Lul";
  }
  if (c == 'M') {
    return "Mum";
  }
  if (c == 'N') {
    return "Num";
  }
  if (c == 'P') {
    return "Pub";
  }
  if (c == 'Q') {
    return "Quack";
  }
  if (c == 'R') {
    return "Rug";
  }
  if (c == 'S') {
    return "Sus";
  }
  if (c == 'T') {
    return "Tut";
  }
  if (c == 'V') {
    return "Vuv";
  }
  if (c == 'W') {
    return "Wack";
  }
  if (c == 'X') {
    return "Ex";
  }
  if (c == 'Y') {
    return "Yub";
  }
  if (c == 'Z') {
    return "Zub";
  }
  else {
    string ret;
    return ret += c;
  }
}

/*
* translateDoubleCharacter
* Returns the phonetic string if it comes from a double occurance.
* @param char c
* @return phonetic string
*/
string Model::translateDoubleCharacter(char c){
  if (c == 'a' || c == 'e' ||c == 'i' ||c == 'o' ||c == 'u') {
    string ret = "squat";
    return ret += c;
  }
  if (c == 'A' || c ==  'E' ||c == 'U' ||c == 'O' ||c == 'U') {
    string ret = "Squat";
    return ret += tolower(c);
  }
  else if (isupper(c)) {
    string ret = "Squa";
    return ret += tolower(c);
  }
  else {
    string ret = "squa";
    return (ret += c);
  }
}
