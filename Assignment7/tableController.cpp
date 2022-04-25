#include "tableController.h"

tableController::tableController() {}

tableController::~tableController() {}

void tableController::printAllStudentInfoById(int studentID) {
  StudentRecordsTree.printTree();
}

void tableController::printAllFacultyInfoById(int facultyID) {
  FacultyRecordsTree.printTree();
}

void tableController::printStudentInfo(int studentID) {
  StudentRecordsTree.find(studentID);
}

void tableController::printFacultyInfo(int facultyID) {
  FacultyRecordsTree.find(facultyID);
}

void tableController::printFacultyAdvisees() {

}

void tableController::printFacultyOfStudent() {
  /*
  DLList<int> tempList;
  std::cout << "Advisees of Faculty Member " << facultyID << " ";

  while (!facultyStudentReferences.isEmpty()) {
    tempList = facultyStudentReferences.peekFront();
    std::cout << facultyStudentReferences.peekFront() << " ";
    facultyStudentReferences.removeFront();
  }

  // Replace values
  while (!tempList.isEmpty()) {
    facultyStudentReferences.insertFront(tempList.peekFront());
    tempList.removeFront();
  }
  */
}

void tableController::AddNewStudent(StudentRecords newStudent) {
  //StudentRecordsTree.insert(newStudent);
}

void tableController::DeleteStudent(int studentID) {
  StudentRecordsTree.remove(studentID);
}

void tableController::AddFaculty(FacultyRecords newFaculty) {
  //FacultyRecordsTree.insert(newFaculty);
}

void tableController::DeleteFaculty(int facultyID) {
  FacultyRecordsTree.remove(facultyID);
}

void tableController::ChangeAdvisor() {}

void tableController::RemoveStudentFromFaculty() {}

void tableController::Rollback() {}

void tableController::ExitMenu() {
}

int main() {
  std::cout << "test" << std::endl;
  return 1;
}
