/*
Thomas Jordan
2400895
thjordan@chapman.edu
CPSC 350-02
Assignment 5
*/

/*
A stack template to define methods for a stack.
*/

template <typename E>

class Stack {
public:
  Stack() {}
  virtual ~Stack() {} // base destructor

  // reinitialize out stack
  virtual void clear() = 0;

  // copy of an element to push
  // push an element onto the top of the stack
  // @param item: element being pushed
  virtual void push(const E& item) = 0;

  // remove the element from the top of the stack
  // return: the element at the top
  virtual E pop() = 0;

  // returns the top element of the stack
  virtual E topValue() = 0;

  // returns the number of elements in the stack
  int length = 0;
};
