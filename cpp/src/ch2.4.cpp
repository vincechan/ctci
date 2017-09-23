#include "third_party/catch.hpp"

#include <vector>
#include "LinkedList.h"

/**
 * partition a list such that all values < x come before x and all values > x
 * come after
 */
void partition(const LinkedList& list, int x) {}

TEST_CASE("ch2.4 partition") {
  LinkedList list;
  list.insert(1);
  list.insert(3);
  list.insert(5);
  list.insert(2);
  list.insert(4);
  std::vector<int> expected = {1, 2, 3, 4, 5};

  partition(list, 3);
  std::vector<int> actual = convertLinkedListToVector(list);

  REQUIRE(expected == actual);
}