/*
Thomas Jordan & Jackie Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 6: Calculating Metrics on Student Wait Times and Window Idle Times at the Registrar's Office
*/

/*
  This is a header file that lists out the public functions that will be used/included in DLList.h and used/included in all other files indirectly.
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
