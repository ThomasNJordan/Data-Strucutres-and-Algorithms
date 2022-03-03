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

int main() {
  char format;
  cout << "Type r for random configuration or f from flat file." << endl;
  cin >> format;
  setup(format); // TODO

  char boundry;
  cout << "What kind of boundry mode would you like to run in?\nEnter m for mirror, d for donut, or n for normal: " << endl;
  cin >> boundry;

  return 0;
}
