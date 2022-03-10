/*
Thomas Jordan & Jacqueline Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 4: Game of Life
*/

#include "cell.h"
#include <iostream>
using namespace std;

class board : public cell {
private:
  int m_rows = 0;
  int m_cols = 0;
public:
  char** m_board;

  int getRows();
  int getCols();
  void setCell(int row, int col);
  void setEmpty(int row, int col);
  void printBoard();
  board(const board& boardToCopy);
  board();
  ~board();
  void setCols(int cols);
  void setRows(int rows);
  void createBoard(int rows, int cols);
  char getValue(int row, int col);
};
