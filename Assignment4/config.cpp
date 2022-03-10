#include "config.h"
#include <fstream>
#include <string>

double config::randomDensity() {
  double r = rand() / double(RAND_MAX);
  return r;
}

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
    randomBoard.printBoard();
  }
}

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
          cout << "\nGen " << i << endl;
        }
        i++;
        m.printBoard();
        m.checkCells();
      }
      cin.get();
      cout << "\nGen " << i << endl;
      m.printBoard();
      cout << "\nStability Achieved" << endl;
      cout << "Press enter to exit. " << endl;
      cin.get();
    }
    if (pause == 'n') {
      int i = 0;
      while (m.isStable() == false) {
        if (i == 0) {
          cout << "Gen 0 (input)" << endl;
        }
        else {
          cout << "\nGen " << i << endl;
        }
        i++;
        m.printBoard();
        m.checkCells();
      }
      cout << "\nGen " << i << endl;
      m.printBoard();
      cout << "\nStability Achieved" << endl;
      cout << "Press enter to exit. " << endl;
      cin.get();
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
          cout << "\nGen " << i << endl;
        }
        i++;
        d.printBoard();
        d.checkCells();
      }
      cin.get();
      cout << "\nGen " << i << endl;
      d.printBoard();
      cout << "\nStability Achieved" << endl;
      cout << "Press enter to exit. " << endl;
      cin.get();
    }
    if (pause == 'n') {
      int i = 0;
      while (d.isStable() == false) {
        if (i == 0) {
          cout << "Gen 0 (input)" << endl;
        }
        else {
          cout << "\nGen " << i << endl;
        }
        i++;
        d.printBoard();
        d.checkCells();
      }
      cout << "\nGen " << i << endl;
      d.printBoard();
      cout << "\nStability Achieved" << endl;
      cout << "Press enter to exit. " << endl;
      cin.get();
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
          cout << "\nGen " << i << endl;
        }
        i++;
        c.printBoard();
        c.checkCells();
      }
      cin.get();
      cout << "\nGen " << i << endl;
      c.printBoard();
      cout << "\nStability Achieved" << endl;
      cout << "Press enter to exit. " << endl;
      cin.get();
    }
    if (pause == 'n') {
      int i = 0;
      while (c.isStable() == false) {
        if (i == 0) {
          cout << "Gen 0 (input)" << endl;
        }
        else {
          cout << "\nGen " << i << endl;
        }
        i++;
        c.printBoard();
        c.checkCells();
      }
      cout << "\nGen " << i << endl;
      c.printBoard();
      cout << "\nStability Achieved" << endl;
      cout << "Press enter to exit. " << endl;
      cin.get();
    }
  }
}
