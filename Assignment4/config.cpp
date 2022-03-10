/*
Thomas Jordan & Jacqueline Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 4: Game of Life
*/

/*
config.cpp creates the enviroment to run The Game of Life. It handles file-
processing, board starting positions, and boundry conditions.
*/

#include "config.h"
#include <fstream>
#include <string>

/*
randomDensity() finds a value between 0 and 1. We then use this value to
compute the density (the distribution) of the bacteria on the board.
@return double r: the density value
*/
double config::randomDensity() {
  double r = rand() / double(RAND_MAX);
  return r;
}

/*
setup() populates the board. If the user wants a randomly configured board, it
then populates the board at a given density. If the user wants to provide their
own board, setup() parses the given file and creates that board.
@param char format: the desired board setup state
*/
void config::setup(char format) {
  if (format == 'r') {
    int numRows;
    int numCols;
    double density;
    cout << "Enter the number of rows: " << endl;
    cin >> numRows;
    cout << "Enter the number of columns: " << endl;
    cin >> numCols;
    cout << "Enter the density value (between 0 and 1): " << endl;
    cin >> density;

    randomBoard.createBoard(numRows, numCols);
    for (int i = 0; i < randomBoard.getRows(); ++i) {
      for (int j = 0; j < randomBoard.getCols(); ++j) {
        if (randomDensity() <= density) {  //https://stackoverflow.com/questions/9878965/rand-between-0-and-1
          randomBoard.setCell(i,j);
        }
        else {
          randomBoard.setEmpty(i,j);
        }
      }
    }
  }
  if (format == 'f') {
    cout << "Enter filepath of input file: " << endl;
    string filepath;
    cin >> filepath;
    // take in user values from file
    ifstream inFile;
    inFile.open(filepath);
    inFile >> numRows;
    inFile >> numCols;
    randomBoard.createBoard(numRows, numCols);
    char x;
    for (int i = 0; i < randomBoard.getRows(); ++i) {
      for (int j = 0; j < randomBoard.getCols(); ++j) {
        inFile >> x;
        if (x == 'X') {
          randomBoard.setCell(i,j);
        }
        else {
          randomBoard.setEmpty(i,j);
        }
      }
    }
    inFile.close();
  }
}

