/*
Thomas Jordan & Jackie Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 7: Creating a Simple Database System Using BSTs
*/

/*
  This is the InputOutput class that provides the functionality of writing and reading binary search trees to files.
*/
#include "InputOutput.h"

/*
  Write Class File Function
  The write class file function allows the user to create a new student or faculty member based on answering a series of questions.
  @param std::string pathToFile: name of the file to write the student's or faculty member's information to
*/
void InputOutput::writeClassFile(std::string pathToFile) {
  std::ofstream class_obj;
  class_obj.open(pathToFile, std::ios::app);
  int choice;
  std::cout << "Would you like to create a new student or faculty member: " << std::endl;
  std::cout << "1. Student\n2. Faculty" << std::endl;
  std::cin >> choice;
  if (choice == 1) {
    StudentRecords tempStudent;
    std::cout << "Enter Student ID: " << std::endl;
    int studentID;
    std::cin >> studentID;
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
    std::cin >> m_GPA;
    tempStudent.setStudentGPA(m_GPA);

    std::cout << "Enter Student Faculty ID: " << std::endl;
    int facultyID;
    std::cin >> facultyID;
    tempStudent.setStudentFacultyAdvisorID(facultyID);

    class_obj.write((char*)&tempStudent, sizeof(tempStudent));
  }
  else if (choice == 2) {
    FacultyRecords tempFaculty;
    std::cout << "Enter Faculty ID: " << std::endl;
    int facultyID;
    std::cin >> facultyID;
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

    class_obj.write((char*)&tempFaculty, sizeof(tempFaculty));
  } else {
    std::cout << "Invalid chocie" << std::endl;
  }
}

/*
  Write Student Tree To File Function
  The write student tree to file function writes the student binary search tree into the file the user has requested after opening the file.
  @param BST<StudentRecords> m_StudentRecordsTree, std::string pathToFile
*/
void InputOutput::writeStudentTreeToFile(BST<StudentRecords> m_StudentRecordsTree, std::string pathToFile) {
  std::ofstream class_obj;
  class_obj.open(pathToFile, std::ios::app);
  class_obj.write((char*)&m_StudentRecordsTree, sizeof(m_StudentRecordsTree));
}

/*
  Write Faculty Tree To File Function
  The write faculty tree to file function writes the faculty binary search tree into the file the user has requested after opening the file.
  @param BST<FacultyRecords> m_FacultyRecordsTree, std::string pathToFile
*/
void InputOutput::writeFacultyTreeToFile(BST<FacultyRecords> m_FacultyRecordsTree, std::string pathToFile) {
  std::ofstream class_obj;
  class_obj.open(pathToFile, std::ios::app);
  class_obj.write((char*)&m_FacultyRecordsTree, sizeof(m_FacultyRecordsTree));
}

/*
  Read Student Tree From File Function
  The read student tree from file function reads the student binary search tree from the file the user has requested after opening the file.
  @param std::string pathToFile
*/
BST<StudentRecords> InputOutput::readStudentTreeFromFile(std::string pathToFile) {
  std::ifstream file_obj;
  file_obj.open(pathToFile, std::ios::in);
  BST<StudentRecords> obj;
  file_obj.read((char*)&obj, sizeof(obj));
  return obj;
}

/*
  Read Faculty Tree From File Function
  The read faculty tree from file function reads the faculty binary search tree from the file the user has requested after opening the file.
  @param std::string pathToFile
*/
BST<FacultyRecords> InputOutput::readFacultyTreeFromFile(std::string pathToFile) {
  std::ifstream file_obj;
  file_obj.open(pathToFile, std::ios::in);
  BST<FacultyRecords> obj;
  file_obj.read((char*)&obj, sizeof(obj));
  return obj;
}
