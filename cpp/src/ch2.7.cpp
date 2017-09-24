#include "third_party/catch.hpp"

#include "LinkedList.h"

bool isPalindrome(const LinkedList& list) {
  // TODO: implement
  return true;
}

TEST_CASE("ch2.7 isPalindrome - [1,2,3,2,1]") {
  LinkedList list(std::vector<int>({1, 2, 3, 2, 1}));

  REQUIRE(isPalindrome(list) == true);
}

TEST_CASE("ch2.7 isPalindrome - [1,2,3,4,5]") {
  LinkedList list(std::vector<int>({1, 2, 3, 4, 5}));

  REQUIRE(isPalindrome(list) == false);
}