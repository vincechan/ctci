#ifndef STACK_INCLUDE_
#define STACK_INCLUDE_

#include <list>

class Stack {
 public:
  Stack();
  ~Stack();
  void push(int value);
  int pop();
  int peek();
  bool is_empty();

 private:
  std::list<int> list;
};

#endif