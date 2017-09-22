#include "third_party/catch.hpp"

#include "LinkedList.h"

/**
 * Find k th to the last element. Return -1 if it doesn't exist.
 */
int findKthToLast(const LinkedList& list, int k) {
  // TODO: implement
  return 0;
}

TEST_CASE("ch2.2 findKthToLast") {
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
}