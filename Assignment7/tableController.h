#include "AStack.h"
#include "BST.h"
#include "StudentRecords.h"
#include "FacultyRecords.h"
#include <algorithm> // std::sort

class tableController : public StudentRecords, FacultyRecords {
  public:
    tableController();
    ~tableController();
    void printAllStudentInfoById();
    void printAllFacultyInfoById();
    void printStudentInfo(int studentID);
    void printFacultyInfo(int facultyID);
    void printFacultyAdvisees(int studentID);
    void printFacultyOfStudent(int facultyID);
    void AddNewStudent(StudentRecords newStudent);
    void DeleteStudent(int studentID);
    void AddFaculty(FacultyRecords newFaculty);
    void DeleteFaculty(int facultyID);
    void ChangeAdvisor(int studentID, int facultyID);
    void RemoveStudentFromFaculty(int studentID, int destinationID);
    void Rollback();
    void ExitMenu();
    //AStack<StudentRecordsTree> tblStudent;
    //AStack<FacultyRecordsTree> tblFaculty;
  private:
    BST<StudentRecords> StudentRecordsTree;
    BST<FacultyRecords> FacultyRecordsTree;
    DLList<int> UnsortedStudentIDs;
    DLList<int> UnsortedFacultyIDs;
  protected:
    DLList<int> userChoices;
};
