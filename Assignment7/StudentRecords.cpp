#include "StudentRecords.h"

StudentRecords::StudentRecords() {
  studentID = -1;
  studentName = "None";
  studentLevel = "None";
  studentMajor = "None";
  studentGPA = -1.0;
  studentFacultyAdvisorID = -1;
}

StudentRecords::StudentRecords(int studentID, std::string studentName, std::string studentLevel, std::string studentMajor, double studentGPA, int studentFacultyAdvisorID) {
  this->studentID = studentID;
  this->studentName = studentName;
  this->studentLevel = studentLevel;
  this->studentMajor = studentMajor;
  this->studentGPA = studentGPA;
  this->studentFacultyAdvisorID = studentFacultyAdvisorID;
}

StudentRecords::~StudentRecords() {}

// Accessors
int StudentRecords::getStudentID() {
  return studentID;
}

std::string StudentRecords::getStudentName() {
  return studentName;
}

std::string StudentRecords::getStudentLevel() {
  return studentLevel;
}

std::string StudentRecords::getStudentMajor() {
  return studentMajor;
}

double StudentRecords::getStudentGPA() {
  return studentGPA;
}

int StudentRecords::getStudentFacultyAdvisorID() {
  return studentFacultyAdvisorID;
}

// Mutator

void StudentRecords::setStudentID(int m_studentID) {
  studentID = m_studentID;
}

void StudentRecords::setStudentFacultyAdvisorID(int advisorID) {
  studentFacultyAdvisorID = advisorID;
}

void StudentRecords::setStudentName(std::string name) {
  studentName = name;
}

void StudentRecords::setStudentLevel(std::string studentLevel) {
  studentLevel = studentLevel;
}

void StudentRecords::setStudentMajor(std::string studentMajor) {
  studentMajor = studentMajor;
}

void StudentRecords::setStudentGPA(int m_GPA) {
  studentGPA = m_GPA;
}

// Method Overloading
bool StudentRecords::operator==(StudentRecords sr) {
  if (this->studentID == sr.studentID && this->studentName == sr.studentName && this->studentLevel == sr.studentLevel && this->studentMajor == sr.studentMajor && this->studentGPA == sr.studentGPA && this->studentFacultyAdvisorID == sr.studentFacultyAdvisorID) {
    return true;
  }
  return false;
}

bool StudentRecords::operator!=(StudentRecords sr) {
  if (this->studentID != sr.studentID || this->studentName != sr.studentName || this->studentLevel != sr.studentLevel || this->studentMajor != sr.studentMajor || this->studentGPA != sr.studentGPA || this->studentFacultyAdvisorID != sr.studentFacultyAdvisorID) {
    return true;
  }
  return false;
}

bool StudentRecords::operator<(StudentRecords sr) {
  if (this->studentID < sr.studentID) {
    return true;
  }
  return false;
}

bool StudentRecords::operator>(StudentRecords sr) {
  if (this->studentID < sr.studentID) {
    return true;
  }
  return false;
}
