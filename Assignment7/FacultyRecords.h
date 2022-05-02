#include "DLList.h"
#include <string>

class FacultyRecords {
  private:
    int facultyID;
    std::string facultyName;
    std::string facultyLevel;
    std::string facultyDepartment;
  public:
    FacultyRecords();
    FacultyRecords(int facultyID, std::string facultyName, std::string facultyLevel, std::string facultyDepartment);
    ~FacultyRecords();
    int getFacultyID();
    std::string getFacultyName();
    std::string getFacultyLevel();
    std::string getFacultyDepartment();
    DLList<int> getFacultyStudentReferences();
    void setFacultyStudentReferences(DLList<int> inList);
    void appendStudentReference(int StudentReferece);
    DLList<int> facultyStudentReferences; // this is dumb
};
