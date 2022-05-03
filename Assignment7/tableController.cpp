#include "tableController.h"

tableController::tableController() {}

tableController::~tableController() {}

void tableController::printAllStudentInfoById() {
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

void tableController::printAllFacultyInfoById() {
  int length = UnsortedFacultyIDs.length();
  DLList<int> tempList;

  // https://www.geeksforgeeks.org/sort-c-stl/
  int FacultysortedArray[length];
  for (int i = 0; i < length; ++i) {
    FacultysortedArray[i] = UnsortedFacultyIDs.peekFront();
    tempList.insertFront(UnsortedFacultyIDs.peekFront());
    UnsortedFacultyIDs.removeFront();
  }
  std::sort(FacultysortedArray, FacultysortedArray+length);

  for (int j = 0; j < length; j++) {
    printFacultyInfo(FacultysortedArray[j]);
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
  std::cout << "Advisee IDs: " << std::endl;
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
  // If student's advisor is in tree, update advisor's student list
  if (FacultyRecordsTree.contains(newStudent.getStudentFacultyAdvisorID())) {
    TreeNode<StudentRecords>* myNode = new TreeNode<StudentRecords>(newStudent.getStudentID(), newStudent);
    StudentRecordsTree.insert(myNode);
    UnsortedStudentIDs.insertFront(newStudent.getStudentID());
    /*
    FacultyRecords tempFaculty = FacultyRecordsTree.find(newStudent.getStudentFacultyAdvisorID());
    DLList<int> tempRefList = tempFaculty.getFacultyStudentReferences();
    tempRefList.insertFront(newStudent.getStudentID());
    tempFaculty.setFacultyStudentReferences(tempRefList);

    TreeNode<FacultyRecords>* facultyNode = new TreeNode<FacultyRecords>(tempFaculty.getFacultyID(), tempFaculty);
    FacultyRecordsTree.remove(tempFaculty.getFacultyID());
    FacultyRecordsTree.insert(facultyNode);
    */
  }
  else {
    std::cout << "No such faculty advisor exists." << std::endl;
  }
}

void tableController::DeleteStudent(int studentID) {
  StudentRecordsTree.remove(studentID);

  // Traverse faculty tree and locate faculty node and delete student reference
}

void tableController::AddFaculty(FacultyRecords newFaculty) {
  TreeNode<FacultyRecords>* myNode = new TreeNode<FacultyRecords>(newFaculty.getFacultyID(), newFaculty);
  FacultyRecordsTree.insert(myNode);
  UnsortedFacultyIDs.insertFront(newFaculty.getFacultyID());
}

void tableController::DeleteFaculty(int facultyID) {
  FacultyRecordsTree.remove(facultyID);
}

void tableController::ChangeAdvisor(int studentID, int facultyID) {
  StudentRecords oldStudent = StudentRecordsTree.find(studentID);
  FacultyRecords newFaculty = FacultyRecordsTree.find(facultyID);
  int oldFacultyID = oldStudent.getStudentID();
  FacultyRecords oldFaculty = FacultyRecordsTree.find(oldFacultyID);

  // Add new adviser to student
  oldStudent.setStudentFacultyAdvisorID(facultyID);
  // Remove old student from old Faculty
  DLList<int> oldStudentRefs = oldFaculty.getFacultyStudentReferences();
  DLList<int> updatedStudentRefs; // Place this in BST object
  while (!oldStudentRefs.isEmpty()) {
    if (oldStudentRefs.peekFront() != studentID) {
      updatedStudentRefs.insertFront(oldStudentRefs.peekFront());
      oldStudentRefs.removeFront();
    }
    else {
      oldStudentRefs.removeFront();
    }
  }
  // Add student to new faculty member
  DLList<int> updatedFacultyRefs = newFaculty.getFacultyStudentReferences();
  updatedFacultyRefs.insertFront(studentID);

  // Update BST
  TreeNode<FacultyRecords>* newFacultyNode = new TreeNode<FacultyRecords>(facultyID, newFaculty);
  FacultyRecordsTree.remove(facultyID);
  FacultyRecordsTree.insert(newFacultyNode);

  TreeNode<FacultyRecords>* oldFacultyNode = new TreeNode<FacultyRecords>(oldFacultyID, oldFaculty);
  FacultyRecordsTree.remove(oldFacultyID);
  FacultyRecordsTree.insert(oldFacultyNode);

  TreeNode<StudentRecords>* oldStudentNode = new TreeNode<StudentRecords>(studentID, oldStudent);
  StudentRecordsTree.remove(studentID);
  StudentRecordsTree.insert(oldStudentNode);
}

void tableController::RemoveStudentFromFaculty(int studentID, int facultyID, int destinationID) {
  // TODO Add check to make sure at least one other node besides root in in BST (maybe check length?)
  // We delete the student ID from the faculty member.
  FacultyRecords FacultyMember = FacultyRecordsTree.find(facultyID);
  FacultyRecords DestinationMember = FacultyRecordsTree.find(destinationID);

  // Remove old student from Faculty member
  DLList<int> oldStudentRefs = FacultyMember.getFacultyStudentReferences();
  DLList<int> updatedStudentRefs; // Place this in BST object
  while (!oldStudentRefs.isEmpty()) {
    if (oldStudentRefs.peekFront() != studentID) {
      updatedStudentRefs.insertFront(oldStudentRefs.peekFront());
      oldStudentRefs.removeFront();
    }
    else {
      oldStudentRefs.removeFront();
    }
  }

  // Add student to new faculty member
  DLList<int> updatedFacultyRefs = DestinationMember.getFacultyStudentReferences();
  updatedFacultyRefs.insertFront(studentID);

  // Update student
  StudentRecords updatedStudent = StudentRecordsTree.find(studentID);
  updatedStudent.setStudentFacultyAdvisorID(destinationID);

  // Update BST
  TreeNode<FacultyRecords>* newFacultyNode = new TreeNode<FacultyRecords>(facultyID, FacultyMember);
  FacultyRecordsTree.remove(facultyID);
  FacultyRecordsTree.insert(newFacultyNode);

  TreeNode<StudentRecords>* oldStudentNode = new TreeNode<StudentRecords>(studentID, updatedStudent);
  StudentRecordsTree.remove(studentID);
  StudentRecordsTree.insert(oldStudentNode);
}

void tableController::Rollback() {
  int optionChosen = userChoices.peekFront();
  userChoices.removeFront();

  if (optionChosen == 7 || optionChosen == 8) {
    // pop Student Table
    tblFaculty.pop();
  }
  if (optionChosen == 9 || optionChosen == 10) {
    // pop Student Table
    tblStudent.pop();
  }
  if (optionChosen == 11 || optionChosen == 12) {
    // pop both
    tblFaculty.pop();
    tblStudent.pop();
  }
}

void tableController::ExitMenu() {
  //printAllFacultyInfoById();
  //printAllFacultyInfoById();
}
