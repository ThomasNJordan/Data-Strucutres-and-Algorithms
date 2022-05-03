#include "InputOutput.h"

void InputOutput::writeClassFile(std::string pathToFile) {
  std::ofstream class_obj;
  class_obj.open(pathToFile, ios::app);
  int choice;
  std::cout << "Would you like to create a new student or faculty member: " << std::endl;
  std::cout << "1. Student\n2. Faculty" << std::endl;
  cin >> choice;
  if (choice == 1) {
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

    class_obj.write((char*)&tempStudent, sizeof(tempStudent));
  }
  else if (choice == 2) {
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

    class_obj.write((char*)&tempFaculty, sizeof(tempFaculty));
  } else {
    std::cout << "Invalid chocie" << std::endl;
  }
}

void InputOutput::writeStudentTreeToFile(BST<StudentRecords> m_StudentRecordsTree, std::string pathToFile) {
  std::ofstream class_obj;
  class_obj.open(pathToFile, ios::app);

  class_obj.write((char*)&m_StudentRecordsTree, sizeof(m_StudentRecordsTree));
}

void InputOutput::writeFacultyTreeToFile(BST<FacultyRecords> m_FacultyRecordsTree, std::string pathToFile) {
  std::ofstream class_obj;
  class_obj.open(pathToFile, ios::app);

  class_obj.write((char*)&m_FacultyRecordsTree, sizeof(m_FacultyRecordsTree));
}


BST<StudentRecords> InputOutput::readStudentTreeFromFile(std::string pathToFile) {
  ifstream file_obj;
  file_obj.open(pathToFile, ios::in);
  BST<StudentRecords> obj;
  file_obj.read((char*)&obj, sizeof(obj));
  return obj;
}

BST<FacultyRecords> InputOutput::readFacultyTreeFromFile(std::string pathToFile) {
  ifstream file_obj;
  file_obj.open(pathToFile, ios::in);
  BST<FacultyRecords> obj;
  file_obj.read((char*)&obj, sizeof(obj));
  return obj;
}

int main() {
  InputOutput i;
  i.writeClassFile("test.txt");
  //Simulate s;
  //s.Menu();
  return 1;
}
