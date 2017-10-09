#include "third_party/catch.hpp"

#include <limits>
#include <list>

/**
 * Implement a stack in addition to push and pop, also has a min function which
 * returns the smallest element. push, pop, and min should run in O(1) time;
 */
class MinStack {
 public:
  MinStack(){};
  ~MinStack(){};
  void push(int value) {
    list_.push_front(value);
    if (value <= min_) {
      min_list_.push_front(value);
      min_ = value;
    }
  };

  int pop() {
    int value = list_.front();
    list_.pop_front();
    if (value == min_) {
      min_list_.pop_front();
      min_ = min_list_.front();
    }
    return value;
  };

  int min() {
    if (list_.size() == 0) {
      return std::numeric_limits<int>::max();  // error, empty list
    }
    return min_;
  };

 private:
  int min_ = std::numeric_limits<int>::max();
  std::list<int> list_;
  // store the current min value
  std::list<int> min_list_;
};

TEST_CASE("ch3.2 MinStack") {
  MinStack stack;
  stack.push(5);
  stack.push(4);
  stack.push(3);
  stack.push(2);
  stack.push(1);
  stack.push(0);

  REQUIRE(stack.min() == 0);
  stack.pop();
  stack.pop();
  REQUIRE(stack.min() == 2);
  stack.pop();
  stack.pop();
  REQUIRE(stack.min() == 4);
  stack.pop();
  REQUIRE(stack.min() == 5);
}