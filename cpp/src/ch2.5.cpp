#include "third_party/catch.hpp"

#include <vector>
#include "LinkedList.h"
#include "test_helper.h"

/**
 * Add two numbers where each number is represented as a linked list. The
 * number is stored is reversed order
 *
 * Example:
 * Input (7->1->6) + (5->9->2)
 * Output (2->1->9)
 * 617 + 295 = 912
 */
LinkedList addTwoNumbers(const LinkedList& num1, const LinkedList& num2) {
  LinkedList answer;
  return answer;
}

TEST_CASE("ch2.5 addTwoNumbers") {
  LinkedList num1;
  num1.insert(7);
  num1.insert(1);
  num1.insert(6);
  LinkedList num2;
  num2.insert(5);
  num2.insert(9);
  num2.insert(2);
  std::vector<int> expected = {2, 1, 9};

  std::vector<int> actual =
      convertLinkedListToVector(addTwoNumbers(num1, num2));

  REQUIRE(expected == actual);
}