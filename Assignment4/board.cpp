/*
Thomas Jordan & Jacqueline Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 4: Game of Life
*/

/*
The board class creates a board for the Game of Life to be played on.
*/

#include "board.h"

/*
Default constructor that defines the row and column values to 0
*/
board::board() {
  setRows(0);
  setCols(0);
}

/*
getRows() returns the numbers of rows in the referenced board
@return: the number of rows
*/
int board::getRows() {
  return m_rows;
}

/*
getCols() returns the numbers of cols in the referenced board
@return: the number of cols
*/
int board::getCols() {
  return m_cols;
}

/*
setRows() sets the number of rows on the board.
@param int rows: the number of rows on the board
*/
void board::setRows(int rows) {
  m_rows = rows;
}

/*
setCols() sets the number of cols on the board.
@param int cols: the number of cols on the board
*/
void board::setCols(int cols) {
  m_cols = cols;
}

/*
getValue() returns the value of the current cell
@param int row: the number of rows on the board
@param int col: the number of cols on the board
@return char: returns the value of the current cell
*/
char board::getValue(int row, int col) {
  return m_board[row][col];
}

/*
setCell() sets the value of the current cell to 'X'
@param int row: the desired row of the cell
@param int col: the desired column of the cell
*/
void board::setCell(int row, int col) {
  m_board[row][col] = 'X';
}

/*
setEmpty() sets the value of the current cell to '-'
@param int row: the desired row of the cell
@param int col: the desired column of the cell
*/
void board::setEmpty(int row, int col) {
  m_board[row][col] = '-';
}

/*
A copy constructor to create a copy of a given board
*/
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

/*
createBoard() makes a new board of a given size of empty values.
@param int row: the number of rows on the board
@param int col: the number of cols on the board
*/
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

/*
printBoard() iterates over the current board and prints each value
*/
void board::printBoard() {
  for(int i = 0; i < getRows(); i++){
    for(int j = 0; j < getCols(); j++){
      cout << m_board[i][j];
    }
    cout << endl;
  }
}

/*
~board() is a destructor that destroys each column in the array, then the row
*/
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
