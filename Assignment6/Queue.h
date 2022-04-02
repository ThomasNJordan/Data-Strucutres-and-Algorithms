#include "DLList.h"

template <typename E>
class Queue {
private:
  DLList<int> myDLList;
public:
  void enqueue(E item);
  void dequeue();
  E peek();
};

template <typename E>
void Queue<E>::enqueue(E item) {
  myDLList.insertBack(item);
}

template <typename E>
void Queue<E>::dequeue() {
  myDLList.removeFront();
}

template <typename E>
E Queue<E>::peek() {
  myDLList.peekFront();
}
