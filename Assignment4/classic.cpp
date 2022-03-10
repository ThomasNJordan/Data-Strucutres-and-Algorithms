/*
Thomas Jordan & Jacqueline Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 4: Game of Life
*/

/*
classic.cpp defines the behavior for the normal variation of the Game of Life.
*/

#include "classic.h"

/*
Mutator to set equalGen to true. It's true if two generations are equal.
*/
void classic::setTrue() {
  equalGen = true;
}

/*
checkCells() iterates over each value in the given array, then checks that
value's neighbors. If the cell has 1 neighbor, it dies. If it has 2, it remains
the same. If there are 3 neighbors, the cell grows a bacteria. If it has 4
neighbors it dies. checkCells() then checks if the current generation is
equal to the previous generation.
*/
void classic::checkCells() {
  board retBoard;
  retBoard.createBoard(getRows(), getCols());

  for (int i = 0; i < getRows(); i++) {
    for (int j = 0; j < getCols(); j++) {
      retBoard.setEmpty(i, j);
    }
  }
  int counter = 0;
  for (int i = 0; i < getRows(); ++i) {
    for (int j = 0; j < getCols(); ++j) {
      // Logic after && is to check if cell is out of bounds
      if (i == 0 && j == 0) { // top left
        if (m_board[i+1][j] == 'X') {
          counter++;
        }
        if (m_board[i+1][j+1] == 'X') {
          counter++;
        }
        if (m_board[i][j+1] == 'X') {
          counter++;
        }
      }
      else if (i == 0 && j == getCols() -1) { // top right
        if (m_board[i][j-1] == 'X') {
          counter++;
        }
        if (m_board[i+1][j-1] == 'X') {
          counter++;
        }
        if (m_board[i+1][j] == 'X') {
          counter++;
        }
      }
      else if (i == getRows() -1 && j == 0) { // bottom left
        if (m_board[i-1][j] == 'X') {
          counter++;
        }
        if (m_board[i-1][j+1] == 'X') {
          counter++;
        }
        if (m_board[i][j+1] == 'X') {
          counter++;
        }
      }
      else if (i == getRows() - 1 && j == getCols() - 1) {  // bottom right
        if (m_board[i][j-1] == 'X') {
          counter++;
        }
        if (m_board[i-1][j-1] == 'X') {
          counter++;
        }
        if (m_board[i-1][j] == 'X') {
          counter++;
        }
      }
      else if (i == 0) {  // top row
        if (m_board[i+1][j] == 'X') {
          counter++;
        }
        if (m_board[i][j-1] == 'X') {
          counter++;
        }
        if (m_board[i][j+1] == 'X') {
          counter++;
        }
        if (m_board[i+1][j-1] == 'X') {
          counter++;
        }
        if (m_board[i+1][j+1] == 'X') {
          counter++;
        }
      }
      else if (i == getRows()-1) { // bottom row
        if (m_board[i][j-1] == 'X') {
          counter++;
        }
        if (m_board[i][j+1] == 'X') {
          counter++;
        }
        if (m_board[i-1][j-1] == 'X') {
          counter++;
        }
        if (m_board[i-1][j] == 'X') {
          counter++;
        }
        if (m_board[i-1][j+1] == 'X') {
          counter++;
        }
      }
      else if (j == 0) {  // left column
        if (m_board[i-1][j] == 'X') {
          counter++;
        }
        if (m_board[i+1][j] == 'X') {
          counter++;
        }
        if (m_board[i-1][j+1] == 'X') {
          counter++;
        }
        if (m_board[i][j+1] == 'X') {
          counter++;
        }
        if (m_board[i+1][j+1] == 'X') {
          counter++;
        }
      }
      else if (j == getCols() -1) {  // right column
        if (m_board[i-1][j] == 'X') {
          counter++;
        }
        if (m_board[i+1][j] == 'X') {
          counter++;
        }
        if (m_board[i-1][j-1] == 'X') {
          counter++;
        }
        if (m_board[i][j-1] == 'X') {
          counter++;
        }
        if (m_board[i+1][j-1] == 'X') {
          counter++;
        }
      }
      else {  // every other cell
        if (m_board[i-1][j] == 'X') {
          counter++;
        }
        if (m_board[i+1][j] == 'X') {
          counter++;
        }
        if (m_board[i][j-1] == 'X') {
          counter++;
        }
        if (m_board[i][j+1] == 'X') {
          counter++;
        }
        if (m_board[i-1][j-1] == 'X') {
          counter++;
        }
        if (m_board[i-1][j+1] == 'X') {
          counter++;
        }
        if (m_board[i+1][j-1] == 'X') {
          counter++;
        }
        if (m_board[i+1][j+1] == 'X') {
          counter++;
        }
      }

      // logic here
      if (counter <= 1) {
        retBoard.setEmpty(i,j);
      }
      if (counter == 2) {
        if (m_board[i][j] == 'X') {
          retBoard.setCell(i,j);
        }
        else {
          retBoard.setEmpty(i,j);
        }
      }
      if (counter == 3) {
        retBoard.setCell(i,j);
      }
      if (counter >= 4) {
        retBoard.setEmpty(i,j);
      }
      counter = 0;
    }
  }
  int diffCounter = 0;
  for (int i = 0; i < getRows(); ++i) {
    for (int j = 0; j < getCols(); ++j) {
      if (retBoard.getValue(i,j) != m_board[i][j]) {
        diffCounter++;
      }
    }
  }
  if (diffCounter == 0) {
    setTrue();
  }

  for (int i = 0; i < getRows(); ++i) {
    for (int j = 0; j < getCols(); j++) {
      m_board[i][j] = retBoard.getValue(i,j);
    }
  }
}

/*
isStable() checks if the board is stable. It first checks if the board is empty.
It then checks if the previous generation was equal to the current generation.
*/
bool classic::isStable() {
  int counter = 0;
  // check if empty
  for (int i = 0; i < getRows()-1; ++i) {
    for (int j = 0; j < getCols()-1; j++) {
      if (m_board[i][j] == 'X') {
        counter++;
      }
    }
  }
  if (equalGen == true) {
    return true;
  }

  return false;
}
