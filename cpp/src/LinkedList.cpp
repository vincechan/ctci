#include "LinkedList.h"
#include "third_party/catch.hpp"

LinkedList::LinkedList() { this->head = nullptr; }

LinkedList::~LinkedList() {
  if (head != nullptr) {
    while (head->next != nullptr) {
      Node* p = head;
      head = head->next;
      delete p;
    }
    delete head;
    head = nullptr;
  }
}

void LinkedList::insert(int data) {
  if (head == nullptr) {
    this->head = new Node(data);
    return;
  }

  Node* tail = head;
  while (tail->next != nullptr) {
    tail = tail->next;
  }
  tail->next = new Node(data);
}

void LinkedList::deleteNode(int value) {
  if (head->data == value) {
    Node* deletingNode = head;
    head = head->next;
    delete deletingNode;
    deletingNode = nullptr;
    return;
  }

  Node* cursor = head;
  while (cursor->next != nullptr) {
    if (cursor->next->data == value) {
      Node* deletingNode = cursor->next;
      cursor->next = cursor->next->next;
      delete deletingNode;
      return;
    }
    cursor = cursor->next;
  }
}