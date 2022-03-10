/*
Thomas Jordan & Jacqueline Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 4: Game of Life
*/

/*
This is the header file for the cell class. cell.h defines the functions that
make one cell on the board.
*/

#ifndef CELL_H
#define CELL_H

class cell {
private:
  char m_value;
public:
  cell();
  ~cell();
  void setValue(char value);
  char getValue();
};

#endif
