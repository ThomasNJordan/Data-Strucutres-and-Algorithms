/*
* This is the mainprogram which drives Parser.cpp. This program will create a
* Parser object, then call the setUserInput() function and printToFile()
* function on it.
*/

#include "Parser.h"

int main() {
  Parser p;
  p.setUserInput();
  p.printToFile();
  return 0;
}
