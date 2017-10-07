#include "third_party/catch.hpp"

#include <vector>
#include "LinkedList.h"
#include "test_helper.h"

/**
 * Add two numbers where each number is represented as a linked list. The
 * number is stored in reversed order
 *
 * Example:
 * Input (7->1->6) + (5->9->2)
 * Output (2->1->9)
 * 617 + 295 = 912
 */
LinkedList addTwoNumbers(const LinkedList& num1, const LinkedList& num2) {
  LinkedList answer;

  int carry = 0;
  Node* cursor = nullptr;
  Node* cursor1 = num1.head;  // iterate first number
  Node* cursor2 = num2.head;  // iterate second number
  while (cursor1 != nullptr || cursor2 != nullptr || carry != 0) {
    // handle num1
    int v1 = 0;
    if (cursor1 != nullptr) {
      v1 = cursor1->value;
      cursor1 = cursor1->next;
    }

    // handle num2
    int v2 = 0;
    if (cursor2 != nullptr) {
      v2 = cursor2->value;
      cursor2 = cursor2->next;
    }

    if (cursor == nullptr) {
      cursor = new Node(nullptr, (v1 + v2 + carry) % 10);
      answer.head = cursor;
    } else {
      cursor->next = new Node(nullptr, (v1 + v2 + carry) % 10);
      cursor = cursor->next;
    }

    carry = v1 + v2 >= 10 ? 1 : 0;
  }

  return answer;
}

TEST_CASE("ch2.5 addTwoNumbers - [7,1,6], [5,9,2]") {
  LinkedList num1(std::vector<int>({7, 1, 6}));
  LinkedList num2(std::vector<int>({5, 9, 2}));
  std::vector<int> expected = {2, 1, 9};

  std::vector<int> actual = addTwoNumbers(num1, num2).toVector();

  REQUIRE(expected == actual);
}

TEST_CASE("ch2.5 addTwoNumbers - [1], [2,2]") {
  LinkedList num1(std::vector<int>({1}));
  LinkedList num2(std::vector<int>({2, 2}));
  std::vector<int> expected = {3, 2};

  std::vector<int> actual = addTwoNumbers(num1, num2).toVector();

  REQUIRE(expected == actual);
}