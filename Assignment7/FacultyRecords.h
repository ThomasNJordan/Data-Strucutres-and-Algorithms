/*
Thomas Jordan & Jackie Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 7: Creating a Simple Database System Using BSTs
*/

/*
  This is the header component of the FacultyRecords class that lists out all the private variables and public functions that will be used/included in tableController.cpp, Simulate.h, Simulate.cpp, InputOutput.h, InputOutput.cpp, and mainprogram.cpp indirectly and in FacultyRecords.cpp and tableController.h directly.
*/

#include "DLList.h"
#include <string>

class FacultyRecords {
private:
  int facultyID;
  std::string facultyName;
  std::string facultyLevel;
  std::string facultyDepartment;
public:
  DLList<int> facultyStudentReferences;
  FacultyRecords();
  FacultyRecords(int facultyID, std::string facultyName, std::string facultyLevel, std::string facultyDepartment);
  // accessors
  int getFacultyID();
  std::string getFacultyName();
  std::string getFacultyLevel();
  std::string getFacultyDepartment();
  DLList <int> getFacultyStudentReferences();
  // mutators
  void setFacultyID(int m_facultyID);
  void setFacultyName(std::string m_facultyName);
  void setFacultyLevel(std::string m_facultyLevel);
  void setFacultyDepartment(std::string m_facultyDepartment);
  void setFacultyStudentReferences(DLList<int> inList);

  void appendStudentReference(int studentReference);
};
