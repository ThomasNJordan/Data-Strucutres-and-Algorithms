#include "AStack.h"
#include "BST.h"
#include "StudentRecords.h"
#include "FacultyRecords.h"

class tableController : public StudentRecords, FacultyRecords {
  public:
    tableController();
    ~tableController();
    void printAllStudentInfoById(int studentID);
    void printAllFacultyInfoById(int facultyID);
    void printStudentInfo(int studentID);
    void printFacultyInfo(int facultyID);
    void printFacultyAdvisees(int studentID);
    void printFacultyOfStudent(int facultyID);
    void AddNewStudent(int studentID, StudentRecords newStudent);
    void DeleteStudent(int studentID);
    void AddFaculty(int facultyID, FacultyRecords newFaculty);
    void DeleteFaculty(int facultyID);
    void ChangeAdvisor();
    void RemoveStudentFromFaculty();
    void Rollback();
    void ExitMenu();
  private:
    BST<StudentRecords> StudentRecordsTree;
    BST<FacultyRecords> FacultyRecordsTree;
    AStack<StudentRecords> StudentRecordsTable;
    AStack<FacultyRecords> FacultyRecordsTable;
};
