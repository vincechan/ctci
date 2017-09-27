#ifndef LINKEDLIST_INCLUDED
#define LINKEDLIST_INCLUDED

#include <iostream>
#include <vector>

struct Node {
  int value;
  Node* next;
  Node(Node* next, int value) : next(next), value(value) {}
  Node(int value) : Node(nullptr, value) {}
};

/**
 * A simple LinkedList with various methods to faciliate unit testing.
 */
class LinkedList {
 public:
  Node* head;

  LinkedList() { this->head = nullptr; }

  LinkedList(const std::vector<int>& initialValues) {
    head = nullptr;
    for (size_t i = 0; i < initialValues.size(); i++) {
      this->push_back(initialValues[i]);
    }
  }

  ~LinkedList();

  Node* find(int value);

  void push_front(int value);

  void push_back(int value);

  void remove(int value);

  /**
   * Copy all values into a vector to facilitate testing.
   */
  inline std::vector<int> toVector() {
    std::vector<int> v;
    Node* runner = this->head;
    while (runner != nullptr) {
      v.push_back(runner->value);
      runner = runner->next;
    }
    return v;
  }

  /**
   * Print all values
   */
  inline void print() {
    Node* runner = this->head;
    while (runner != nullptr) {
      std::cout << runner->value << " ";
      runner = runner->next;
    }
  }
};

#endif