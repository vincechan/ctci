#ifndef LINKEDLIST_INCLUDED
#define LINKEDLIST_INCLUDED

struct Node {
  int data;
  Node* next;
  Node(int value) {
    data = value;
    next = nullptr;
  }
};

class LinkedList {
 public:
  Node* head;
  LinkedList();
  ~LinkedList();
  void insert(int data);
  void deleteNode(int data);
};

#endif