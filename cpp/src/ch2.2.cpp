#include "third_party/catch.hpp"

#include "LinkedList.h"

/**
 * Find k th to the last element. Return -1 if it doesn't exist.
 */
int findKthToLast(const LinkedList& list, int k) {
  // find total number of elements in the linked list
  int count = 0;
  Node* p = list.head;
  while (p != nullptr) {
    count++;
    p = p->next;
  }

  // determine number of move next to get to kth to last element
  p = list.head;
  int moves = count - k - 1;
  if (moves < 0) {
    // kth element does not exist
    return -1;
  }

  // go to k th to the last element and return the value
  while (moves > 0) {
    p = p->next;
    moves--;
  }
  return p->data;
}

TEST_CASE("ch2.2 findKthToLast - [1,2,3,4,5]") {
  LinkedList list;
  list.insert(1);
  list.insert(2);
  list.insert(3);
  list.insert(4);
  list.insert(5);

  REQUIRE(findKthToLast(list, 0) == 5);
  REQUIRE(findKthToLast(list, 1) == 4);
  REQUIRE(findKthToLast(list, 2) == 3);
  REQUIRE(findKthToLast(list, 3) == 2);
  REQUIRE(findKthToLast(list, 4) == 1);
  REQUIRE(findKthToLast(list, 5) == -1);
  REQUIRE(findKthToLast(list, 1000) == -1);
}

TEST_CASE("ch2.2 findKthToLast - []") {
  LinkedList list;

  REQUIRE(findKthToLast(list, 0) == -1);
}