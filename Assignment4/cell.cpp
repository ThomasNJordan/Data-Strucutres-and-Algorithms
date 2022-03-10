/*
* cell adds functonality for one cell of the Game of Life grid.
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
* Destructor
*/
cell::~cell() {}

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
