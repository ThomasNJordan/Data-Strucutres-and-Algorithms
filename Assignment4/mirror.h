/*
Thomas Jordan & Jacqueline Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 4: Game of Life
*/

/*
mirror.h defines the mirror class which defines the behavior for the mirror
boundary condiiton.
*/

#include "classic.h"

class mirror : public classic {
public:
  void checkCells();
};
