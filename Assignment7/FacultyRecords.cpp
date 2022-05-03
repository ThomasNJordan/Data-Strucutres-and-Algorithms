#include "FacultyRecords.h"

FacultyRecords::FacultyRecords() {
  facultyID = -1;
  facultyName = "";
  facultyLevel = "";
  facultyDepartment = "";
}

FacultyRecords::FacultyRecords(int facultyID, std::string facultyName, std::string facultyLevel, std::string facultyDepartment) {
  this->facultyID = facultyID;
  this->facultyName = facultyName;
  this->facultyLevel = facultyLevel;
  this->facultyDepartment = facultyDepartment;
}

FacultyRecords::~FacultyRecords() {}

// Accesors
int FacultyRecords::getFacultyID() {
  return facultyID;
}

std::string FacultyRecords::getFacultyName() {
  return facultyName;
}

std::string FacultyRecords::getFacultyLevel() {
  return facultyLevel;
}

std::string FacultyRecords::getFacultyDepartment() {
  return facultyDepartment;
}

DLList<int> FacultyRecords::getFacultyStudentReferences() {
  return facultyStudentReferences;
}

void FacultyRecords::setFacultyID(int m_facultyID) {
  facultyID = m_facultyID;
}

void FacultyRecords::setFacultyName(std::string m_facultyName) {
  facultyName = m_facultyName;
}

void FacultyRecords::setFacultyLevel(std::string m_facultyLevel) {
  facultyLevel = m_facultyLevel;
}

void FacultyRecords::setFacultyDepartment(std::string m_facultyDepartment) {
  facultyDepartment = m_facultyDepartment;
}

void FacultyRecords::setFacultyStudentReferences(DLList<int> inList) {
  while (!facultyStudentReferences.isEmpty()) {
    facultyStudentReferences.removeFront();
  }
  while (!inList.isEmpty()) {
    facultyStudentReferences.insertFront(inList.peekFront());
    inList.removeFront();
  }
}

void FacultyRecords::appendStudentReference(int StudentReferece) {
  facultyStudentReferences.insertFront(StudentReferece);
}
