#include "third_party/catch.hpp"

#include <stack>
#include <vector>

/**
 * In classic Towers of Hanoi problem, there are 3 towers and N disks of
 * different sizes. Initially the disks are sorted in ascending order of size
 * from top to bottom. Move the disks from the first tower to the last tower
 * using stacks with the following constraints.
 *
 * 1. Only one disk can be moved at a time
 * 2. A disk is slid off the top of one tower onto next one
 * 3. A disk can only be placed on top of a larger tower
 */

void moveDisks(std::stack<int>& source, std::stack<int>& target, std::stack<int>& spare, int itemCount) {
  if (itemCount == 0) {
    return;
  }

  // move (itemCount - 1) items from source to spare
  moveDisks(source, spare, target, itemCount - 1);
  // move 1 (the last item) from source to target
  target.push(source.top());
  source.pop();
  // move (itemCount - 1) items from spare to target
  moveDisks(spare, target, source, itemCount - 1);
}

TEST_CASE("ch3.4 moveDisks") {
    // Arrange
    std::stack<int> t1;
    std::stack<int> t2;
    std::stack<int> t3;
    t1.push(5);
    t1.push(4);
    t1.push(3);
    t1.push(2);
    t1.push(1);

    // Act
    moveDisks(t1, t3, t2, 5);

    std::vector<int> expected = {1,2,3,4,5};
    std::vector<int> actual;
    while (!t3.empty()) {
        actual.push_back(t3.top());
        t3.pop();
    }

    REQUIRE(expected == actual);
}