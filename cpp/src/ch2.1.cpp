#include "third_party/catch.hpp"

#include <vector>
#include "LinkedList.h"
#include "test_helper.h"

/**
 * remove duplicates from unsorted linked list
 */
void removeDuplicates(const LinkedList& list) {
  Node* first = list.head;

  while (first != nullptr) {
    Node* second = first;
    while (second->next != nullptr) {
      if (first->data == second->next->data) {
        // delete duplicate
        Node* deleteNode = second->next;
        second->next = second->next->next;
        delete deleteNode;
        deleteNode = nullptr;
      } else {
        second = second->next;
      }
    }
    first = first->next;
  }
}

/**
 * Copy all values inside a LinkedList into a vector to facilitate testing.
 */
std::vector<int> convertLinkedListToVector(const LinkedList& list) {
  std::vector<int> v;
  Node* cur = list.head;
  while (cur != nullptr) {
    v.push_back(cur->data);
    cur = cur->next;
  }
  return v;
}

TEST_CASE("ch2.1 removeDuplicates - [3,2,1,3]") {
  std::vector<int> expected = {3, 2, 1};
  LinkedList list;
  list.insert(3);
  list.insert(2);
  list.insert(1);
  list.insert(3);

  removeDuplicates(list);
  std::vector<int> actual = convertLinkedListToVector(list);

  REQUIRE(expected == actual);
}

TEST_CASE("ch2.1 removeDuplicates - [3,3,3,3]") {
  std::vector<int> expected = {3};
  LinkedList list;
  list.insert(3);
  list.insert(3);
  list.insert(3);
  list.insert(3);

  removeDuplicates(list);
  std::vector<int> actual = convertLinkedListToVector(list);

  REQUIRE(expected == actual);
}

TEST_CASE("ch2.1 removeDuplicates - [3,2,1]") {
  std::vector<int> expected = {3, 2, 1};
  LinkedList list;
  list.insert(3);
  list.insert(2);
  list.insert(1);

  removeDuplicates(list);
  std::vector<int> actual = convertLinkedListToVector(list);

  REQUIRE(expected == actual);
}

TEST_CASE("ch2.1 removeDuplicates - []") {
  std::vector<int> expected = {};
  LinkedList list;

  removeDuplicates(list);
  std::vector<int> actual = convertLinkedListToVector(list);

  REQUIRE(expected == actual);
}