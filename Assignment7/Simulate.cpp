#include <iostream>
#include "tableController.h"
#include "Simulate.h"

Simulate::Simulate() {

}

Simulate::~Simulate() {

}

Simulate::Menu() {
  int optionChosen;
  Simulate sim;
  DLList<int> userChoices;
  int userChoicesSize = 0;

  while (isMenu) {
    std::cout << "~Menu~" << std::endl;
    std::cout << "1. Print all students and their information (sorted by ascending id #)." << std::endl;
    std::cout << "2. Print all faculty and their information (sorted by ascending id #)." << std::endl;
    std::cout << "3. Find and display student information given the students id." << std::endl;
    std::cout << "4. Find and display faculty information given the faculty id." << std::endl;
    std::cout << "5. Given a student’s id, print the name and info of their faculty advisor." << std::endl;
    std::cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << std::endl;
    std::cout << "7. Add a new student." << std::endl;
    std::cout << "8. Delete a student given the id." << std::endl;
    std::cout << "9. Add a new faculty member." << std::endl;
    std::cout << "10. Delete a faculty member given the id." << std::endl;
    std::cout << "11. Change a student’s advisor given the student id and the new faculty id." << std::endl;
    std::cout << "12. Remove an advisee from a faculty member given the ids." << std::endl;
    std::cout << "13. Rollback." << std::endl;
    std::cout << "14. Exit." << std::endl;
    std::cout << "Choose either 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, or 14." << std::endl;
    std::cin >> optionChosen;

    if (userChoicesSize != 5) {
      userChoices.insertFront(optionChosen);
      userChoices++;
    }
    else {
      userChoices.insertFront(optionChosen);
      userChoices.removeBack();
    }

  }
}
