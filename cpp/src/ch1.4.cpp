#include "third_party/catch.hpp"

#include <string>

/**
 * Replace all spaces ' ' within a string with "%20".
 * The input string will have enough space at the end.
 *  Perform this operation in place.
 *
 * example:
 * input:  "Mr John Smith    "
 * output: "Mr%20John%20Smith"
 */
void replaceSpaces(std::string& input) {
  int end = input.size() - 1;
  int cur = input.size() - 1;

  // find and set cur to first non space character from the end
  while (cur > 0) {
    if (input[cur] != ' ') {
      break;
    }
    cur--;
  }

  // walk the string from cur position (first non space position from the end),
  // copy each character to the end of the string
  while (cur > 0) {
    if (input[cur] == ' ') {
      input[end--] = '0';
      input[end--] = '2';
      input[end--] = '%';
      cur--;
    } else {
      input[end--] = input[cur--];
    }
  }
}

TEST_CASE("ch1.4 replaceSpaces - [Mr John Smith    ]") {
  std::string input = "Mr John Smith    ";
  std::string expected = "Mr%20John%20Smith";
  replaceSpaces(input);
  REQUIRE(input == expected);
}

TEST_CASE("ch1.4 replaceSpaces - empty string") {
  std::string input = "";
  std::string expected = "";
  replaceSpaces(input);
  REQUIRE(input == expected);
}

TEST_CASE("ch1.4 replaceSpaces - no space") {
  std::string input = "test";
  std::string expected = "test";
  replaceSpaces(input);
  REQUIRE(input == expected);
}