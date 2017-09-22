#ifndef LINKEDLIST_INCLUDED
#define LINKEDLIST_INCLUDED

#include <vector>

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

/**
 * Copy all values inside a LinkedList into a vector to facilitate testing.
 */
inline std::vector<int> convertLinkedListToVector(const LinkedList& list) {
  std::vector<int> v;
  Node* cur = list.head;
  while (cur != nullptr) {
    v.push_back(cur->data);
    cur = cur->next;
  }
  return v;
}

#endif