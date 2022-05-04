/*
Thomas Jordan & Jackie Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 7: Creating a Simple Database System Using BSTs
*/

/*
  This is the ListNode template class that provides the functionality of a list node.
  It takes in 1 component for the template: typename E to allow any data type to be applied to the list node.
*/

/*
  This is a header file that lists out the public functions that will be used/included in FacultyRecords.h, FacultyRecords.cpp, tableController.h, tableController.cpp, Simulate.h, Simulate.cpp, InputOutput.h, InputOutput.cpp, and mainprogram.cpp indirectly and in ListNode.h and DLList.h directly.
*/

// abstract list node class with 2 pointers (prev and next)
template <typename E>
class ListNode {
public:
  E element;
  ListNode* prev; // pointer to previous node
  ListNode* next; // pointer to next node

  /*
    Default Constructor
    The default constructor initializes my public pointer variables to nullptr.
  */
  ListNode() {
    prev = nullptr;
    next = nullptr;
  }

  /*
    Overloaded Constructor
    The overloaded constructor initializes my element object with its value that has been passed into the parameters and my public pointer variables to nullptr.
    @param E elemVal: data value to be added to node
  */
  ListNode(E elemVal) {
    element = elemVal;
    prev = nullptr;
    next = nullptr;
  }
};
