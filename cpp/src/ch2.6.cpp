#include "third_party/catch.hpp"

#include "LinkedList.h"

/**
 * Find the loop beginning node given a linked list that has a loop in it
 *
 * Example:
 * Input: (A->B->C->D->E->C) the C is the same C as earlier
 * Ouput: C
 */
Node* findLoop(const LinkedList& list) {
  if (list.head == nullptr) {
    return nullptr;
  }

  // for every one move slow cursor makes, fast cursor will make 2 moves
  Node* fast = list.head;
  Node* slow = list.head;
  while (fast->next != nullptr) {
    fast = fast->next->next;
    slow = slow->next;
    if (fast == slow) {
      break;
    }
  }

  if (fast != slow) {
    // no loop found
    return nullptr;
  }

  // Loop found. Try to determine beginning of the loop.
  // Point fast to head and leave slow at the last collision point.
  // move both fast and slow one move at a time, when they meet again
  // that's the beginning of the loop
  fast = list.head;
  while (fast != slow) {
    fast = fast->next;
    slow = slow->next;
  }

  return fast;
}

TEST_CASE("ch2.6 findLoop") {
  LinkedList list(std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8}));

  // create the loop so that last node's next pointer points to node 4
  Node* last = list.head;
  while (last->next != nullptr) {
    last = last->next;
  }
  last->next = list.head->next->next->next;

  REQUIRE(findLoop(list)->value == 4);
}