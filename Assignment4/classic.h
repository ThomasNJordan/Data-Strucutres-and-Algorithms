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
