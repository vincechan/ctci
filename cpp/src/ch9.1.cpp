#include "third_party/catch.hpp"

#include <vector>
/**
 * A child is running up a staircase with n steps, and can hop either 1 step, 2
 * steps, or 3 steps at a time. Implement a method to count how many possible
 * ways the child can run up the stairs
 *
 * Example
 * input: 1   output: 1
 * input: 2   output: 2   [(1,1), (2)]
 * input: 3   output: 4   [(1,1,1), (1,2), (2,1), (3)]
 * input: 4   output: 7   [(1,1,1,1), (1,1,2), (1,2,1), (1,3), (2,1,1), (2,2),
 * (3,1)]
 */

long count_ways_dp(long steps, std::vector<long>& mem) {
  /**
   * w(n) = w(n-1) + w(n-2) + w(n-3)
   */
  if (steps == 1) {
    mem[steps] = 1;
  } else if (steps == 2) {
    mem[steps] = 2;
  } else if (steps == 3) {
    mem[steps] = 4;
  } else {
    if (mem[steps] == 0) {
      mem[steps] = count_ways_dp(steps - 1, mem) +
                   count_ways_dp(steps - 2, mem) +
                   count_ways_dp(steps - 3, mem);
    }
  }
  return mem[steps];
}

long count_ways(long steps) {
  std::vector<long> mem(steps + 1, 0);
  count_ways_dp(steps, mem);
  return mem[steps];
}

TEST_CASE("ch9.1 - count ways") {
  REQUIRE(count_ways(1) == 1);
  REQUIRE(count_ways(2) == 2);
  REQUIRE(count_ways(3) == 4);
  REQUIRE(count_ways(4) == 7);
  REQUIRE(count_ways(5) == 13);
}