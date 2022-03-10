/*
Thomas Jordan & Jacqueline Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 4: Game of Life
*/

#ifndef CLASSIC_H
#define CLASSIC_H

#include "board.h"

class classic : public board {
private:
  bool equalGen = false;
public:
  bool isStable();
  void checkCells();
  void setTrue();
};

#endif
