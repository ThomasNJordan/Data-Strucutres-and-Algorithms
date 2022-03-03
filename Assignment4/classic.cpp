#include "classic.h"

char** classic::checkCells() {
  char** newBoard;
  // makes copy of m_board
  for (int i = 0; i < getRows(); i++) {
    for (int j = 0; j < getCols(); j++) {
      newBoard[i][j] = m_board[i][j];
    }
  }
  int counter = 0;
  for (int i = 0; i < getRows(); i++) {
    for (int j = 0; j < getCols(); j++) {
      // Logic after && is to check if cell is out of bounds
      if (i!= getRows()) {
        if (m_board[i+1][j] == 'X') { // foward one
          counter++;
        }
      }
      if (i!=0) {
        if (m_board[i-1][j] == 'X') { // back one
          counter++;
        }
      }
      if (j != getCols()) {
        if (m_board[i][j+1] == 'X') { // up one
          counter++;
        }
      }
      if (j!=0) {
        if (m_board[i][j-1] == 'X') { // down one
          counter++;
        }
      }
      if (i != 0 && j != 0) {
        if (m_board[i-1][j-1] == 'X') {
          counter++;
        }
      }
      if ((i!= getRows() || j!= 0)) {
        if (m_board[i+1][j-1] == 'X') { // bottem right
          counter++;
        }
      }
      if (i!= 0 || j!= getCols()) {
        if (m_board[i-1][j+1] == 'X') { // top left
          counter++;
        }
      }
      if (i!= getRows() || j!= getCols()) {
        if (m_board[i+1][j+1] == 'X') { // top right
          counter++;
        }
      }

      // logic here
      if (counter <= 1) {
        newBoard[i][j] == '-';
      }
      if (counter == 3) {
        newBoard[i][j] == 'X';
      }
      if (counter >= 4) {
        newBoard[i][j] == '-';
      }
      counter = 0;
    }
  }
  return newBoard;
}

classic::~classic() {}

int main() {
  classic c;
  c.createBoard(5,5);
  c.checkCells();
  return 0;
}
