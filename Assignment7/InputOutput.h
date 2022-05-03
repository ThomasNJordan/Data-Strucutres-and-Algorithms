#include "Simulate.h"
#include <fstream>

class InputOutput {
public:
  void readClassFile();
  void writeClassFile(std::string pathToFile);
  void writeStudentTreeToFile(BST<StudentRecords> m_StudentRecordsTree, std::string pathToFile);
  void writeFacultyTreeToFile(BST<FacultyRecords> m_FacultyRecordsTree, std::string pathToFile);
};
