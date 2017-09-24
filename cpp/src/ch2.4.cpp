#include "third_party/catch.hpp"

#include <vector>
#include "LinkedList.h"

/**
 * partition a list such that all values < x come before x and all values > x
 * come after
 */
void partition(const LinkedList& list, int x) {}

TEST_CASE("ch2.4 partition") {
  LinkedList list(std::vector<int>({1, 3, 4, 5, 4}));

  partition(list, 3);
  std::vector<int> actual = list.toVector();

  REQUIRE(actual[0] < 3);
  REQUIRE(actual[1] < 3);
  REQUIRE(actual[2] == 3);
  REQUIRE(actual[3] > 3);
  REQUIRE(actual[4] > 3);
}