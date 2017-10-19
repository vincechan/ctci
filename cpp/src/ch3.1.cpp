#include "third_party/catch.hpp"

#include <iostream>
#include <vector>

/**
 * Use a single array to implement 3 stacks
 */

class ThreeStacks {
 public:
  ThreeStacks(int capacity = 100) : stackCapacity(capacity) {
    // init array
    pa = new int[stackCapacity * 3];
    for (int i = 0; i < stackCapacity * 3; i++) {
      pa[i] = 0;
    }
    // init the top index for all stacks to -1
    for (auto& i : stackTopIndices) {
      i = -1;
    }
  }
  ~ThreeStacks() { delete pa; }

  bool isEmpty(int stackNum) { return stackTopIndices[stackNum] == -1; }

  void push(int stackNum, int value) {
    if (stackTopIndices[stackNum] == stackCapacity - 1) {
      throw std::runtime_error("the target stack is full");
    }
    stackTopIndices[stackNum]++;
    int index = getArrayIndex(stackNum);
    pa[index] = value;
  }
  int pop(int stackNum) {
    if (isEmpty(stackNum)) {
      throw std::runtime_error("target stack is empty");
    }
    int index = getArrayIndex(stackNum);
    int value = pa[index];
    stackTopIndices[stackNum]--;
    return value;
  }

 private:
  int* pa;  // array to store stacks
  int stackCapacity;
  int stackTopIndices[3];
  /**
   * Get array index for the given stack
   */
  int getArrayIndex(int stackNum) {
    return stackNum * stackCapacity + stackTopIndices[stackNum];
  }
};

TEST_CASE("ch3.1 ThreeStacks") {
  ThreeStacks stacks(5);
  for (int i = 0; i < 3; i++) {
    stacks.push(0, i);       // push 0,1,2 to stack 0
    stacks.push(1, 10 + i);  // push 10,11,12 to stack 1
    stacks.push(2, 20 + i);  // push 20,21,22 to stack 2
  }

  std::vector<int> actual;
  for (int i = 0; i < 3; i++) {
    actual.push_back(stacks.pop(0));
    actual.push_back(stacks.pop(1));
    actual.push_back(stacks.pop(2));
  }

  while (stacks.isEmpty(2) == false) {
    std::cout << stacks.pop(2) << std::endl;
  }

  std::vector<int> expected = {2, 12, 22, 1, 11, 21, 0, 10, 20};

  REQUIRE(expected == actual);
}