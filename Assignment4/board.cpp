/*
Thomas Jordan & Jacqueline Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 4: Game of Life
*/

#include "board.h"

board::board() {
  setRows(0);
  setCols(0);
}

int board::getRows() {
  return m_rows;
}

int board::getCols() {
  return m_cols;
}

void board::setRows(int rows) {
  m_rows = rows;
}

void board::setCols(int cols) {
  m_cols = cols;
}

char board::getValue(int row, int col) {
  return m_board[row][col];
}

void board::setCell(int row, int col) {
  m_board[row][col] = 'X';
}

void board::setEmpty(int row, int col) {
  m_board[row][col] = '-';
}

board::board(const board& boardToCopy) {
  this->m_rows = boardToCopy.m_rows;
  this->m_cols = boardToCopy.m_cols;

  m_board = new char* [m_rows]; // first create array of char pointers [char*, char*, ...]
  for(int i=0;i<m_rows;i++){ // then for each char* in the array, convert it into a dynamic array
    m_board[i] = new char[m_cols];
  }

  for (int i = 0; i < m_rows; i++) {
    for (int j = 0; j < m_cols; j++) {
      m_board[i][j]  = boardToCopy.m_board[i][j];
    }
  }
}

void board::createBoard(int rows, int cols) {
  setRows(rows); // declare rows for other functions outside of scope
  setCols(cols);
  m_board = new char* [rows]; // first create array of char pointers [char*, char*, ...]
  for(int i=0;i<rows;i++){ // then for each char* in the array, convert it into a dynamic array
    m_board[i] = new char[cols];
  }

  // at this point board = [[...],[...],[...],[...]], a 2D array
  // here's how you can fill the entire grid with a value
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      m_board[i][j] = '-';
    }
  }
}

void board::printBoard() {
  for(int i = 0; i < getRows(); i++){
    for(int j = 0; j < getCols(); j++){
      cout << m_board[i][j];
    }
    cout << endl;
  }
}

board::~board() {
  // to deallocate the memory, first delete the allocation of each inner array
  // then deallocate the memory of the outer array at the end
  if (getCols() == 0 && getRows() == 0) {
    for(int i = 0; i < getRows(); i++){
      delete[] m_board[i];
    }
    delete[] m_board;
  }
}
