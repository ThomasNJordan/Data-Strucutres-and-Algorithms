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
    ~StudentRecords();
    bool operator==(const StudentRecords sr);
    int getStudentID();
    std::string getStudentName();
    std::string getStudentLevel();
    std::string getStudentMajor();
    double getStudentGPA();
    int getStudentFacultyAdvisorID();
    void setStudentFacultyAdvisorID(int advisorID);
};
