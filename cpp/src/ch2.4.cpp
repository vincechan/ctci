#include "third_party/catch.hpp"

#include <vector>
#include "LinkedList.h"

/**
 * partition a list such that all values < x come before x and all values > x
 * come after
 */
void partition(LinkedList& list, int x) {
  Node* beforeHead = nullptr;
  Node* beforeTail = nullptr;
  Node* sameHead = nullptr;
  Node* sameTail = nullptr;
  Node* afterHead = nullptr;
  Node* afterTail = nullptr;

  Node* cursor = list.head;
  while (cursor != nullptr) {
    if (cursor->value < x) {
      if (beforeHead == nullptr) {
        beforeHead = new Node(nullptr, cursor->value);
        beforeTail = beforeHead;
      } else {
        beforeTail->next = new Node(nullptr, cursor->value);
        beforeTail = beforeTail->next;
      }
    } else if (cursor->value == x) {
      if (sameHead == nullptr) {
        sameHead = new Node(nullptr, cursor->value);
        sameTail = sameHead;
      } else {
        sameTail->next = new Node(nullptr, cursor->value);
        sameTail = sameTail->next;
      }
    } else {
      if (afterHead == nullptr) {
        afterHead = new Node(nullptr, cursor->value);
        afterTail = afterHead;
      } else {
        afterTail->next = new Node(nullptr, cursor->value);
        afterTail = afterTail->next;
      }
    }
    cursor = cursor->next;
  }

  Node* newHead = nullptr;
  Node* newTail = nullptr;

  cursor = beforeHead;
  while (cursor != nullptr) {
    if (newHead == nullptr) {
      newHead = new Node(nullptr, cursor->value);
      newTail = newHead;
    } else {
      newTail->next = new Node(nullptr, cursor->value);
      newTail = newTail->next;
    }
    cursor = cursor->next;
  }

  cursor = sameHead;
  while (cursor != nullptr) {
    if (newHead == nullptr) {
      newHead = new Node(nullptr, cursor->value);
      newTail = newHead;
    } else {
      newTail->next = new Node(nullptr, cursor->value);
      newTail = newTail->next;
    }
    cursor = cursor->next;
  }

  cursor = afterHead;
  while (cursor != nullptr) {
    if (newHead == nullptr) {
      newHead = new Node(nullptr, cursor->value);
      newTail = newHead;
    } else {
      newTail->next = new Node(nullptr, cursor->value);
      newTail = newTail->next;
    }
    cursor = cursor->next;
  }

  // TODO: remove existing nodes in list.head

  list.head = newHead;
}

TEST_CASE("ch2.4 partition - [5,3,4,5,1]") {
  LinkedList list(std::vector<int>({5, 3, 4, 5, 1}));

  partition(list, 3);
  std::vector<int> actual = list.toVector();

  REQUIRE(actual[0] < 3);
  REQUIRE(actual[1] == 3);
  REQUIRE(actual[2] > 3);
  REQUIRE(actual[3] > 3);
  REQUIRE(actual[4] > 3);
}