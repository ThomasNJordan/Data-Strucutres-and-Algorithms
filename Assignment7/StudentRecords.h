/*
Thomas Jordan & Jackie Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 7: Creating a Simple Database System Using BSTs
*/

/*
  This is the header component of the StudentRecords class that lists out all the private variables and public functions that will be used/included in tableController.cpp, Simulate.h, Simulate.cpp, InputOutput.h, InputOutput.cpp, and mainprogram.cpp indirectly and in StudentRecords.cpp and tableController.h directly.
*/

#include <string>

class StudentRecords {
private:
  int studentID;
  std::string studentName;
  std::string studentLevel;
  std::string studentMajor;
  double studentGPA;
  int studentFacultyAdvisorID;
public:
  StudentRecords();
  StudentRecords(int studentID, std::string studentName, std::string studentLevel, std::string studentMajor, double studentGPA, int studentFacultyAdvisorID);
  // accessors
  int getStudentID();
  std::string getStudentName();
  std::string getStudentLevel();
  std::string getStudentMajor();
  double getStudentGPA();
  int getStudentFacultyAdvisorID();
  // mutators
  void setStudentID(int m_studentID);
  void setStudentName(std::string m_studentName);
  void setStudentLevel(std::string m_studentLevel);
  void setStudentMajor(std::string m_studentMajor);
  void setStudentGPA(double m_studentGPA);
  void setStudentFacultyAdvisorID(int facultyID);
  // operator overloading
  bool operator == (const StudentRecords sr);
  bool operator != (const StudentRecords sr);
  bool operator > (const StudentRecords sr);
  bool operator < (const StudentRecords sr);
};
