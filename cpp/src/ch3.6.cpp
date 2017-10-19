#include "third_party/catch.hpp"

#include <stack>

/**
 * Sort a stack in ascending order (biggest item on top). Additional stacks
 * maybe used, but no other data structures can be used. The stack should
 * support push, pop, peek, and isEmpty
 */
std::stack<int> sortStack(std::stack<int>& s) {
  std::stack<int> sorted;  // put sorted items on this stack, smallest on top

  while (!s.empty()) {
    int temp = s.top();
    s.pop();

    // find a location to put the items in sorted stack. if the location is not
    // on top, move the items from sorted back to s
    while (!sorted.empty() && temp < sorted.top()) {
      s.push(sorted.top());
      sorted.pop();
    }

    sorted.push(temp);
  }
  return sorted;
}

TEST_CASE("ch3.6 sortStack") {
  std::stack<int> s;
  s.push(4);
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(5);
  std::vector<int> expected = {5, 4, 3, 2, 1};

  std::stack<int> sorted = sortStack(s);

  std::vector<int> actual;
  while (!sorted.empty()) {
    actual.push_back(sorted.top());
    sorted.pop();
  }

  REQUIRE(expected == actual);
}