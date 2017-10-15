#include "third_party/catch.hpp"

#include <iostream>
#include <stack>
#include <unordered_set>

struct Node {
  Node* next;
  int value;
  Node() : next(nullptr) {}
  Node(Node* next) : next(next) {}
};

/**
 * determine if there is a route between two nodes
 */
bool is_connected(Node* a, Node* b) {
  if (a == nullptr || b == nullptr) {
    return false;
  }

  std::unordered_set<Node*> visited;
  std::stack<Node*> s;

  s.push(a);
  visited.insert(a);

  while (!s.empty()) {
    Node* current = s.top();
    s.pop();

    // check if we found b, if we found b, it's connected
    if (current == b) {
      return true;
    }

    // add neighbor to be explored
    if (current->next != nullptr) {
      if (visited.find(current->next) == visited.end()) {
        visited.insert(current->next);
        s.push(current->next);
      }
    }
  }

  return false;
}

TEST_CASE("ch4.2 isConnected - connected") {
  Node* n1 = new Node();
  n1->next = new Node();
  n1->next->next = new Node();
  n1->next->next->next = new Node();
  Node* a = n1;
  Node* b = n1->next->next;

  bool connected = is_connected(a, b);

  REQUIRE(connected == true);
}

TEST_CASE("ch4.2 isConnected - not connected") {
  Node* n1 = new Node();
  n1->next = new Node();
  n1->next->next = new Node();
  n1->next->next->next = new Node();
  Node* a = n1;
  Node* b = new Node();

  bool connected = is_connected(a, b);

  REQUIRE(connected == false);
}