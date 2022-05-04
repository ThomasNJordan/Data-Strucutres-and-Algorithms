/*
Thomas Jordan & Jackie Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 7: Creating a Simple Database System Using BSTs
*/

/*
  This is the StudentRecords class that provides the functionality of organizing the information of a student.
*/

#include "StudentRecords.h"

/*
  Default Constructor
  The default constructor initializes my private variables to -1, -1.0 and "".
*/
StudentRecords::StudentRecords() {
  studentID = -1;
  studentName = "";
  studentLevel = "";
  studentMajor = "";
  studentGPA = -1.0;
  studentFacultyAdvisorID = -1;
}

/*
  Overloaded Constructor
  The overloaded constructor creates a student of given ID, name, level (Freshman, Sophomore, etc.), major, GPA, and and faculty's ID they belong to.
  @param int studentID, std::string studentName, std::string studentLevel, std::string studentMajor, double studentGPA, int studentFacultyAdvisorID
*/
StudentRecords::StudentRecords(int studentID, std::string studentName, std::string studentLevel, std::string studentMajor, double studentGPA, int studentFacultyAdvisorID) {
  this->studentID = studentID;
  this->studentName = studentName;
  this->studentLevel = studentLevel;
  this->studentMajor = studentMajor;
  this->studentGPA = studentGPA;
  this->studentFacultyAdvisorID = studentFacultyAdvisorID;
}

// accessors

/*
  Get Student ID Function
  The get student ID function is an accessor function that returns the student's ID.
  @return int studentID
*/
int StudentRecords::getStudentID() {
  return studentID;
}

/*
  Get Student Name Function
  The get student name function is an accessor function that returns the student's name.
  @return std::string studentName
*/
std::string StudentRecords::getStudentName() {
  return studentName;
}

/*
  Get Student Level Function
  The get student level function is an accessor function that returns the student's level.
  @return std::string studentLevel
*/
std::string StudentRecords::getStudentLevel() {
  return studentLevel;
}

/*
  Get Student Major Function
  The get student major function is an accessor function that returns the student's major.
  @return std::string studentMajor
*/
std::string StudentRecords::getStudentMajor() {
  return studentMajor;
}

/*
  Get Student GPA Function
  The get student GPA function is an accessor function that returns the student's GPA.
  @return double studentGPA
*/
double StudentRecords::getStudentGPA() {
  return studentGPA;
}

/*
  Get Student Faculty Advisor ID Function
  The get student faculty advisor ID function is an accessor function that returns the faculty's ID the student is associated with.
  @return int studentFacultyAdvisorID
*/
int StudentRecords::getStudentFacultyAdvisorID() {
  return studentFacultyAdvisorID;
}

// mutators

/*
  Set Student ID Function
  The set student ID function is a mutator function that assigns an ID to use for the student.
  @param int m_studentID
*/
void StudentRecords::setStudentID(int m_studentID) {
  studentID = m_studentID;
}

/*
  Set Student Name Function
  The set student name function is a mutator function that assigns a name to use for the student.
  @param std::string m_studentName
*/
void StudentRecords::setStudentName(std::string m_studentName) {
  studentName = m_studentName;
}

/*
  Set Student Level Function
  The set student level function is a mutator function that assigns a level to use for the student.
  @param std::string m_studentLevel
*/
void StudentRecords::setStudentLevel(std::string m_studentLevel) {
  studentLevel = m_studentLevel;
}

/*
  Set Student Major Function
  The set student major function is a mutator function that assigns a major to use for the student.
  @param std::string m_studentMajor
*/
void StudentRecords::setStudentMajor(std::string m_studentMajor) {
  studentMajor = m_studentMajor;
}

/*
  Set Student GPA Function
  The set student GPA function is a mutator function that assigns a GPA to use for the student.
  @param double m_studentGPA
*/
void StudentRecords::setStudentGPA(double m_studentGPA) {
  studentGPA = m_studentGPA;
}

/*
  Set Student Faculty Advisor ID Function
  The set student faculty advisor ID function is a mutator function that assigns a faculty's ID to associate to the student.
  @param int facultyID
*/
void StudentRecords::setStudentFacultyAdvisorID(int facultyID) {
  studentFacultyAdvisorID = facultyID;
}

// operator overloading

/*
  Operator == Function
  The operator == function is an operator overloading function that will compare whether the student's information is equal to another student's information.
  @param StudentRecords sr: object declared for StudentRecords class
  @return bool true: occurs if the student's information equals another student's information, bool false: occurs if the student's information doesn't equal another student's information
*/
bool StudentRecords::operator == (StudentRecords sr) {
  if (this->studentID == sr.studentID && this->studentName == sr.studentName && this->studentLevel == sr.studentLevel && this->studentMajor == sr.studentMajor && this->studentGPA == sr.studentGPA && this->studentFacultyAdvisorID == sr.studentFacultyAdvisorID) {
    return true;
  }
  return false;
}

/*
  Operator != Function
  The operator != function is an operator overloading function that will compare whether the student's information is not equal to another student's information.
  @param StudentRecords sr
  @return bool true: occurs if the student's information doesn't equal another student's information, bool false: occurs if the student's information equals another student's information
*/
bool StudentRecords::operator != (StudentRecords sr) {
  if (this->studentID != sr.studentID || this->studentName != sr.studentName || this->studentLevel != sr.studentLevel || this->studentMajor != sr.studentMajor || this->studentGPA != sr.studentGPA || this->studentFacultyAdvisorID != sr.studentFacultyAdvisorID) {
    return true;
  }
  return false;
}

/*
  Operator > Function
  The operator > function is an operator overloading function that will compare whether the student's ID is greater than another student's ID (numerically wise).
  @param StudentRecords sr
  @return bool true: occurs if the student's ID is greater than another student's ID, bool false: occurs if the student's ID isn't greater than another student's ID
*/
bool StudentRecords::operator > (StudentRecords sr) {
  if (this->studentID > sr.studentID) {
    return true;
  }
  return false;
}

/*
  Operator < Function
  The operator < function is an operator overloading function that will compare whether the student's ID is less than another student's ID (numerically wise).
  @param StudentRecords sr
  @return bool true: occurs if the student's ID is less than another student's ID, bool false: occurs if the student's ID isn't less than another student's ID
*/
bool StudentRecords::operator < (StudentRecords sr) {
  if (this->studentID < sr.studentID) {
    return true;
  }
  return false;
}
