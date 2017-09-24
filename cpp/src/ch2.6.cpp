#include "third_party/catch.hpp"

#include "LinkedList.h"

/**
 * Find the loop beginning node given a linked list that has a loop in it
 *
 * Example:
 * Input: (A->B->C->D->E->C) the C is the same C as earlier
 * Ouput: C
 */
int findLoop(const LinkedList& list) {
  // TODO: implement
  return 0;
}

TEST_CASE("ch2.6 findLoop") {
  LinkedList list(std::vector<int>({1, 2, 3, 4, 5}));

  // create the loop so that node 5's next pointer points to node 3
  Node* last = list.head;
  while (last->next != nullptr) {
    last = last->next;
  }
  last->next = list.head->next->next;

  REQUIRE(findLoop(list) == 3);
}