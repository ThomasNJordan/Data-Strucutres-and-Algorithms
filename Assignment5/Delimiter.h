/*
Thomas Jordan
2400895
thjordan@chapman.edu
CPSC 350-02
Assignment 5
*/

/*
The header file for the Delimiter class
*/

#ifndef DELIMITER_H
#define DELIMITER_H

#include "AStack.h"
#include <string>
#include <fstream>

class Delimiter : public AStack<char>, public AStack<int> {
public:
  char expectedValue(char givenValue);
  void delimiter(string ProgramFilePath);
};

#endif
