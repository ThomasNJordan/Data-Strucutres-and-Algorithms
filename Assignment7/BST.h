/*
Thomas Jordan & Jackie Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 7: Creating a Simple Database System Using BSTs
*/

/*
  This is the BST template class that provides the functionality of the binary search tree.
  It takes in 1 component for the template: typename E to allow any data type to be applied to the binary search tree.
*/

#include "TreeNode.h"
#include <iostream>

template <typename E>
class BST{
private:
  TreeNode<E>* root; // root of tree
  int size; // number of elements in tree

public:
  BST();
  ~BST();
  bool contains(int k);
  E find(int k);
  void insert(TreeNode<E>* node);
  bool remove(int k);
  TreeNode<E>* getSuccessor(TreeNode<E>* d);
  TreeNode<E>* getMin();
  TreeNode<E>* getMax();
  void inOrder(TreeNode<E>* node);
  void printTree();
  TreeNode<E>* getRoot();
  int length();
  bool isEmpty();
};

/*
  Default Constructor
  The default constructor initializes my private variables to nullptr and 0.
*/
template <typename E>
BST<E>::BST(){
  root = nullptr;
  size = 0;
}

/*
  Destructor
  Called when deleting Binary Search Trees
*/
template <typename E>
BST<E>::~BST(){}

/*
  Contains Function
  The contains function checks if the binary search tree contains a node with the key k or not.
  @param int k: key in the binary search tree
  @return bool false: occurs if root is null or if current value is null, bool true: occurs if the current key value equals to key k
*/
template <typename E>
bool BST<E>::contains(int k){
  if (root == nullptr) {
    return false;
  }
  TreeNode<E>* curr = root;
  while (curr->key != k) {
    if (k < curr->key) {
      curr = curr->left;
    }
    else {
      curr = curr->right;
    }
    if (curr == nullptr) {
      return false;
    }
  }
  return true;
}

/*
  Find Function
  The find function checks if the binary search tree finds a node with the key k or not.
  @param int k
  @return E E(): displays empty value if root is null or current value is null, E curr->value: displays the current value if the current key value is equal to key k
*/
template <typename E>
E BST<E>::find(int k){
  if (root == nullptr) { // checks to see if the BST exists or not
    return E(); // returns false case
  }
  TreeNode<E>* curr = root;
  while (curr->key != k) { // while current key doesn't point to the value you're looking for
    if (k < curr->key) { // if value you're looking for is less than current key
      curr = curr->left; // search the left side of BST
    }
    else {
      curr = curr->right; // search the right side of BST
    }
    if (curr == nullptr) { // if current key points to nothing
      return E(); // return empty value
    }
  }
  return curr->value; // return the current value
}

/*
  Insert Function
  The insert function inserts the node into the binary search tree.
  @param TreeNode<E>* node: the node to insert into the binary search tree
*/
template <typename E>
void BST<E>::insert(TreeNode<E>* node){
  if (root == nullptr) {
    root = node;
  } else {
    TreeNode<E>* curr = root;
    TreeNode<E>* parent;
    while (true) {
      parent = curr;  // update parent
      // based on value, update current
      if (node->key < curr->key) {
        curr = curr->left;
        if (curr == nullptr) {
          parent->left = node;
          break;
        }
      }
      else {
        curr = curr->right;
        if (curr == nullptr) {
          parent -> right = node;
          break;
        }
      }
    }
  }
  size++;
}

