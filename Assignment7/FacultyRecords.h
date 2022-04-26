#include "DLList.h"
#include <string>

class FacultyRecords {
  private:
    int facultyID;
    std::string facultyName;
    std::string facultyLevel;
    std::string facultyDepartment;
    DLList<int> facultyStudentReferences;
  public:
    FacultyRecords();
    FacultyRecords(int facultyID, std::string facultyName, std::string facultyLevel, std::string facultyDepartment);
    ~FacultyRecords();
    int getFacultyID();
    std::string getFacultyName();
    std::string getFacultyLevel();
    std::string getFacultyDepartment();
    DLList<int> getFacultyStudentReferences();
};
