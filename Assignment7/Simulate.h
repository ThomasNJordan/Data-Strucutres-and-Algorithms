/*
Thomas Jordan & Jackie Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 7: Creating a Simple Database System Using BSTs
*/

/*
  This is a header file that lists out the public functions that will be used/included in InputOutput.h, InputOutput.cpp, and mainprogram.cpp indirectly and in Simulate.cpp directly.
*/

#include "tableController.h"

class Simulate {
private:
  DLList<int> userChoices;
public:
  void Menu();
};
