// doubly linked list template class

#include "ListNode.h"

template <typename E>
class DLList{
private:
  ListNode<E>* head; // pointer to front of list
  ListNode<E>* tail; // pointer to back of list
  int size; // number of elements in list

public:
  DLList();
  ~DLList();
  void insertFront(E item);
  void insertBack(E item);
  E removeFront();
  E removeBack();
  E peekFront();
  E peekBack();
  int length();
  bool isEmpty();
};

/*
Constructor for DLList.
*/
template <typename E>
DLList<E>::DLList(){
  head = nullptr;
  tail = nullptr;
  size = 0;
}

/*
Destructor for DLList.
*/
template <typename E>
DLList<E>::~DLList(){
  if (size != 0) {  // When size is 0, we already delete values. If we delete a
    // deleted pointer, it causes an error
    ListNode<E>* temp = head;
    while (head != nullptr) {
      temp = head;
      head = head->next;
      delete temp;
    }
  }
}

/*
insertFront
Function inserts a list node to the front of the list.
@param item: item value to be inserted.
*/
template <typename E>
void DLList<E>::insertFront(E item){
  ListNode<E>* temp = new ListNode<E>(item);
  // When list is empty
  /*
  - Create a new list node temp with data element
  - Set tail be temp
  - Set head be temp
  */
  if(size == 0) {
    tail = temp;
  }
  // When list is NOT empty
  /*
  - Create a new list temp node with data element
  - Make head's prev point to temp
  - Make temp's next point to head
  - Make head point to temp
  */
  else {
    head->prev = temp;
    temp->next = head;
  }
  head = temp;
  size++;
}

/*
insertBack
Function inserts a list node to the back of the list.
@param item: item value to be inserted.
*/
template <typename E>
void DLList<E>::insertBack(E item){
  ListNode<E>* temp = new ListNode<E>(item);
  // When list is empty
  /*
  - Create a new list node temp with data element
  - Set tail be temp
  - Set head be temp
  */
  if (size == 0) {
    head = temp;
  }
  // When list is NOT empty
  /*
  - Create a new list node temp with data element
  - Make temp's next point to temp
  - Make temp's previous point to tail
  - Make tail point to temp
  */
  else {
    tail->next = temp;
    temp->prev = tail;
  }
  tail = temp;
  size++;
}

/*
removeFront
Function removes a list node from the front of the list.
@return: item value at front.
*/
template <typename E>
E DLList<E>::removeFront(){
  ListNode<E>* temp = head;
  // When head is NULL
  /*
  - Create a new temp pointer
  - Make temp's next point to head
  - Make tail point to NULL
  - Store temp's data and set temp's next to NULL
  - Delete temp and return data value
  */
  if (head->next == nullptr) {
    tail = nullptr;
  }
  // When head is NOT NULL
  /*
  - Make a new temp pointer point to head
  - Make head's next's prev point to NULL
  - Make head point to head's next
  - Store temp's data and set temp's next to NULL
  - Delete temp and return data value
  */
  else {
    head->next->prev = nullptr;
    head = head->next;
  }
  E item = temp->element;
  temp->next = nullptr;
  delete temp;
  size--;
  return item;
}


/*
removeBack
Function removes a list node from the back of the list.
@return: item value at back.
*/
template <typename E>
E DLList<E>::removeBack(){
  ListNode<E>* temp = tail;
  // When tail's prev is NULL
  /*
  - Create a new temp pointer
  - Make head point to NULL
  - Store temp's data and set temp's prev to NULL
  - Delete temp and return data value
  */
  if (tail->prev == nullptr) {
    head = nullptr;
  }
  // When tail's prev is NOT NULL
  /*
  - Make a new temp pointer point to tail
  - Make tail's prev's next point to NULL
  - Make tail point to tail's previous
  - Store temp's data and set temp's prev to NULL
  - delete temp
  */
  else {
    tail->prev->next = nullptr;
    tail = tail->prev;
  }
  E item = temp->element;
  temp->prev = nullptr;
  delete temp;
  size--;
  return item;
}

/*
peekFront
Function returns the data value at front of list
@return: item value at front.
*/
template <typename E>
E DLList<E>::peekFront(){
  return head->element;
}

/*
peekBack
Function returns the data value at the back of list
@return: item value at back.
*/
template <typename E>
E DLList<E>::peekBack(){
  return tail->element;
}

/*
length
Function returns the size of the list.
@return: size of list.
*/
template <typename E>
int DLList<E>::length(){
  return size;
}


/*
length
Function returns if list is empty or not by checking size.
@return: T/F.
*/
template <typename E>
bool DLList<E>::isEmpty(){
  return (size == 0); // if size = 0, return true, else return false
}
