#include "third_party/catch.hpp"

#include <list>
#include <vector>

/**
 * Implement a SetOfStacks that composed of multiple stacks. Create a new stack
 * when previous one has reached capacity.
 * Implement a popAt function which performs a pop operation on a specific
 * stack.
 */

class SubStack {
 public:
  SubStack() {}
  ~SubStack() {}
  void push(int value) { list_.push_front(value); }
  int pop() {
    int value = list_.front();
    list_.pop_front();
    return value;
  }
  int size() { return list_.size(); }

 private:
  std::list<int> list_;
};

class SetOfStacks {
 public:
  SetOfStacks(int capacity) : capacity(capacity) {}
  ~SetOfStacks() {}

  void push(int value) {
    // find the stack to push on to
    SubStack* target = nullptr;
    // if there are existing stacks
    if (substacks.size() > 0) {
      // look at the last stack to see if it has space
      target = substacks.back();
      // create new stack if there are no more space
      if (target->size() >= capacity) {
        target = new SubStack();
        substacks.push_back(target);
      }
    } else {
      // there are no stacks yet, create one
      target = new SubStack();
      substacks.push_back(target);
    }
    target->push(value);
  }

  int pop() {
    if (substacks.size() == 0) {
      throw std::runtime_error("empty stack");
    }

    SubStack* target = substacks.back();
    int value = target->pop();
    // if we poped the last item from the stack, remove the stack
    if (target->size() == 0) {
      substacks.pop_back();
      delete target;
    }
    return value;
  }

  int popAt(int index) {
    SubStack* target = substacks[index];
    return target->pop();
  }

 private:
  std::vector<SubStack*> substacks;
  int capacity;
};

TEST_CASE("ch3.3 SetOfStacks") {
  SetOfStacks sos(5);
  for (int i = 1; i <= 15; i++) {
    sos.push(i);
  }

  REQUIRE(sos.pop() == 15);
  REQUIRE(sos.pop() == 14);
  REQUIRE(sos.pop() == 13);
  REQUIRE(sos.pop() == 12);
  REQUIRE(sos.pop() == 11);
}

TEST_CASE("ch3.3 SetOfStacks - popAt") {
  SetOfStacks sos(5);
  for (int i = 1; i <= 16; i++) {
    sos.push(i);
  }

  REQUIRE(sos.popAt(3) == 16);
  REQUIRE(sos.popAt(2) == 15);
  REQUIRE(sos.popAt(1) == 10);
  REQUIRE(sos.popAt(0) == 5);
}