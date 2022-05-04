/*
Thomas Jordan & Jackie Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 7: Creating a Simple Database System Using BSTs
*/

/*
  This is the DLList template class that provides the functionality of a doubly linked list.
  It takes in 1 component for the template: typename E to allow any data type to be applied to the doubly linked list.
*/

#include "ListNode.h"

/*
  This is the header component of the DLList template class that lists out all the private variables and public functions that will be used/included in FacultyRecords.cpp, tableController.h, tableController.cpp, Simulate.h, Simulate.cpp, InputOutput.h, InputOutput.cpp, and mainprogram.cpp indirectly and in DLList.h and FacultyRecords.h directly.
*/

template <typename E>
class DLList {
private:
  ListNode<E>* head; // pointer points to the front of the doubly linked list
  ListNode<E>* tail; // pointer points to the back of the doubly linked list
  int size; // tells you the number of elements in the doubly linked list
public:
  DLList(); // default constructor
  ~DLList(); // destructor
  void insertFront(E item); // inserts list node to the front of the doubly linked list
  void insertBack(E item); // inserts list node to the back of the doubly linked list // equivalent to the enqueue function for queue
  E removeFront(); // removes list node that's at the front of the doubly linked list // equivalent to the dequeue function for queue
  E removeBack(); // removes list node that's at the back of the doubly linked list
  E peekFront(); // allows you to see what's the first element of the doubly linked list is // equivalent to the peek function for queue
  E peekBack(); // allows you to see what's the last element of the doubly linked list is
  int length(); // tells you the size of the doubly linked list
  bool isEmpty(); // tells you whether the doubly linked list is empty or not
};

/*
  Default Constructor
  The default constructor initializes my private pointer variables to nullptr and my private int variable to 0.
*/
template <typename E>
DLList<E>::DLList() {
  head = nullptr;
  tail = nullptr;
  size = 0;
}

/*
  Destructor
  The destructor destroys the temp pointer object.
*/
template <typename E>
DLList<E>::~DLList() {
  if (size != 0) { // if there are elements in the doubly linked list...
    ListNode<E>* temp = head; // create a temp pointer object that will replace the original head pointer's placement
    while (head != nullptr) { // while head pointer isn't equal to null...
      temp = head; // assign temp pointer to head pointer
      head = head->next; // assign head pointer to point to the next element instead of the current element
      delete temp; // that way, temp pointer object can be deleted
    }
  }
}

/*
  Insert Front Function
  The insert front function adds a list node to the front of the doubly linked list.
  @param E item: the element that will be placed in the front of the doubly linked list
*/
template <typename E>
void DLList<E>::insertFront(E item) {
  ListNode<E>* temp = new ListNode<E>(item); // create a temp pointer object that points to the new node containing the new element, and add that node to the front of the doubly linked list
  if(size == 0) { // if there are no elements in the doubly linked list...
    tail = temp; // set tail to be temp
  }
  else { // if there are elements in the doubly linked list...
    head->prev = temp; // make head's prev point to temp
    temp->next = head; // make temp's next point to head
  }
  head = temp; // make head point to temp
  size++; // include the added node to the doubly linked list
}

/*
  Insert Back Function
  The insert back function adds a list node to the back of the doubly linked list.
  @param E item: the element that will be placed in the back of the doubly linked list
*/
template <typename E>
void DLList<E>::insertBack(E item) { // create a temp pointer object that points to the new node containing the new element, and add that node to the back of the doubly linked list
  ListNode<E>* temp = new ListNode<E>(item); // create a temp pointer object that points to the new node containing the new element, and add that node to the back of the doubly linked list
  if (size == 0) { // if there are no elements in the doubly linked list...
    head = temp; // set head to be temp
  }
  else { // if there are elements in the doubly linked list...
    tail->next = temp; // make temp's next point to temp
    temp->prev = tail; // make temp's prev point to tail
  }
  tail = temp; // make tail point to temp
  size++; // include the added node to the doubly linked list
}

/*
  Remove Front Function
  The remove front function deletes a list node from the front of the doubly linked list.
  @return E item: the element that will be removed from the front of the doubly linked list
*/
template <typename E>
E DLList<E>::removeFront() {
  ListNode<E>* temp = head; // create a temp pointer object that will replace the original head pointer's placement since the temp pointer object will eventually be deleted
  if (head->next == nullptr) { // if the new head pointer is null...
    tail = nullptr; // make tail equal to null
  }
  else { // if the new head pointer is not null...
    head->next->prev = nullptr; // make head's next's prev point to null
    head = head->next; // make head point to head's next
  }
  E item = temp->element; // declare item with the element that will be removed
  temp->next = nullptr; // make temp's next point to null
  delete temp; // temp object gets deleted after being assigned to null
  size--; // less nodes in the doubly linked list after removing the front node
  return item; // return the element that has been removed
}

/*
  Remove Back Function
  The remove back function deletes a list node from the back of the doubly linked list.
  @return E item: the element that will be removed from the back of the doubly linked list
*/
template <typename E>
E DLList<E>::removeBack() {
  ListNode<E>* temp = tail; // create a temp pointer object that will replace the original tail pointer's placement since the temp pointer object will eventually be deleted
  if (tail->prev == nullptr) { // if the new tail pointer is null...
    head = nullptr; // make head point to null
  }
  else { // if the new tail pointer is not null...
    tail->prev->next = nullptr; // make tail's prev's next point to null
    tail = tail->prev; // make tail point to tail's prev
  }
  E item = temp->element; // declare item with the element that will be removed
  temp->prev = nullptr; // make temp's prev point to null
  delete temp; // temp object gets deleted after being assigned to null
  size--; // less nodes in the doubly linked list after removing the back node
  return item; // return the element that has been removed
}

/*
  Peek Front Function
  The peek front function returns the element that's at the front of the doubly linked list.
  @return E head->element: the element from the front of the doubly linked list that will be returned
*/
template <typename E>
E DLList<E>::peekFront() {
  return head->element;
}

/*
  Peek Back Function
  The peek back function returns the element that's at the back of the doubly linked list.
  @return E tail->element: the element from the back of the doubly linked list that will be returned
*/
template <typename E>
E DLList<E>::peekBack() {
  return tail->element;
}

/*
  Length Function
  The length function returns the number of elements currently in the doubly linked list.
  @return int size
*/
template <typename E>
int DLList<E>::length() {
  return size;
}

/*
  Is Empty Function
  The is empty function returns the size of 0 to indicate that there aren't any elements present in the doubly linked list.
  @return bool (size == 0)
*/
template <typename E>
bool DLList<E>::isEmpty() {
  return (size == 0); // if size = 0, return true, else return false
}
