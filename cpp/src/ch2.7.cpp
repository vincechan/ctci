#include "third_party/catch.hpp"

#include "LinkedList.h"

bool isPalindrome(const LinkedList& list) {
  if (list.head == nullptr) {
    return false;
  }

  // store a copy of the list in reverse order
  LinkedList reverse;
  Node* runner = list.head;
  while (runner != nullptr) {
    reverse.push_front(runner->value);
    runner = runner->next;
  }

  // traverse both list, every item should have the same value if it's a
  // palindrome
  Node* first = list.head;
  Node* second = reverse.head;
  while (first != nullptr) {
    if (first->value != second->value) {
      return false;
    }
    first = first->next;
    second = second->next;
  }

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
