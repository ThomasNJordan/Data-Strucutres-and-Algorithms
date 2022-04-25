#include <string>
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

int main() {
  std::cout << "test" << std::endl;
  return 1;
}
