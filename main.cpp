#include "src/Linked_List.h"
#include "src/Node.h"
#include "src/Queue.h"
#include "src/Stack.h"
#include <iostream>
using namespace std;

int main() {
  Node<int> n = 3;
  Linked_List<char> l;
  Queue<float> q;
  Stack<int> s;

  l.insertLast('a');
  q.Insert(2.5);
  s.Push(55555);

  cout << n.getData() << endl;
  l.printForward();
  q.Print();
  s.Print();

  return 0;
}
