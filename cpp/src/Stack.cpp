#include "Stack.h"

Stack::Stack() {}

Stack::~Stack() {}

void Stack::push(int value) { list.push_front(value); }

int Stack::pop() {
  if (list.size() == 0) {
    throw std::runtime_error("empty stack");
  }
  int value = list.front();
  list.pop_front();
  return value;
}

int Stack::peek() {
  if (list.size() == 0) {
    throw std::runtime_error("empty stack");
  }
  return list.front();
}

bool Stack::is_empty() { return list.size() == 0; }
