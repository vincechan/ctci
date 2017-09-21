#include "third_party/catch.hpp"

#include <string>

/**
 * Compress a string using the counts of repeated characters. If compressed
 * string would not be smaller, return original string
 *
 * example
 * input: aabcccccaaa
 * output: a2b1c5a3
 */
std::string compressString(const std::string &input) {
  std::string output;

  if (input.size() <= 2) {
    output = input;
    return output;
  }

  output.push_back(input[0]);
  char last = input[0];
  int lastCount = 1;
  for (size_t i = 1; i < input.size(); i++) {
    if (input[i] == last) {
      lastCount++;
      if (i == input.size() - 1) {
        output.append(std::to_string(lastCount));
      }
    }

    if (input[i] != last) {
      output.append(std::to_string(lastCount));
      output.push_back(input[i]);
      lastCount = 1;
      last = input[i];
    }
  }

  // return original string if the compressed string is longer
  if (output.size() > input.size()) {
    output = input;
  }

  return output;
}

TEST_CASE("ch1.5 compressString - [a2b1c5a3]") {
  std::string expected = "a2b1c5a3";
  std::string actual = compressString("aabcccccaaa");
  REQUIRE(expected == actual);
}

TEST_CASE("ch1.5 compressString - [aa]") {
  std::string expected = "aa";
  std::string actual = compressString("aa");
  REQUIRE(expected == actual);
}

TEST_CASE("ch1.5 compressString - [aaa]") {
  std::string expected = "a3";
  std::string actual = compressString("aaa");
  REQUIRE(expected == actual);
}
