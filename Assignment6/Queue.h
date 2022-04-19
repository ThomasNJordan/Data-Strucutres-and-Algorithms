/*
Thomas Jordan & Jackie Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 6: Calculating Metrics on Student Wait Times and Window Idle Times at the Registrar's Office
*/

/*
  This is the Queue template class that provides the functionality of a queue.
  It takes in 1 component for the template: typename E to allow any data type to be applied to the queue.
*/

#include "DLList.h"

/*
  This is the header component of the Queue template class that lists out all the private variables and public functions that will be used/included in Simulation.h and used/included in Simulation.cpp and mainprogram.cpp indirectly.
*/

template <typename E>
class Queue {
private:
  DLList<int> myDLList;
public:
  void enqueue(E item); // equivalent to insertBack function in DLList.h
  void dequeue(); // equivalent to removeFront function in DLList.h
  E peek(); // equivalent to peekFront function in DLList.h
};

/*
  Enqueue Function
  The enqueue function calls the insert back function from DLList template class to insert an element to the back of the queue.
  @param E item: the element that will be inserted to the back of the queue
*/
template <typename E>
void Queue<E>::enqueue(E item) {
  myDLList.insertBack(item);
}

/*
  Dequeue Function
  The dequeue function calls the remove front function from DLList template class to remove an element from the front of the queue.
*/
template <typename E>
void Queue<E>::dequeue() {
  myDLList.removeFront();
}

/*
  Peek Function
  The peek function calls the peek front function from DLList template class to display the element that's at the front of the queue.
*/
template <typename E>
E Queue<E>::peek() {
  myDLList.peekFront();
}
