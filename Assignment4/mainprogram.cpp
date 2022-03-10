#include <iostream>
#include <string>
#include "config.h"

config conf;  // must be in global scope to destruct properly

int main() {
  char format;
  cout << "Type r for random configuration or f from flat file." << endl;
  cin >> format;
  conf.setup(format);

  char boundry;
  char pause;
  cout << "What kind of boundary mode would you like to run in?\nEnter m for mirror, d for donut, or n for normal: " << endl;
  cin >> boundry;
  cout << "Do you want a brief pause between generations? (y/n):" << endl;
  cin >> pause;
  conf.game(boundry, pause);
  return 0;
}
