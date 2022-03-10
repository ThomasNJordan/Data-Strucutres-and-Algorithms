/*
Thomas Jordan & Jacqueline Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 4: Game of Life
*/

/*
* cell adds functonality for one cell on the Game of Life board.
*/

#include "cell.h"

using namespace std;

/*
* Default constructor sets a cell's default state to be empty
*/
cell::cell() {
  m_value = '-';
}

/*
* setVale() sets the value of the cell to the provided value
* @param char value: the value to set cell to
*/
void cell::setValue(char value) {
  m_value = value;
}

/*
* getValue() returns the value of the cell
* @return:
*/
char cell::getValue() {
  return m_value;
}
