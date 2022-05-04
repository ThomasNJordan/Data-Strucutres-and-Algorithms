/*
Thomas Jordan & Jackie Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 7: Creating a Simple Database System Using BSTs
*/

/*
  This is the TreeNode template class that provides the functionality of a binary search tree node.
  It takes in 1 component for the template: typename E to allow any data type to be applied to the binary search tree node.
*/

/*
  This is a header file that lists out the public functions that will be used/included in tableController.h, tableController.cpp, Simulate.h, Simulate.cpp, InputOutput.h, InputOutput.cpp, and mainprogram.cpp indirectly and in TreeNode.h and BST.h directly.
*/

// abstract TreeNode class
template <typename E>
class TreeNode{
public:
  E value; // data value
  int key; // key for comparison
  TreeNode* left; // left child tree node
  TreeNode* right; // right child tree node

  /*
    Default Constructor
    The default constructor initializes my public int variable to 0, my public E variable to E(), and my public pointer variables to nullptr.
  */
  TreeNode(){ // default constructor
    key = 0;
    value = E(); // empty value
    left = nullptr;
    right = nullptr;
  }

  /*
    Overloaded Constructor
    The overloaded constructor initializes my element object with its value that has been passed into the parameters and my public pointer variables to nullptr.
    @param int k: value for the key, E v: the value that won't make the tree node empty
  */
  TreeNode(int k, E v){ // overloaded constructor
    key = k;
    value = v;
    left = nullptr;
    right = nullptr;
  }
};
