#include "third_party/catch.hpp"

#include "Stack.h"

/**
 * Implement a queue using 2 stacks
 */
class TwoStackQueue {
 public:
  TwoStackQueue() {}
  ~TwoStackQueue() {}

  void enqueue(int value) { inStack.push(value); }

  int dequeue() {
    if (outStack.is_empty()) {
      transfer();
    }
    if (outStack.is_empty()) {
      throw std::runtime_error("queue is empty");
    }
    return outStack.pop();
  }

  /**
   * transfer all items from inStack to outStack
   * after transfer, the items in outStack will be in queue (FIFO) order
   */
  void transfer() {
    while (!inStack.is_empty()) {
      outStack.push(inStack.pop());
    }
  }

 private:
  Stack inStack;
  Stack outStack;
};

TEST_CASE("ch3.5 TwoStackQueue") {
  TwoStackQueue queue;

  for (int i = 1; i <= 10; i++) {
    queue.enqueue(i);
  }
  REQUIRE(queue.dequeue() == 1);

  for (int i = 11; i <= 20; i++) {
    queue.enqueue(i);
  }
  REQUIRE(queue.dequeue() == 2);
}