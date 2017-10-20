#include "third_party/catch.hpp"

#include <list>

/**
 * Implement the sheleter class which operates on a FIFO basis. The built-in
 * linked list maybe used.
 */
enum AnimalType  {
  Cat,
  Dog
};

struct Animal {
  AnimalType type;
  int id;
  Animal(AnimalType type, int id) : type(type), id(id) {}
};

class AnimalShelter {
 public:
  void enqueue(Animal animal) {
    anyQ.push_back(animal);

    if (animal.type == AnimalType::Cat) {
      catQ.push_back(animal);
    }
    else {
      dogQ.push_back(animal);
    }
  }

  Animal dequeueAny() {
    Animal animal = anyQ.front();
    anyQ.pop_front();

    if (animal.type == AnimalType::Cat) {
      catQ.pop_front();
    }
    else {
      dogQ.pop_front();
    }
    return animal;
  }
  
  Animal dequeueDog() {
    Animal animal = dogQ.front();
    dogQ.pop_front();
    anyQ.pop_front();
    return animal;
  }

  Animal dequeueCat() {
    Animal animal = catQ.front();
    anyQ.pop_front();
    catQ.pop_front();
    return animal;
  }

 private:
  std::list<Animal> anyQ;
  std::list<Animal> dogQ;
  std::list<Animal> catQ;
};

TEST_CASE("ch3.7 AnimalShelter - dequeueAny") {
  AnimalShelter shelter;

  shelter.enqueue(Animal(AnimalType::Cat, 1));
  shelter.enqueue(Animal(AnimalType::Dog, 11));
  shelter.enqueue(Animal(AnimalType::Cat, 2));
  shelter.enqueue(Animal(AnimalType::Dog, 22));
  REQUIRE(shelter.dequeueAny().id == 1);
  REQUIRE(shelter.dequeueAny().id == 11);
  REQUIRE(shelter.dequeueAny().id == 2);
  REQUIRE(shelter.dequeueAny().id == 22);
}

TEST_CASE("ch3.7 AnimalShelter") {
  AnimalShelter shelter;

  shelter.enqueue(Animal(AnimalType::Cat, 1));
  shelter.enqueue(Animal(AnimalType::Dog, 11));
  shelter.enqueue(Animal(AnimalType::Cat, 2));
  shelter.enqueue(Animal(AnimalType::Dog, 22));
  REQUIRE(shelter.dequeueDog().id == 11);
  REQUIRE(shelter.dequeueCat().id == 1);
  REQUIRE(shelter.dequeueDog().id == 22);
  REQUIRE(shelter.dequeueCat().id == 2);
}