#include "third_party/catch.hpp"

#include <vector>
#include "LinkedList.h"

void deleteMiddle(const LinkedList& list) {
  // TODO: implement
}

TEST_CASE("ch2.3 deleteMiddle") {
  LinkedList list;
  list.insert(1);
  list.insert(2);
  list.insert(3);
  list.insert(4);
  list.insert(5);
  std::vector<int> expected = {1, 2, 4, 5};

  deleteMiddle(list);
  std::vector<int> actual = convertLinkedListToVector(list);

  REQUIRE(expected == actual);
}