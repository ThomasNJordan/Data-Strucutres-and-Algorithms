#include "InputOutput.h"

using namespace std;

int main() {
  InputOutput i;
  int userChoice;
  cout << "Do you want to initalize student and faculty BSTs from files?" << endl;
  cout << "1. Yes\n2. No" << endl;
  cin >> userChoice;
  if (userChoice == 1) {
    cout << "Enter location of Student BST. If it doesn't exist, type DNE" << endl;
    string location;
    if (location != "DNE") {
      i.readStudentTreeFromFile(location);
    }
    cout << "Enter location of Faculty BST. If it doesn't exist, type DNE" << endl;
    string flocation;
    if (flocation != "DNE") {
      i.readFacultyTreeFromFile(flocation);
    }
  }
  Simulate s;
  s.Menu();
  return 1;
}
