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
    // Accessors
    std::string getFacultyName();
    std::string getFacultyLevel();
    std::string getFacultyDepartment();
    // Mutators
    void setFacultyID(int m_facultyID);
    void setFacultyName(std::string m_facultyName);
    void setFacultyLevel(std::string m_facultyLevel);
    void setFacultyDepartment(std::string m_facultyDepartment);

    DLList<int> getFacultyStudentReferences();
    void setFacultyStudentReferences(DLList<int> inList);
    void appendStudentReference(int StudentReferece);
    DLList<int> facultyStudentReferences; // this is dumb
};
