#include "LinkedList.h"
#include "third_party/catch.hpp"

LinkedList::~LinkedList() {
  // HACK: we are corrupting the linked list for ch2.6, which will cause issue
  // when we free the linked list. Commenting out the freeing of the nodes since
  // it's the sole purpose of the LinkedList in to faciliate ch2 exercises.
  //
  // if (head != nullptr) {
  //   while (head->next != nullptr) {
  //     Node* p = head;
  //     head = head->next;
  //     delete p;
  //   }
  //   delete head;
  //   head = nullptr;
  // }
}

Node* LinkedList::find(int targetValue) {
  Node* runner = this->head;
  while (runner != nullptr) {
    if (runner->value == targetValue) {
      return runner;
    }
    runner = runner->next;
  }
  return nullptr;
}

void LinkedList::push_back(int newValue) {
  if (head == nullptr) {
    this->head = new Node(newValue);
    return;
  }

  Node* runner = head;
  while (runner->next != nullptr) {
    runner = runner->next;
  }
  runner->next = new Node(newValue);
}

void LinkedList::push_front(int newValue) {
  Node* newNode = new Node(this->head, newValue);
  this->head = newNode;
}

void LinkedList::remove(int targetValue) {
  if (this->head == nullptr) {
    return;
  }

  if (this->head->value == targetValue) {
    Node* target = this->head;
    this->head = this->head->next;
    delete target;
  }

  Node* runner = this->head;
  while (runner->next != nullptr) {
    if (runner->next->value == targetValue) {
      Node* target = runner->next;
      runner->next = runner->next->next;
      delete target;
      return;
    }
    runner = runner->next;
  }
}
