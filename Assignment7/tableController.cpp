#include "tableController.h"

tableController::tableController() {}

tableController::~tableController() {}

void tableController::printAllStudentInfoById(int studentID) {
  int length = UnsortedStudentIDs.length();
  DLList<int> tempList;

  // https://www.geeksforgeeks.org/sort-c-stl/
  int sortedArray[length];
  for (int i = 0; i < length; ++i) {
    sortedArray[i] = UnsortedStudentIDs.peekFront();
    tempList.insertFront(UnsortedStudentIDs.peekFront());
    UnsortedStudentIDs.removeFront();
  }
  std::sort(sortedArray, sortedArray+length);

  for (int j = 0; j < length; j++) {
    printStudentInfo(sortedArray[j]);
  }

  // Replace values
  while (!tempList.isEmpty()) {
    UnsortedStudentIDs.insertFront(tempList.peekFront());
    tempList.removeFront();
  }
}

void tableController::printAllFacultyInfoById(int facultyID) {
  int length = UnsortedFacultyIDs.length();
  DLList<int> tempList;

  // https://www.geeksforgeeks.org/sort-c-stl/
  int sortedArray[length];
  for (int i = 0; i < length; ++i) {
    sortedArray[i] = UnsortedFacultyIDs.peekFront();
    tempList.insertFront(UnsortedFacultyIDs.peekFront());
    UnsortedFacultyIDs.removeFront();
  }
  std::sort(sortedArray, sortedArray+length);

  for (int j = 0; j < length; j++) {
    printStudentInfo(sortedArray[j]);
  }

  // Replace values
  while (!tempList.isEmpty()) {
    UnsortedFacultyIDs.insertFront(tempList.peekFront());
    tempList.removeFront();
  }
}

void tableController::printStudentInfo(int studentID) {
  StudentRecords tempStudent = StudentRecordsTree.find(studentID);
  std::cout << "Student ID: " << tempStudent.getStudentID() << std::endl;
  std::cout << "Name: " << tempStudent.getStudentName() << std::endl;
  std::cout << "Level: " << tempStudent.getStudentLevel() << std::endl;
  std::cout << "Major: " << tempStudent.getStudentMajor() << std::endl;
  std::cout << "GPA: " << tempStudent.getStudentGPA() << std::endl;
  std::cout << "Faculty Advisor ID: " << tempStudent.getStudentFacultyAdvisorID() << std::endl;
}

void tableController::printFacultyInfo(int facultyID) {
  FacultyRecords tempFaculty = FacultyRecordsTree.find(facultyID);
  DLList<int> tempStudentList = tempFaculty.getFacultyStudentReferences();
  DLList<int> tempList;

  std::cout << "Faculty ID: " << tempFaculty.getFacultyID() << std::endl;
  std::cout << "Name: " << tempFaculty.getFacultyName() << std::endl;
  std::cout << "Position: " << tempFaculty.getFacultyLevel() << std::endl;
  std::cout << "Department: " << tempFaculty.getFacultyDepartment() << std::endl;
  std::cout << "Advisees IDs: " << std::endl;
  while (!tempStudentList.isEmpty()) {
    tempList.insertFront(tempStudentList.peekFront());
    std::cout << tempStudentList.peekFront() << " ";
    tempStudentList.removeFront();
  }
  // Replace values
  while (!tempList.isEmpty()) {
    tempStudentList.insertFront(tempList.peekFront());
    tempList.removeFront();
  }
}

void tableController::printFacultyAdvisees(int studentID) {
  StudentRecords tempRecord = StudentRecordsTree.find(studentID);
  int tempFacultyID = tempRecord.getStudentFacultyAdvisorID();
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

void tableController::AddNewStudent(StudentRecords newStudent) {
  TreeNode<StudentRecords>* myNode = new TreeNode<StudentRecords>(newStudent.getStudentID(), newStudent);
  StudentRecordsTree.insert(myNode);
  UnsortedStudentIDs.insertFront(newStudent.getStudentID());
}

void tableController::DeleteStudent(int studentID) {
  StudentRecordsTree.remove(studentID);
}

void tableController::AddFaculty(FacultyRecords newFaculty) {
  TreeNode<FacultyRecords>* myNode = new TreeNode<FacultyRecords>(newFaculty.getFacultyID(), newFaculty);
  FacultyRecordsTree.insert(myNode);
  UnsortedFacultyIDs.insertFront(newFaculty.getFacultyID());
}

void tableController::DeleteFaculty(int facultyID) {
  FacultyRecordsTree.remove(facultyID);
}

void tableController::ChangeAdvisor() {}

void tableController::RemoveStudentFromFaculty() {}

void tableController::Rollback() {
  int optionChosen = userChoices.peekFront();
  userChoices.removeFront();

  if (optionChosen == 7 || optionChosen == 8) {
    // pop Student Table
  }
  if (optionChosen == 9 || optionChosen == 10) {
    // pop Student Table
  }
  if (optionChosen == 11 || optionChosen == 12) {
    // pop both
  }
}

void tableController::ExitMenu() {
  //printAllFacultyInfoById();
  //printAllFacultyInfoById();
}

int main() {
  tableController tc;
  std::cout << "test" << std::endl;
  return 1;
}
