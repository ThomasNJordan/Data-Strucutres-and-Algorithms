#include "mirror.h"

void mirror::checkCells() {
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
          counter = counter + 2;
        }
        if (m_board[i+1][j+1] == 'X') {
          counter++;
        }
        if (m_board[i][j+1] == 'X') {
          counter = counter + 2;
        }
        if (m_board[i][j] == 'X') {
          counter = counter + 3;
        }
      }
      else if (i == 0 && j == getCols() -1) { // top right
        if (m_board[i][j-1] == 'X') {
          counter = counter + 2;
        }
        if (m_board[i+1][j-1] == 'X') {
          counter++;
        }
        if (m_board[i+1][j] == 'X') {
          counter = counter + 2;
        }
        if (m_board[i][j] == 'X') {
          counter = counter + 3;
        }
      }
      else if (i == getRows() -1 && j == 0) { // bottom left
        if (m_board[i-1][j] == 'X') {
          counter = counter + 2;
        }
        if (m_board[i-1][j+1] == 'X') {
          counter++;
        }
        if (m_board[i][j+1] == 'X') {
          counter = counter + 2;
        }
        if (m_board[i][j] == 'X') {
          counter = counter + 3;
        }
      }
      else if (i == getRows() - 1 && j == getCols() - 1) {  // bottom right
        if (m_board[i][j-1] == 'X') {
          counter = counter + 2;
        }
        if (m_board[i-1][j-1] == 'X') {
          counter++;
        }
        if (m_board[i-1][j] == 'X') {
          counter = counter + 2;
        }
        if (m_board[i][j] == 'X') {
          counter = counter + 3;
        }
      }
      else if (i == 0) {  // top row
        if (m_board[i+1][j] == 'X') {
          counter = counter + 2;
        }
        if (m_board[i][j-1] == 'X') {
          counter = counter + 2;
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
        if (m_board[i][j] == 'X') {
          counter++;
        }
      }
      else if (i == getRows()-1) { // bottom row
        if (m_board[i][j-1] == 'X') {
          counter = counter + 2;
        }
        if (m_board[i][j+1] == 'X') {
          counter = counter + 2;
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
        if (m_board[i][j] == 'X') {
          counter++;
        }
      }
      else if (j == 0) {  // left column
        if (m_board[i-1][j] == 'X') {
          counter = counter + 2;
        }
        if (m_board[i+1][j] == 'X') {
          counter = counter + 2;
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
        if (m_board[i][j] == 'X') {
          counter++;
        }
      }
      else if (j == getCols() -1) {  // right column
        if (m_board[i-1][j] == 'X') {
          counter = counter + 2;
        }
        if (m_board[i+1][j] == 'X') {
          counter = counter + 2;
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
        if (m_board[i][j] == 'X') {
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
