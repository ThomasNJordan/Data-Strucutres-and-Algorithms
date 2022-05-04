/*
Thomas Jordan & Jackie Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 7: Creating a Simple Database System Using BSTs
*/

/*
  This is a main program class file that runs the read student tree from file function from the InputOutput class if the user answers yes to the question.
  It also calls the menu function in the Simulate class to get the database system activated.
  It is the driver class for this assignment by getting the user's response to do the next task.
*/

#include "InputOutput.h"
using namespace std;

int main() {
  InputOutput i;
  int userChoice;
  cout << "Do you want to initalize student and faculty BSTs from files?" << endl;
  cout << "Type 1 for yes or 2 for no." << endl;
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