/*
  Delete Function
  The delete function removes a node from the binary search tree.
  There are 4 cases to removing a node from the binary search tree:
    1. if the node has no children,
    2. if the node has 1 left child,
    3. if the node has 1 right child, and
    4. if the node has 2 children (both left and right).
  @param int k
  @return bool false: occurs if current value is null, return true: occurs when removing the node is successful
*/
template <typename E>
bool BST<E>::remove(int k){
  if (root == nullptr) {
    return false;
  }
  TreeNode<E>* curr = root;
  TreeNode<E>* parent = root;
  bool isLeft = true;

  // find the node to delete (and store isLeft)
  while (curr->key != k) {
    parent = curr;
    if (k < curr->key) {
      curr = curr->left;
      isLeft = true;
    }
    else {
      curr = curr->right;
      isLeft = false;
    }
    if (curr == nullptr) {
      return false;
    }
  }

  // at this point, we have found the node to remove
  // case 1: no cihldren
  if (curr->left == nullptr && curr->right == nullptr) {
    if (curr == root) {
      root = nullptr;
    }
    else if (isLeft == true) {
      parent->left = nullptr;
    }
    else {
      parent->right = nullptr;
    }
  }
  // case 2: 1 left child
  else if (curr->right == nullptr) {
    if (curr == root) {
      root = curr->left;
    }
    else if (isLeft == true) {
      parent->left = curr->left;
    }
    else {
      parent->right = curr->left;
    }
  }
  // case 3: 1 right child
  else if (curr->left == nullptr) {
    if (curr == root) {
      root = curr->right;
    }
    else if (isLeft) {
      parent->left = curr->right;
    }
    else {
      parent->right = curr->right;
    }
  }
  // case 4: 2 children
  // Replace current with the leftmost cihld of the right child
  else {
    TreeNode<E>* successor = getSuccessor(curr);
    if (curr = root) { // In edge case of tree size 1
      root = successor;
    }
    else if (isLeft) {
      parent->left = successor;
    }
    else {
      parent->right = successor;
    }
    successor->left = curr->left;
  }
  size--;
  delete curr;
  return true;
}

/*
  Get Successor Function
  The get successor function finds a node's leftmost child of its right child.
  @param TreeNode<E>* d: the node to find the successor for
  @return TreeNode<E>* successor: the successor node
*/
template <typename E>
TreeNode<E>* BST<E>::getSuccessor(TreeNode<E>* d){
  TreeNode<E>* successor = d;
  TreeNode<E>* sp = d;
  TreeNode<E>* curr = d->right; // curr is successor's child

  while (curr != nullptr) {
    sp = successor;
    successor = curr;
    curr = curr->left;
  }

  /*
  In the case that a tree has a subtree off a right brach, we set the left of
  the right subtree to the previous' left. (Move the subtree over) Then we can
  continue as normal to find the successor.
  */
  if (successor != d->right) {
    sp->left = successor->right;
    successor->right = d->right;
  }

  return successor;
}

/*
  Get Min Function
  The get min function finds a binary search tree's smallest key node.
  @return E TreeNode<E>(): occurs if root equals to null, TreeNode<E>* curr: occurs if current value's left child isn't equal to null (the smallest key node)
*/
template <typename E>
TreeNode<E>* BST<E>::getMin(){
  TreeNode<E>* curr = root;
  if (root == nullptr) {
    return new TreeNode<E>(); // new makes a pointer that is converted to object
  }
  while (curr->left != nullptr) { // find the left-most value
    curr = curr->left;
  }
  return curr;
}

/*
  Get Max Function
  The get max function finds a binary search tree's largest key node.
  @return E TreeNode<E>(), TreeNode<E>* curr: occurs if current value's right child isn't equal to null (the largest key node)
*/
template <typename E>
TreeNode<E>* BST<E>::getMax(){
  TreeNode<E>* curr = root;
  if (root == nullptr) {
    return new TreeNode<E>(); // new makes a pointer that is converted to object
  }
  while (curr->right != nullptr) { // find the left-most value
    curr = curr->right;
  }
  return curr;
}

/*
  In Order Function
  The in order function traverses by starting at some node and organizes the nodes from least to greatest.
  @param TreeNode<E>* node: the node to begin the traversal
  @return occurs if there's no nodes in the binary search tree
*/
template <typename E>
void BST<E>::inOrder(TreeNode<E>* node){
  if (node == nullptr) {
    return;
  }
  inOrder(node->left);
  std::cout << node->key << "-";
  inOrder(node->right);
}

/*
  Print Tree Function
  The print tree function calls for the in order function.
*/
template <typename E>
void BST<E>::printTree(){
  inOrder(root);
  std::cout << std::endl;
}

/*
  Get Root Function
  The get root function returns the root value of the binary search tree.
  @return TreeNode<E>* root
*/
template <typename E>
TreeNode<E>* BST<E>::getRoot(){ // the root is also the mode
  return root;
}

/*
  Length Function
  The length function returns the size of the binary search tree.
  @return int size
*/
template <typename E>
int BST<E>::length(){
  return size;
}

/*
  Is Empty Function
  The is empty function checks to see whether the binary search tree is empty or not.
  @return bool true: occurs if the size of the binary search tree is 0, bool false: occurs if the size of the binary search tree isn't 0
*/
template <typename E>
bool BST<E>::isEmpty(){
  if (size == 0) {
    return true;
  }
  return false;
}
