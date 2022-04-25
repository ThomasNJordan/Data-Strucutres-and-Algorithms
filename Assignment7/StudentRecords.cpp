#include "StudentRecords.h"

StudentRecords::StudentRecords() {
  studentID = -1;
  studentName = "None";
  studentLevel = "None";
  studentMajor = "None";
  studentGPA = -1.0;
  studentFacultyAdvisorID = -1;
}

StudentRecords::StudentRecords(int studentID, string studentName, string studentLevel, string studentMajor, double studentGPA, int studentFacultyAdvisorID) {
  this->studentID = studentID;
  this->studentName = studentName;
  this->studentLevel = studentLevel;
  this->studentMajor = studentMajor;
  this->studentGPA = studentGPA;
  this->studentFacultyAdvisorID = studentFacultyAdvisorID;
}
