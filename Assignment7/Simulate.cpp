#include "Simulate.h"

Simulate::Simulate() {}

Simulate::~Simulate() {}

void Simulate::Menu() {
  int optionChosen;
  int userChoicesSize = 0;
  tableController sim;
  bool isMenu = false;

  while (!isMenu) {
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
      userChoicesSize++;
    }
    else {
      userChoices.insertFront(optionChosen);
      userChoices.removeBack();
    }

    if (optionChosen == 1) {
      sim.printAllStudentInfoById();
    }
    else if (optionChosen == 2) {
      sim.printAllFacultyInfoById();
    }
    else if (optionChosen == 3) {
      int tempStudentID;
      std::cout << "Enter Student ID you wish to find: " << std::endl;
      std::cin >> tempStudentID;
      sim.printStudentInfo(tempStudentID);
    }
    else if (optionChosen == 4) {
      int tempFacultyID;
      std::cin >> tempFacultyID;
      sim.printFacultyInfo(tempFacultyID);
    }
    else if (optionChosen == 5) {
      int tempStudentID;
      std::cin >> tempStudentID;
      sim.printFacultyOfStudent(tempStudentID);
    }
    else if (optionChosen == 6) {
      int tempFacultyID;
      std::cin >> tempFacultyID;
      sim.printFacultyAdvisees(tempFacultyID);
    }
    else if (optionChosen == 7) {
      StudentRecords tempStudent;
      std::cout << "Enter Student ID: " << std::endl;
      int studentID;
      cin >> studentID;
      tempStudent.setStudentID(studentID);

      std::cout << "Enter Student Name: " << std::endl;
      std::string m_studentName;
      std::cin >> m_studentName;
      tempStudent.setStudentName(m_studentName);

      std::cout << "Enter Student Level: " << std::endl;
      std::string studentLevel;
      std::getline(std::cin, studentLevel);
      tempStudent.setStudentLevel(studentLevel);

      std::cout << "Enter Student Major: " << std::endl;
      std::string studentMajor;
      std::getline(std::cin, studentMajor);
      tempStudent.setStudentMajor(studentMajor);

      std::cout << "Enter Student GPA: " << std::endl;
      double m_GPA;
      cin >> m_GPA;
      tempStudent.setStudentGPA(m_GPA);

      std::cout << "Enter Student Faculty ID: " << std::endl;
      int facultyID;
      cin >> facultyID;
      tempStudent.setStudentFacultyAdvisorID(facultyID);

      sim.AddNewStudent(tempStudent);
    }
    else if (optionChosen == 8) {
      std::cout << "Enter student ID you wish to delete: " << std::endl;
      int deleteID;
      cin >> deleteID;
      sim.DeleteStudent(deleteID);
    }
    else if (optionChosen == 9) {
      FacultyRecords tempFaculty;
      std::cout << "Enter Faculty ID: " << std::endl;
      int facultyID;
      cin >> facultyID;
      tempFaculty.setFacultyID(facultyID);

      std::cout << "Enter Faculty Name: " << std::endl;
      std::string facultyName;
      std::cin >> facultyName;
      tempFaculty.setFacultyName(facultyName);

      std::cout << "Enter Faculty Level: " << std::endl;
      std::string facultyLevel;
      std::cin >> facultyLevel;
      tempFaculty.setFacultyLevel(facultyLevel);

      std::cout << "Enter Faculty Department: " << std::endl;
      std::string facultyDepartment;
      std::cin >> facultyDepartment;
      tempFaculty.setFacultyDepartment(facultyDepartment);

      sim.AddFaculty(tempFaculty);
    }
    else if (optionChosen == 10) {
      std::cout << "Enter faculty ID you wish to delete: " << std::endl;
      int deleteID;
      cin >> deleteID;
      sim.DeleteFaculty(deleteID);
    }
    else if (optionChosen == 11) {
      std::cout << "Enter the student ID" << std::endl;
      int studentID;
      cin >> studentID;
      std::cout << "Enter the new advisor ID" << std::endl;
      int advisorID;
      cin >> advisorID;
      sim.ChangeAdvisor(studentID, advisorID);
    }
    else if (optionChosen == 12) {
      std::cout << "Enter the student ID" << std::endl;
      int studentID;
      cin >> studentID;
      std::cout << "Enter the new faculty ID" << std::endl;
      int advisorID;
      cin >> advisorID;
      sim.RemoveStudentFromFaculty(studentID, advisorID);
    }
    else if (optionChosen == 13) {
      sim.Rollback();
    }
    else { // optionChosen == 14
      sim.ExitMenu();
      isMenu = true;
    }
    optionChosen = -1;
  }
}


int main() {
  Simulate s;
  s.Menu();
  return 1;
}
