#include "third_party/catch.hpp"

#include <vector>

/**
 * Imagine a robot sitting on the upper left corner of an X by Y grid. The robot
 * can only move in two directions: right and down. How many possible paths are
 * there for the robot to go from (0,0) to (X,Y)?
 */

int count_paths_dp(int r, int c, std::vector<std::vector<int>>& mem) {
  if (r < 0) return 0;
  if (c < 0) return 0;
  if (r == 0 && c == 0) return 1;
  if (mem[r][c] == 0) {
    mem[r][c] = count_paths_dp(r, c - 1, mem) + count_paths_dp(r - 1, c, mem);
  }
  return mem[r][c];
}

int count_paths(int X, int Y) {
  std::vector<std::vector<int>> mem(Y, std::vector<int>(X, 0));
  return count_paths_dp(Y - 1, X - 1, mem);
}

TEST_CASE("ch9.2 count_paths") { REQUIRE(count_paths(4, 4) == 20); }