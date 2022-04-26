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

void tableController::printFacultyAdvisees(int studentID) {
  StudentRecords tempRecord = StudentRecordsTree.find(studentID);
  int tempFacultyID = tempRecord.getStudentFacultyID();
  printFacultyInfo(tempFacultyID);
}

void tableController::printFacultyOfStudent(int facultyID) {
  FacultyRecords tempFaculty = FacultyRecordsTree.find(facultyID);
  DLList<int> tempList;
  DLList<int> FacultyOfStudentList = tempFaculty.getFacultyStudentReferences();
  std::cout << "Advisees of Faculty Member " << facultyID << ": ";

  while (!FacultyOfStudentList.isEmpty()) {
    tempList.insertFront(FacultyOfStudentList.peekFront());
    std::cout << FacultyOfStudentList.peekFront() << " ";
    FacultyOfStudentList.removeFront();
  }

  // Replace values
  while (!tempList.isEmpty()) {
    FacultyOfStudentList.insertFront(tempList.peekFront());
    tempList.removeFront();
  }
}

void tableController::AddNewStudent(int studentID, StudentRecords newStudent) {
  TreeNode<StudentRecords>* myNode = new TreeNode<StudentRecords>(studentID, newStudent);
  StudentRecordsTree.insert(myNode);
}

void tableController::DeleteStudent(int studentID) {
  StudentRecordsTree.remove(studentID);
}

void tableController::AddFaculty(int facultyID, FacultyRecords newFaculty) {
  TreeNode<FacultyRecords>* myNode = new TreeNode<FacultyRecords>(facultyID, newFaculty);
  FacultyRecordsTree.insert(myNode);
}

void tableController::DeleteFaculty(int facultyID) {
  FacultyRecordsTree.remove(facultyID);
}

void tableController::ChangeAdvisor() {}

void tableController::RemoveStudentFromFaculty() {}

void tableController::Rollback() {}

void tableController::ExitMenu() {
  //printAllFacultyInfoById();
  //printAllFacultyInfoById();
}

int main() {
  tableController tc;
  std::cout << "test" << std::endl;
  return 1;
}
