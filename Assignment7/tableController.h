#include "AStack.h"
#include "BST.h"
#include "StudentRecords.h"
#include "FacultyRecords.h"

class tableController : public StudentRecords, FacultyRecords {
  public:
    tableController();
    ~tableController();
    void printAllStudentInfoById();
    void printAllFacultyInfoById();
    void printStudentInfo();
    void printFacultyInfo();
    void pirntFacultyAdvisees();
    void AddNewStudent();
    void DeleteStudent();
    void AddFaculty();
    void DeleteFaculty();
    void ChangeAdvisor();
    void RemoveStudentFromFaculty();
    void Rollback();
    void ExitMenu();
  private:
    //BST<StudentRecords> StudentRecordsTree;
    //BST<FacultyRecords> FacultyRecordsTree;
    AStack<StudentRecords> StudentRecordsTable;
    AStack<FacultyRecords> FacultyRecordsTable;
};
