/*
Thomas Jordan & Jackie Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 7: Creating a Simple Database System Using BSTs
*/

/*
  This is a header file that lists out the public functions that will be used/included in tableController.h, tableController.cpp, Simulate.h, Simulate.cpp, InputOutput.h, InputOutput.cpp, and mainprogram.cpp indirectly and in AStack.h directly.
*/

// stack abstract class
template <typename E>
class Stack {
public:
  Stack() {}  // default constructor
  virtual ~Stack() {} // base destructor

  /*
    Clear Function
    The clear function gets rid of all the elements in the stack and reintitializes the stack.
  */
  virtual void clear() = 0;

  /*
    Push Function
    The push function adds an element onto the top of the stack.
    @param const E& item: the element being added to the stack
  */
  virtual void push(const E& item) = 0;

  /*
    Pop Function
    The pop function removes and returns an element from the top of the stack.
    @return E item: the top element of the stack
  */
  virtual E pop() = 0;

  /*
    Top Value Function
    The top value function returns a copy of the value of the top element of the stack.
    @return E value: the value of top element of the stack if the size of the stack is 0, E stackArray[top - 1]: the value of top element of the stack if the size of the stack is greater than 0
  */
  virtual E topValue() = 0;

  /*
    Length Function
    The length function returns the number of elements that are currently in the stack.
    @return int size
  */
  int length = 0;
};
