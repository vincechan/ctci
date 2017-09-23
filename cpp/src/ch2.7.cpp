#include "third_party/catch.hpp"

#include "LinkedList.h"

bool isPalindrome(const LinkedList& list) {
  // TODO: implement
  return true;
}

TEST_CASE("ch2.7 isPalindrome - [1,2,3,2,1]") {
  LinkedList list;
  list.insert(1);
  list.insert(2);
  list.insert(3);
  list.insert(2);
  list.insert(1);

  REQUIRE(isPalindrome(list) == true);
}

TEST_CASE("ch2.7 isPalindrome - [1,2,3,4,5]") {
  LinkedList list;
  list.insert(1);
  list.insert(2);
  list.insert(3);
  list.insert(4);
  list.insert(5);

  REQUIRE(isPalindrome(list) == false);
}