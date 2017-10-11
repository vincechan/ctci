#include "third_party/catch.hpp"

/**
 * Implement the sheleter class which operates on a FIFO basis. The built-in
 * linked list maybe used.
 */
class Shelter {
 public:
  void enqueue(int animalId);
  int dequeueAny();
  int dequeueDog();
  int dequeueCat();
};