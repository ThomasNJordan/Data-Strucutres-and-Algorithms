/*
Thomas Jordan & Jackie Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 7: Creating a Simple Database System Using BSTs
*/

/*
  This is the tableController class that provides the functionality of the menu displayed in the Simulate class.
*/

#include "tableController.h"
#include <iostream>

/*
  Print All Student Info By ID Function
  The print all student info by ID function takes care of menu option 1, which is to display all students' information based on their IDs, such as:
    1. ID number,
    2. name,
    3. level (Freshman, Sophomore, etc.),
    4. major,
    5. GPA, and
    6. their advisor, which contain the faculty ID of their advisor.
*/
void tableController::printAllStudentInfoById() { // optionChosen == 1
  int length = UnsortedStudentIDs.length();
  DLList<int> tempList;

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

/*
  Print All Faculty Info By ID Function
  The print all faculty info by ID function takes care of menu option 2, which is to display all faculty's information based on their IDs, such as:
    1. ID number,
    2. name,
    3. level (lecturer, assistant professor, professor, associate professor, etc.),
    4. department, and
    5. a list of their advisees'/students' IDs.
*/
void tableController::printAllFacultyInfoById() { // optionChosen == 2
  int length = UnsortedFacultyIDs.length();
  DLList<int> tempList;

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

/*
  Print Student Info Function
  The print student info function takes care of menu option 3, which is to display all of one student's information based on their ID number, such as:
    1. ID number,
    2. name,
    3. level (Freshman, Sophomore, etc.),
    4. major,
    5. GPA, and
    6. their advisor, which contain the faculty ID of their advisor.
  @param int studentID
*/
void tableController::printStudentInfo(int studentID) { // optionChosen == 3
  StudentRecords tempStudent = StudentRecordsTree.find(studentID);
  std::cout << "Student's ID number: " << tempStudent.getStudentID() << std::endl;
  std::cout << "Student's name: " << tempStudent.getStudentName() << std::endl;
  std::cout << "Student's level: " << tempStudent.getStudentLevel() << std::endl;
  std::cout << "Student's major: " << tempStudent.getStudentMajor() << std::endl;
  std::cout << "Student's GPA: " << tempStudent.getStudentGPA() << std::endl;
  std::cout << "Faculty advisor's ID that the student is associated with: " << tempStudent.getStudentFacultyAdvisorID() << std::endl;
}

/*
  Print Faculty Info Function
  The print faculty info function takes care of menu option 4, which is to display all of one faculty advisor's information based on their ID number, such as:
    1. ID number,
    2. name,
    3. level (lecturer, assistant professor, professor, associate professor, etc.),
    4. department, and
    5. a list of their advisees'/students' IDs.
  @param int facultyID
*/
void tableController::printFacultyInfo(int facultyID) { // optionChosen == 4
  FacultyRecords tempFaculty = FacultyRecordsTree.find(facultyID);
  DLList<int> tempStudentList = tempFaculty.getFacultyStudentReferences();
  DLList<int> tempList;

  std::cout << "Faculty advisor's ID number: " << tempFaculty.getFacultyID() << std::endl;
  std::cout << "Faculty advisor's name: " << tempFaculty.getFacultyName() << std::endl;
  std::cout << "Faculty advisor's position: " << tempFaculty.getFacultyLevel() << std::endl;
  std::cout << "Faculty advisor's department: " << tempFaculty.getFacultyDepartment() << std::endl;
  std::cout << "List of faculty advisor's advisees'/students' IDs: " << std::endl;
  while (!tempStudentList.isEmpty()) {
    tempList.insertFront(tempStudentList.peekFront());
    std::cout << tempStudentList.peekFront() << " ";
    tempStudentList.removeFront();
  }

  // replace values
  while (!tempList.isEmpty()) {
    tempStudentList.insertFront(tempList.peekFront());
    tempList.removeFront();
  }
}

/*
  Print Faculty Of Student Function
  The print faculty of student function takes care of menu option 5, which is to display the name and information of the faculty advisor that is associated with a student based on the student's ID number.
  @param int facultyID
*/
void tableController::printFacultyOfStudent(int facultyID) { // optionChosen == 5
  FacultyRecords tempFaculty = FacultyRecordsTree.find(facultyID);
  DLList<int> tempList;
  DLList<int> FacultyOfStudentList = tempFaculty.getFacultyStudentReferences();
  std::cout << "Advisees/students of faculty advisor " << facultyID << ": ";

  while (!FacultyOfStudentList.isEmpty()) {
    tempList.insertFront(FacultyOfStudentList.peekFront());
    std::cout << FacultyOfStudentList.peekFront() << " ";
    FacultyOfStudentList.removeFront();
  }

  // replace values
  while (!tempList.isEmpty()) {
    FacultyOfStudentList.insertFront(tempList.peekFront());
    tempList.removeFront();
  }
}

/*
  Print Faculty Advisees Function
  The print faculty advisees function takes care of menu option 6, which is to display all the names and information of the faculty advisor's advisees/students based on that faculty advisor's ID number.
  @param int studentID
*/
void tableController::printFacultyAdvisees(int studentID) { // optionChosen == 6
  StudentRecords tempRecord = StudentRecordsTree.find(studentID);
  int tempFacultyID = tempRecord.getStudentFacultyAdvisorID();
  printFacultyInfo(tempFacultyID);
}

/*
  Add New Student Function
  The add new student function takes care of menu option 7, which is to add a new student to the student binary search tree.
  @param StudentRecords newStudent
*/
void tableController::AddNewStudent(StudentRecords newStudent) { // optionChosen == 7
  // if the student's faculty advisor is in the faculty binary search tree, then update the faculty advisor's advisee/student list
  if (FacultyRecordsTree.contains(newStudent.getStudentFacultyAdvisorID())) {
    TreeNode<StudentRecords>* myNode = new TreeNode<StudentRecords>(newStudent.getStudentID(), newStudent);
    StudentRecordsTree.insert(myNode);
    UnsortedStudentIDs.insertFront(newStudent.getStudentID());
  }

  // CODE TO HANDLE STUDENT REFERENCES - BROKE WITHOUT TIME TO FIX :(
  // FacultyRecords tempFaculty = FacultyRecordsTree.find(newStudent.getStudentFacultyAdvisorID());
  // DLList<int> tempRefList = tempFaculty.getFacultyStudentReferences();
  // tempRefList.insertFront(newStudent.getStudentID());
  // tempFaculty.setFacultyStudentReferences(tempRefList);
  //
  // TreeNode<FacultyRecords>* facultyNode = new TreeNode<FacultyRecords>(tempFaculty.getFacultyID(), tempFaculty);
  // FacultyRecordsTree.remove(tempFaculty.getFacultyID());
  // FacultyRecordsTree.insert(facultyNode);

  // tblStudent.push(StudentRecordsTree);
  else {
    std::cout << "No such faculty advisor exist in the faculty binary search tree." << std::endl;
  }
}

/*
  Delete Student Function
  The delete student function takes care of menu option 8, which is to delete a student from the student binary search tree given the student's ID number.
  @param int studentID
*/
void tableController::DeleteStudent(int studentID) { // optionChosen == 8
  StudentRecordsTree.remove(studentID);
  // tblStudent.push(StudentRecordsTree);
  // traverse the faculty binary search tree, locate the faculty node, and delete the student reference
}

/*
  Add Faculty Function
  The add faculty function takes care of menu option 9, which is to add a new faculty advisor to the faculty binary search tree.
  @param FacultyRecords newFaculty
*/
void tableController::AddFaculty(FacultyRecords newFaculty) { // optionChosen == 9
  TreeNode<FacultyRecords>* myNode = new TreeNode<FacultyRecords>(newFaculty.getFacultyID(), newFaculty);
  FacultyRecordsTree.insert(myNode);
  UnsortedFacultyIDs.insertFront(newFaculty.getFacultyID());
  // tblFaculty.push(FacultyRecordsTree);
}

/*
  Delete Faculty Function
  The delete faculty function takes care of menu option 10, which is to delete a faculty advisor from the faculty binary search tree given the faculty advisor's ID number.
  @param int facultyID
*/
void tableController::DeleteFaculty(int facultyID) { // optionChosen == 10
  FacultyRecordsTree.remove(facultyID);
  // tblFaculty.push(FacultyRecordsTree);
}

/*
  Change Advisor Function
  The change advisor function takes care of menu option 11, which is to change a student's faculty advisor given the student's ID number and the new faculty advisor's ID number.
  @param int studentID, int facultyID
*/
void tableController::ChangeAdvisor(int studentID, int facultyID) { // optionChosen == 11
  StudentRecords oldStudent = StudentRecordsTree.find(studentID);
  FacultyRecords newFaculty = FacultyRecordsTree.find(facultyID);
  int oldFacultyID = oldStudent.getStudentID();
  FacultyRecords oldFaculty = FacultyRecordsTree.find(oldFacultyID);

  // add a new faculty advisor to associate with a student
  oldStudent.setStudentFacultyAdvisorID(facultyID);

  // remove a student from their previous faculty advisor
  DLList<int> oldStudentRefs = oldFaculty.getFacultyStudentReferences();
  DLList<int> updatedStudentRefs; // place this in BST object
  while (!oldStudentRefs.isEmpty()) {
    if (oldStudentRefs.peekFront() != studentID) {
      updatedStudentRefs.insertFront(oldStudentRefs.peekFront());
      oldStudentRefs.removeFront();
    }
    else {
      oldStudentRefs.removeFront();
    }
  }

  // add a student to associate with a new faculty advisor
  DLList<int> updatedFacultyRefs = newFaculty.getFacultyStudentReferences();
  updatedFacultyRefs.insertFront(studentID);

  // update BSTs
  TreeNode<FacultyRecords>* newFacultyNode = new TreeNode<FacultyRecords>(facultyID, newFaculty);
  FacultyRecordsTree.remove(facultyID);
  FacultyRecordsTree.insert(newFacultyNode);

  TreeNode<FacultyRecords>* oldFacultyNode = new TreeNode<FacultyRecords>(oldFacultyID, oldFaculty);
  FacultyRecordsTree.remove(oldFacultyID);
  FacultyRecordsTree.insert(oldFacultyNode);

  TreeNode<StudentRecords>* oldStudentNode = new TreeNode<StudentRecords>(studentID, oldStudent);
  StudentRecordsTree.remove(studentID);
  StudentRecordsTree.insert(oldStudentNode);

  // tblStudent.push(StudentRecordsTree);
  // tblFaculty.push(FacultyRecordsTree);
}

/*
  Remove Student From Faculty Function
  The remove student from faculty function takes care of menu option 12, which is to delete a advisee/student from their faculty advisor given their ID number.
  @param int studentID, int destinationID
*/
void tableController::RemoveStudentFromFaculty(int studentID, int destinationID) {
  // TODO Add check to make sure at least one other node besides root in in BST (maybe check length?)
  // We delete the student ID from the faculty member.
  StudentRecords StudentNode = StudentRecordsTree.find(studentID);
  FacultyRecords FacultyMember = FacultyRecordsTree.find(StudentNode.getStudentFacultyAdvisorID());
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
  TreeNode<FacultyRecords>* newFacultyNode = new TreeNode<FacultyRecords>(StudentNode.getStudentFacultyAdvisorID(), FacultyMember);
  FacultyRecordsTree.remove(StudentNode.getStudentFacultyAdvisorID());
  FacultyRecordsTree.insert(newFacultyNode);

  TreeNode<StudentRecords>* oldStudentNode = new TreeNode<StudentRecords>(StudentNode.getStudentFacultyAdvisorID(), updatedStudent);
  StudentRecordsTree.remove(studentID);
  StudentRecordsTree.insert(oldStudentNode);
}

/*
  Rollback Function
  The rollback function takes care of menu option 13, which is to revert back edits the user has made to the database.
  The edits are all stored in a stack, while only holds the most recent 5 edits.
*/
void tableController::Rollback() { // optionChosen == 13
  int optionChosen = userChoices.peekFront();
  userChoices.removeFront();

  if (optionChosen == 7 || optionChosen == 8) {
    // pop Student Table
    // tblStudent.pop();
  }
  if (optionChosen == 9 || optionChosen == 10) {
    // pop Faculty Table
    // tblFaculty.pop();
  }
  if (optionChosen == 11 || optionChosen == 12) {
    // pop both tables
    // tblStudent.pop();
    // tblFaculty.pop();
  }
}

/*
  Exit Menu Function
  The exit menu function takes care of menu option 14, which is to allow the user to quit the program when they're done utilizing the database.
  Before exiting the program, it will print all of the information of the students and faculty advisors.
*/
void tableController::ExitMenu() { // optionChosen == 14
  printAllStudentInfoById();
  printAllFacultyInfoById();
}
