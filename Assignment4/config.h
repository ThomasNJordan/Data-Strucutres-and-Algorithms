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
  void game(char boundry, char pause);
  double randomDensity();
};

#endif
