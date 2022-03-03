#include "board.h"

board::board() {
  rows = 0;
  cols = 0;
}

int board::getRows() {
  return rows;
}

int board::getCols() {
  return cols;
}

void board::createBoard(int rows, int cols) {
  m_board = new char* [rows]; // first create array of char pointers [char*, char*, ...]
  for (int i = 0; i < rows; i++) { // then for each char* in the array, convert it into a dynamic array
    m_board[i] = new char[cols];
  }
  for(int i = 0; i < rows; i++){ // then for each char* in the array, convert it into a dynamic array
    m_board[i] = new char[cols];
  }

  // at this point board = [[...],[...],[...],[...]], a 2D array
  // here's how you can fill the entire grid with a value
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      m_board[i][j] = '-';
    }
  }
  // here's how to print the entire grid
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      cout << m_board[i][j];
    }
    cout << endl;
  }
}

board::~board() {
  // to deallocate the memory, first delete the allocation of each inner array
  // then deallocate the memory of the outer array at the end
  if (getCols() == 0 && getCols() == 0) {
    for(int i = 0; i < getRows(); i++){
      delete[] m_board[i];
    }
  }
  delete[] m_board;
}

/*
int main() {
  board b;
  b.createBoard(5,5);
  return 0;
}
*/
