/*
Thomas Jordan & Jacqueline Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 4: Game of Life
*/

/*
donut.h defines the donut class which defines the behavior for the donut boudnry
condiiton.
*/

#include "classic.h"

class donut : public classic {
public:
  void checkCells();
};