/*
game() passses the populated board into the appropriate function depending on
the desired boundary condition. If the user wants to print the board to the
terminal, they can, or they can print the entire sequence to a desired out file.
@param char boundry: the boundry condition
@param char pause: outputs the board to the terminal or to a file
*/
void config::game(char boundry, char pause) {
  if (boundry == 'm') {
    mirror m;
    m.createBoard(randomBoard.getRows(), randomBoard.getCols());
    for (int i = 0; i < randomBoard.getRows(); ++i) {
      for (int j = 0; j < randomBoard.getCols(); ++j) {
        if (randomBoard.getValue(i,j) == 'X') {
          m.setCell(i,j);
        }
        if (randomBoard.getValue(i,j) == '-') {
          m.setEmpty(i,j);
        }
      }
    }
    if (pause == 'y') {
      int i = 0;
      while (m.isStable() == false) {
        cin.get();  // pause: https://stackoverflow.com/questions/21257544/c-wait-for-user-input
        if (i == 0) {
          cout << "Gen 0 (input)" << endl;
        }
        else {
          cout << "Gen " << i << endl;
        }
        i++;
        m.printBoard();
        m.checkCells();
      }
      cin.get();
      cout << "Gen " << i << endl;
      m.printBoard();
      cout << "\nStability Achieved" << endl;
      cout << "Press enter to exit. " << endl;
      cin.get();
    }
    if (pause == 'n') {
      string outfilename;
      cout << "Enter the name for the output file: " << endl;
      cin >> outfilename;
      ofstream out_file;
      out_file.open(outfilename);
      int i = 0;
      while (m.isStable() == false) {
        if (i == 0) {
          out_file << "Gen 0 (input)" << endl;
        }
        else {
          out_file << "\nGen " << i << endl;
        }
        i++;

        for(int i = 0; i < m.getRows(); i++){
          for(int j = 0; j < m.getCols(); j++){
            out_file << m.getValue(i,j);
          }
          out_file << endl;
        }
        m.checkCells();
      }
      out_file << "\nGen " << i << endl;
      for(int i = 0; i < m.getRows(); i++){
        for(int j = 0; j < m.getCols(); j++){
          out_file << m.getValue(i,j);
        }
        out_file << endl;
      }
      out_file << "\nStability Achieved" << endl;
      out_file.close();
    }
  }

  if (boundry == 'd') { // donut
    donut d;
    d.createBoard(randomBoard.getRows(), randomBoard.getCols());
    for (int i = 0; i < randomBoard.getRows(); ++i) {
      for (int j = 0; j < randomBoard.getCols(); ++j) {
        if (randomBoard.getValue(i,j) == 'X') {
          d.setCell(i,j);
        }
        if (randomBoard.getValue(i,j) == '-') {
          d.setEmpty(i,j);
        }
      }
    }
    if (pause == 'y') {
      // do file IO and wait for user to type enter (while loop)
      int i = 0;
      // do file IO and wait for user to type enter (while loop)
      while (d.isStable() == false) {
        cin.get();  // pause: https://stackoverflow.com/questions/21257544/c-wait-for-user-input
        if (i == 0) {
          cout << "Gen 0 (input)" << endl;
        }
        else {
          cout << "Gen " << i << endl;
        }
        i++;
        d.printBoard();
        d.checkCells();
      }
      cin.get();
      cout << "Gen " << i << endl;
      d.printBoard();
      cout << "\nStability Achieved" << endl;
      cout << "Press enter to exit. " << endl;
      cin.get();
    }
    if (pause == 'n') {
      string outfilename;
      cout << "Enter the name for the output file: " << endl;
      cin >> outfilename;
      ofstream out_file;
      out_file.open(outfilename);
      int i = 0;
      while (d.isStable() == false) {
        if (i == 0) {
          out_file << "Gen 0 (input)" << endl;
        }
        else {
          out_file << "\nGen " << i << endl;
        }
        i++;
        for(int i = 0; i < d.getRows(); i++){
          for(int j = 0; j < d.getCols(); j++){
            out_file << d.getValue(i,j);
          }
          out_file << endl;
        }
        d.checkCells();
      }
      out_file << "\nGen " << i << endl;
      for(int i = 0; i < d.getRows(); i++){
        for(int j = 0; j < d.getCols(); j++){
          out_file << d.getValue(i,j);
        }
        out_file << endl;
      }
      out_file << "\nStability Achieved" << endl;
      out_file.close();
    }
  }
  if (boundry == 'n') {
    classic c;
    c.createBoard(randomBoard.getRows(), randomBoard.getCols());
    for (int i = 0; i < randomBoard.getRows(); ++i) {
      for (int j = 0; j < randomBoard.getCols(); ++j) {
        if (randomBoard.getValue(i,j) == 'X') {
          c.setCell(i,j);
        }
        if (randomBoard.getValue(i,j) == '-') {
          c.setEmpty(i,j);
        }
      }
    }
    if (pause == 'y') {
      // do file IO and wait for user to type enter (while loop)
      int i = 0;
      // do file IO and wait for user to type enter (while loop)
      while (c.isStable() == false) {
        cin.get();  // pause: https://stackoverflow.com/questions/21257544/c-wait-for-user-input
        if (i == 0) {
          cout << "Gen 0 (input)" << endl;
        }
        else {
          cout << "Gen " << i << endl;
        }
        i++;
        c.printBoard();
        c.checkCells();
      }
      cin.get();
      cout << "Gen " << i << endl;
      c.printBoard();
      cout << "\nStability Achieved" << endl;
      cout << "Press enter to exit. " << endl;
      cin.get();
    }
    if (pause == 'n') {
      string outfilename;
      cout << "Enter the name for the output file: " << endl;
      cin >> outfilename;
      ofstream out_file;
      out_file.open(outfilename);
      int i = 0;
      while (c.isStable() == false) {
        if (i == 0) {
          out_file << "Gen 0 (input)" << endl;
        }
        else {
          out_file << "\nGen " << i << endl;
        }
        i++;
        for(int i = 0; i < c.getRows(); i++){
          for(int j = 0; j < c.getCols(); j++){
            out_file << c.getValue(i,j);
          }
          out_file << endl;
        }
        c.checkCells();
      }
      out_file << "\nGen " << i << endl;
      for(int i = 0; i < c.getRows(); i++){
        for(int j = 0; j < c.getCols(); j++){
          out_file << c.getValue(i,j);
        }
        out_file << endl;
      }
      out_file << "\nStability Achieved" << endl;
      out_file.close();
    }
  }
}
