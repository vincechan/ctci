#include "third_party/catch.hpp"

#include <vector>
#include "LinkedList.h"

void deleteMiddle(const LinkedList& list) {
  if (list.head == nullptr) {
    return;
  }

  // Use a fast and a slow cursor, for every 1 move slow cursor makes, fast
  // cursor will make 2 moves. When fast cursor gets to the end, slow cursor
  // will be at the middle
  Node* fast = list.head;
  Node* slow = list.head;
  while (fast->next != nullptr && fast->next->next != nullptr) {
    fast = fast->next->next;
    slow = slow->next;
  }

  Node* deleteNode = slow->next;
  slow->data = slow->next->data;
  slow->next = slow->next->next;
  delete deleteNode;
}

TEST_CASE("ch2.3 deleteMiddle - [1,2,3,4,5]") {
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

TEST_CASE("ch2.3 deleteMiddle - [1,2,3,4]") {
  LinkedList list;
  list.insert(1);
  list.insert(2);
  list.insert(3);
  list.insert(4);
  std::vector<int> expected = {1, 3, 4};

  deleteMiddle(list);
  std::vector<int> actual = convertLinkedListToVector(list);

  REQUIRE(expected == actual);
}

TEST_CASE("ch2.3 deleteMiddle - []") {
  LinkedList list;
  std::vector<int> expected;

  deleteMiddle(list);
  std::vector<int> actual = convertLinkedListToVector(list);

  REQUIRE(expected == actual);
}