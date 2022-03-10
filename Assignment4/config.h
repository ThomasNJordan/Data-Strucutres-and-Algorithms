/*
Thomas Jordan & Jacqueline Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 4: Game of Life
*/

/*
config defines the behavior for controlling the different game elements.
*/

#ifndef CONFIG_H
#define CONFIG_H

#include "donut.h"
#include "mirror.h"

class config : public donut, mirror {
private:
  board randomBoard;
  int numRows;
  int numCols;
public:
  void setup(char format);
  void game(char boundary, char pause);
  double randomDensity();
};

#endif
