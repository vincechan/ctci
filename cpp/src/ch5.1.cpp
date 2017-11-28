#include "third_party/catch.hpp"

/**
 * Given two 32-bit numbers N and M, and two bit positions i and j. Write a
 * method to insert M into N such that M starts at bit j and ends at bit i.
 * EXAMPLE:
 * N      = 10000000000,  i = 2,  j = 6
 * M      =     10011
 * Output = 10001001100
 */
int update_bits(int N, int M, int i, int j) {
  // clear [i,j] bits in N
  // create a mask that will have zeros in [i,j] and ones everywhere else
  int allOnes = ~0;
  int N_mask = allOnes & (1 << (j + 1));  // this creates 1111110000000
  N_mask = N_mask | ~(1 << i);            // this creates 1111110000011
  int num = N & N_mask;                   // this clears the [i,j] bits in N

  // insert M into N
  int M_mask = M << i;  // shift M by i
  return num | M_mask;  // insert M into N by "or-ing" the M_mask
}

TEST_CASE("ch5.1 update_bits") {
  // N = 10000000000
  // M =     10011
  // i = 2
  // j = 6
  REQUIRE(update_bits(0b10000000000, 0b10011, 2, 6) == 0b10001001100);
}