/*
Thomas Jordan
2400895
thjordan@chapman.edu
CPSC 350-02
Assignment 5
*/

/*
AStack is a implementation of a stack using arrays.
*/

#ifndef ASTACK_H
#define ASTACK_H

#include "Stack.h"
#include <exception>
#include <iostream>

using namespace std;

template <typename E>
class AStack : public Stack<E> {
private:
  int stackSize;
  int top;
  E *ArrayStack;
public:
  AStack();
  ~AStack();
  void clear();
  void push(const E& item);
  E pop();
  E topValue();
  int length();
};

/*
Default constructor that creates an empty array of size 4.
*/
template <typename E>
AStack<E>::AStack() {
  ArrayStack = new E[4];
  stackSize = 4;
  top = 0;
}

/*
Destructor that calls the clear() function.
*/
template <typename E>
AStack<E>::~AStack() {
  clear();
}

/*
Sets the size counter to 0, then deletes the array
*/
template <typename E>
void AStack<E>::clear() {
  stackSize = 0;
  delete[] ArrayStack;
}

/*
push() pushes an item onto the stack. If the stack is full, it then doubles the
size of the array.
@param the generic item being added to the stack
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
  ArrayStack[top] = item;  // sets a new top to actual top
  top++;
}

/*
pop() removes the top item from the stack
@return returns the new top value of the stack
*/
template <typename E>
E AStack<E>::pop() { //
  try {
    if (top == 0) {
      throw runtime_error("Error: Stack is empty");
    }
  }
  catch (const exception &e) {} // replace with runtime_error
  stackSize--;
  top--;
  return ArrayStack[top];
}

/*
topValue() returns the top value
@return the top value of the stack
*/
template <typename E>
E AStack<E>::topValue() {
  return ArrayStack[top-1];
}

/*
length() returns the size of the stack
@return the size of the stack
*/
template <typename E>
int AStack<E>::length() {
  return stackSize;
}

#endif
