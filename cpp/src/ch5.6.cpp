#include "third_party/catch.hpp"

/**
 * Swap the even bits with the odd bits in a given integer
 */
int SwapOddEvenBits(int n) {
  int oddBits = n & 0xAAAAAAAA;   // 1010.....
  int evenBits = n & 0x55555555;  // 0101.....
  return (oddBits >> 1) | (evenBits << 1);
}

TEST_CASE("ch5.6 SwapOddEvenBits") {
  // 0110 => 1001
  REQUIRE(SwapOddEvenBits(6) == 9);

  // 100100 => 011000
  //     36 => 24
  REQUIRE(SwapOddEvenBits(36) == 24);
}