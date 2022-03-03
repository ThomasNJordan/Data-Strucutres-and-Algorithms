#include "cell.h"
#include <iostream>
using namespace std;

class board : public cell {
private:
  int rows = 0;
  int cols = 0;
public:
  char** m_board;
  int getRows();
  int getCols();
  board();
  ~board();
  void createBoard(int rows, int cols);
};
