#include "third_party/catch.hpp"

#include <algorithm>
#include <string>
#include <unordered_set>

/**
 * Determine if a given string has all unique characters.
 */
bool isUnique(const std::string& input) {
  std::unordered_set<char> set;
  for (auto character : input) {
    if (set.find(character) != set.end()) {
      return false;
    }
    set.insert(character);
  }
  return true;
}

/**
 * Same as isUnique, except without using additinal data structure
 */
bool isUnique2(std::string input) {
  if (input.size() <= 1) {
    return true;
  }

  // sort the input string in place
  std::sort(input.begin(), input.end());

  // iterate the string, if the current char is the same as last char,
  // it's not unique
  char last = input[0];
  for (size_t i = 1; i < input.size(); i++) {
    if (input[i] == last) {
      return false;
    }
    last = input[i];
  }
  return true;
}

TEST_CASE("ch1.1 isUnique") {
  REQUIRE(isUnique("abcde"));
  REQUIRE(isUnique("aabcde") == false);
}

TEST_CASE("ch1.1 isUnqiue2") {
  REQUIRE(isUnique2("abcde"));
  REQUIRE(isUnique2("aabcde") == false);
}
