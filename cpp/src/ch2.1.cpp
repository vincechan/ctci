#include "third_party/catch.hpp"

#include <iostream>
#include <unordered_set>
#include <vector>
#include "LinkedList.h"
#include "test_helper.h"

/**
 * remove duplicates from unsorted linked list. No additional data structure
 */
void removeDuplicates(const LinkedList& list) {
  Node* target = list.head;
  while (target != nullptr) {
    Node* runner = target;
    while (runner->next != nullptr) {
      if (runner->next->value == target->value) {
        Node* duplicate = runner->next;
        std::cout << duplicate->value << std::endl;
        std::cout << runner->next << std::endl;
        std::cout << runner->next->next << std::endl;
        runner->next = runner->next->next;
        // delete duplicate;
      } else {
        runner = runner->next;
      }
      std::cout << "runner " << runner->next << std::endl;
    }
    target = target->next;
  }
}

TEST_CASE("ch2.1 removeDuplicates - [3,2,1,3]") {
  // Arrange
  LinkedList list(std::vector<int>({3, 2, 1, 3}));
  std::vector<int> expected = {3, 2, 1};

  // Act
  removeDuplicates(list);

  // Assert
  REQUIRE(expected == list.toVector());
}

TEST_CASE("ch2.1 removeDuplicates - [3,3,3,3]") {
  LinkedList list(std::vector<int>({3, 3, 3, 3}));
  std::vector<int> expected = {3};

  removeDuplicates(list);

  REQUIRE(expected == list.toVector());
}

TEST_CASE("ch2.1 removeDuplicates - [3,2,1]") {
  LinkedList list(std::vector<int>({3, 2, 1}));
  std::vector<int> expected = {3, 2, 1};

  removeDuplicates(list);

  REQUIRE(expected == list.toVector());
}

TEST_CASE("ch2.1 removeDuplicates - []") {
  std::vector<int> expected = {};
  LinkedList list;

  removeDuplicates(list);

  REQUIRE(expected == list.toVector());
}