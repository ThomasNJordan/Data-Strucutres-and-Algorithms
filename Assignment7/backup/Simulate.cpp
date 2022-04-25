#include <iostream>
#include "Simulate.h"

Simulate::Simulate() {

}

Simulate::~Simulate() {

}

Simulate::Menu() {
  boolean isMenu = true;
  int optionChosen;

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

    if (optionChosen == 1) {

    }
    else if (optionChosen == 2) {

    }
    else if (optionChosen == 3) {

    }
    else if (optionChosen == 4) {

    }
    else if (optionChosen == 5) {

    }
    else if (optionChosen == 6) {

    }
    else if (optionChosen == 7) {

    }
    else if (optionChosen == 8) {

    }
    else if (optionChosen == 9) {

    }
    else if (optionChosen == 10) {

    }
    else if (optionChosen == 11) {

    }
    else if (optionChosen == 12) {

    }
    else if (optionChosen == 13) {

    }
    else { // optionChosen == 14
      break;
    }
  }
}
