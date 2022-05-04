/*
Thomas Jordan & Jackie Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 7: Creating a Simple Database System Using BSTs
*/

/*
  This is the AStack template class that provides the functionality of the dynamically allocated stack array.
  It takes in 1 component for the template: typename E to allow any data type to be applied to the dynamically allocated stack array.
*/

#ifndef ASTACK_H
#define ASTACK_H

#include "Stack.h"
#include <exception>
#include <iostream>

/*
  This is the header component of the AStack template class that lists out all the private variables and public functions that will be used/included in tableController.cpp, Simulate.h, Simulate.cpp, InputOutput.h, InputOutput.cpp, and mainprogram.cpp indirectly and in AStack.h and tableController.h directly.
*/

template <typename E>
class AStack : public Stack<E> {
private:
  E *ArrayStack; // array holding stack elements
  int top; // placement of top element
  int stackSize; // current size of stack array
public:
  AStack(); // default constructor
  ~AStack(); // destructor
  void clear(); // get rid of all elements in the stack array to make the stack array empty
  void push(const E& item); // pushing an element to the top of the stack array
  E pop(); // removing the element that's at the top of the stack array
  E topValue(); // display the element that's at the top of the stack array
  int length(); // display how many elements are currently in the stack array
};

/*
  Default Constructor
  The default constructor initializes my private variables ArrayStack to a size of 4 (in order to create an empty array of size 4), stackSize to 4, and top to 0.
*/
template <typename E>
AStack<E>::AStack() {
  ArrayStack = new E[4];
  stackSize = 4;
  top = 0;
}

/*
  Destructor
  The destructor calls the clear function.
*/
template <typename E>
AStack<E>::~AStack() {
  clear();
}

/*
  Clear Function
  The clear function gets rid of all the elements in the dynamically allocated stack array and reintitializes it.
*/
template <typename E>
void AStack<E>::clear() {
  stackSize = 0;
  delete[] ArrayStack;
}

/*
  Push Function
  The push function adds an element onto the top of the dynamically allocated stack array.
  If the dynamically allocated stack array is full, it then doubles the size of the dynamically allocated stack array.
  @param const E& item: the element being added to the stack
*/
template <typename E>
void AStack<E>::push(const E& item) {
  if (top == stackSize) { // check if stack is full
    E* newStack = new E[stackSize * 2];
    for (int i =  0; i < stackSize; ++i) {
      newStack[i] = ArrayStack[i];
    }
    stackSize = stackSize * 2;
    ArrayStack = new E[stackSize];
    for (int i = 0; i < stackSize; ++i) {
      ArrayStack[i] = newStack[i];
    }
  }
  ArrayStack[top] = item; // sets a new top to actual top
  top++;
}

/*
  Pop Function
  The pop function removes and returns an element from the top of the dynamically allocated stack array most of the time.
  If the dynamically allocated stack array is empty (top == 0), an runtime error exception is thrown since there aren't any elements to remove.
  @return E item: the top element of the stack
*/
template <typename E>
E AStack<E>::pop() { //
  try {
    if (top == 0) {
      throw std::runtime_error("Error: Stack is currently empty. There's no elements for you to remove from the stack.");
    }
  }
  catch (const std::runtime_error &e) {}
  stackSize--;
  top--;
  return ArrayStack[top];
}

/*
  Top Value Function
  The top value function returns a copy of the value of the top element of the dynamically allocated stack array.
  @return E value: the value of top element of the dynamically allocated stack array if the size of the stack is 0, E stackArray[top - 1]: the value of top element of the dynamically allocated stack array if the size of the stack is greater than 0
*/
template <typename E>
E AStack<E>::topValue() {
  if (stackSize == 0) {
    E value = E();
    return value;
  }
  return ArrayStack[top - 1];
}

/*
  Length Function
  The length function returns the number of elements that are currently in the dynamically allocated stack array.
  @return int stackSize
*/
template <typename E>
int AStack<E>::length() {
  return stackSize;
}

#endif
