#include <iostream>
#include <string>

using namespace std;

void setup(char format) { // put this in seperate file
  if (format == 'r') {
    // fill in random values
  }
  if (format == 'f') {
    // take in user values from file
  }
}

void gamemode(char boundry) {
  if (boundry == 'm') {
    // do mirror mode
  }
  if (boundry == 'd') {
    // do donut mode
  }
  if (boundry == 'n') {
    // do normal mode
  }
}

void simulate(char pause) {
  if (pause == 'y') {
    // do file IO and wait for user to type enter (while loop)
  }
  if (pause == 'n') {
    // do file IO without outputting anything to the terminal
  }
}

int main() {
  char format;
  cout << "Type r for random configuration or f from flat file." << endl;
  cin >> format;
  setup(format); // TODO

  char boundry;
  cout << "What kind of boundry mode would you like to run in?\nEnter m for mirror, d for donut, or n for normal: " << endl;
  cin >> boundry;
  gamemode(boundry);

  char pause;
  cout << "Do you want a brief pause between generations? y/n:" << endl;
  cin >> pause;
  simulate(pause);

  return 0;
}
