/*
Thomas Jordan & Jackie Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 7: Creating a Simple Database System Using BSTs
*/

/*
  This is a header file that lists out the public functions that will be used/included in InputOutput.cpp and mainprogram.cpp directly.
*/

#include "Simulate.h"
#include <fstream>

class InputOutput {
public:
  void readClassFile();
  void writeClassFile(std::string pathToFile);
  void writeStudentTreeToFile(BST<StudentRecords> m_StudentRecordsTree, std::string pathToFile);
  void writeFacultyTreeToFile(BST<FacultyRecords> m_FacultyRecordsTree, std::string pathToFile);
  BST<StudentRecords> readStudentTreeFromFile(std::string pathToFile);
  BST<FacultyRecords> readFacultyTreeFromFile(std::string pathToFile);
};
