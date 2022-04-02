#include "Queue.h"
#include <iostream>

using namespace std;

int main() {
  Queue<int> q;
  cout << "Inserting elements 6, 7, and 8" << endl;
  q.enqueue(6);
  q.enqueue(7);
  q.enqueue(8);

  cout << "Checking front element" << endl;
  cout << q.peek() << endl;

  cout << "Removing two elements" << endl;
  q.dequeue();
  q.dequeue();
  cout << q.peek() << endl;

  return 0;
}
