#ifndef BOARD_H
#define BOARD_H

#include "board.h"

class classic : public board {
public:
  char** newBoard;
  char** checkCells();
  ~classic();
};

#endif
