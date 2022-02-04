/*
* age.cpp is a program that computes the larget and smallest
* value in an array of size 3. It first prompts the user for
* three values, stores those values in an array, then in a for
* loop, iterate over the array and find the largest and smallest
* value.
*/

#include <iostream>

using namespace std;

int main() {
  int ages[3];

  cout << "Enter the ages of three people: " << endl;
  cin >> ages[0];
  cin >> ages[1];
  cin >> ages[2];

  // sort
  int largest = ages[0];
  int smallest = ages[0];

  for (int i = 0; i < 3; i++) {
    if (ages[i] > largest) {
      largest = ages[i];
    }
    if (ages[i] < smallest) {
      smallest = ages[i];
    }
  }
  cout << "Youngest: " << smallest << endl;
  cout << "Oldest: " << largest << endl;

  return 0;
}
