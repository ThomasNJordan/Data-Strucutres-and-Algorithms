/*
Thomas Jordan & Jackie Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 7: Creating a Simple Database System Using BSTs
*/

/*
  This is a header file that lists out all of the private, protected, and public variables and functions that will be used/included in Simulate.cpp, InputOutput.h, InputOutput.cpp, and mainprogram.cpp indirectly and in tableController.cpp and Simulate.h directly.
*/

#include "AStack.h"
#include "BST.h"
#include "StudentRecords.h"
#include "FacultyRecords.h"
#include <algorithm> // contains std::sort function

class tableController : public StudentRecords, FacultyRecords {
private:
  BST<StudentRecords> StudentRecordsTree;
  BST<FacultyRecords> FacultyRecordsTree;
  DLList<int> UnsortedStudentIDs;
  DLList<int> UnsortedFacultyIDs;
protected:
  DLList<int> userChoices;
public:
  void printAllStudentInfoById(); // optionChosen == 1
  void printAllFacultyInfoById(); // optionChosen == 2
  void printStudentInfo(int studentID); // optionChosen == 3
  void printFacultyInfo(int facultyID); // optionChosen == 4
  void printFacultyOfStudent(int facultyID); // optionChosen == 5
  void printFacultyAdvisees(int studentID); // optionChosen == 6
  void AddNewStudent(StudentRecords newStudent); // optionChosen == 7
  void DeleteStudent(int studentID); // optionChosen == 8
  void AddFaculty(FacultyRecords newFaculty); // optionChosen == 9
  void DeleteFaculty(int facultyID); // optionChosen == 10
  void ChangeAdvisor(int studentID, int facultyID); // optionChosen == 11
  void RemoveStudentFromFaculty(int studentID, int destinationID); // optionChosen == 12
  void Rollback(); // optionChosen == 13
  void ExitMenu(); // optionChosen == 14
  // AStack<StudentRecordsTree> tblStudent;
  // AStack<FacultyRecordsTree> tblFaculty;
};
