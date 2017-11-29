#include "third_party/catch.hpp"

/**
 * Determine the number of bits required to convert integer a to b
 */
int CountDiffBits(int a, int b) {
  // get the diff between a & b
  int diff = a ^ b;

  // count the number of 1s in the diff
  int count = 0;
  for (int c = diff; c != 0; c = c >> 1) {
    count = count + (c & 1);
  }
  return count;
}

TEST_CASE("ch5.5 bits difference") {
  // a = 11111   b = 1110  output: 2
  REQUIRE(CountDiffBits(31, 14) == 2);

  // a = 10101   b = 10001  output: 1
  REQUIRE(CountDiffBits(21, 17) == 1);
}