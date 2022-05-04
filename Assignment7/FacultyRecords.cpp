/*
Thomas Jordan & Jackie Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 7: Creating a Simple Database System Using BSTs
*/

/*
  This is the FacultyRecords class that provides the functionality of organizing the information of a faculty member.
*/

#include "FacultyRecords.h"

/*
  Default Constructor
  The default constructor initializes my private variables to -1 and "".
*/
FacultyRecords::FacultyRecords() {
  facultyID = -1;
  facultyName = "";
  facultyLevel = "";
  facultyDepartment = "";
}

/*
  Overloaded Constructor
  The overloaded constructor creates a faculty member of given ID, name, level (lecturer, assistant professor, professor, associate professor, etc.), and department they belong to.
  @param int facultyID, std::string facultyName, std::string facultyLevel, std::string facultyDepartment
*/
FacultyRecords::FacultyRecords(int facultyID, std::string facultyName, std::string facultyLevel, std::string facultyDepartment) {
  this->facultyID = facultyID;
  this->facultyName = facultyName;
  this->facultyLevel = facultyLevel;
  this->facultyDepartment = facultyDepartment;
}

// accessors

/*
  Get Faculty ID Function
  The get faculty ID function is an accessor function that returns the faculty's ID.
  @return int facultyID
*/
int FacultyRecords::getFacultyID() {
  return facultyID;
}

/*
  Get Faculty Name Function
  The get faculty name function is an accessor function that returns the faculty's name.
  @return std::string facultyName
*/
std::string FacultyRecords::getFacultyName() {
  return facultyName;
}

/*
  Get Faculty Level Function
  The get faculty level function is an accessor function that returns the faculty's level.
  @return std::string facultyLevel
*/
std::string FacultyRecords::getFacultyLevel() {
  return facultyLevel;
}

/*
  Get Faculty Department Function
  The get faculty department function is an accessor function that returns the faculty's department.
  @return std::string facultyDepartment
*/
std::string FacultyRecords::getFacultyDepartment() {
  return facultyDepartment;
}

/*
  Get Faculty Student References Function
  The get faculty student references function is an accessor function that returns the faculty student references.
  @return DLList<int> facultyStudentReferences: a doubly linked list of faculty student references organized in integers
*/
DLList<int> FacultyRecords::getFacultyStudentReferences() {
  return facultyStudentReferences;
}

// mutators

/*
  Set Faculty ID Function
  The set faculty ID function is a mutator function that assigns an ID to use for the faculty member.
  @param int m_facultyID
*/
void FacultyRecords::setFacultyID(int m_facultyID) {
  facultyID = m_facultyID;
}

/*
  Set Faculty Name Function
  The set faculty name function is a mutator function that assigns a name to use for the faculty member.
  @param std::string m_facultyName
*/
void FacultyRecords::setFacultyName(std::string m_facultyName) {
  facultyName = m_facultyName;
}

/*
  Set Faculty Level Function
  The set faculty level function is a mutator function that assigns a level to use for the faculty member.
  @param std::string m_facultyLevel
*/
void FacultyRecords::setFacultyLevel(std::string m_facultyLevel) {
  facultyLevel = m_facultyLevel;
}

/*
  Set Faculty Department Function
  The set faculty department function is a mutator function that assigns a department to use for the faculty member.
  @param std::string m_facultyDepartment
*/
void FacultyRecords::setFacultyDepartment(std::string m_facultyDepartment) {
  facultyDepartment = m_facultyDepartment;
}

/*
  Set Faculty Student References Function
  The set faculty student references function is a mutator function that assigns the content in the inList doubly linked list to facultyStudentReferences doubly linked list.
  @param DLList<int> inList
*/
void FacultyRecords::setFacultyStudentReferences(DLList<int> inList) {
  while (!facultyStudentReferences.isEmpty()) {
    facultyStudentReferences.removeFront();
  }
  while (!inList.isEmpty()) {
    facultyStudentReferences.insertFront(inList.peekFront());
    inList.removeFront();
  }
}

/*
  Append Student Reference Function
  The append student references function inserts the student reference to the front of the faculty student references doubly linked list.
  @param int studentReference
*/
void FacultyRecords::appendStudentReference(int studentReference) {
  facultyStudentReferences.insertFront(studentReference);
}
