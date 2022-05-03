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
    bool operator!=(const StudentRecords sr);
    bool operator<(const StudentRecords sr);
    bool operator>(const StudentRecords sr);
    // Accessors
    int getStudentID();
    std::string getStudentName();
    std::string getStudentLevel();
    std::string getStudentMajor();
    double getStudentGPA();
    int getStudentFacultyAdvisorID();
    // Mutators
    void setStudentID(int studentID);
    void setStudentName(std::string name);
    void setStudentLevel(std::string studentName);
    void setStudentMajor(std::string studentMajor);
    void setStudentGPA(int m_GPA);
    void setStudentFacultyAdvisorID(int advisorID);
};
