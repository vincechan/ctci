#include "third_party/catch.hpp"

#include "test_helper.h"
#include <vector>


/**
 * rotate a NxN matric by 90 degress right
 */
void rotateRight90(std::vector<std::vector<int>> &input) {
  int n = input.size();

  // rotate the matrix
  // rotated matrix row and col will be given by
  //   rotated_row = input_col
  //   rotated_col = N - 1 - input_row
  auto rotated = input;
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      rotated[c][n - 1 - r] = input[r][c];
    }
  }

  input = rotated;
}

TEST_CASE("1.6 rotateRight90") {
  // Arrange
  std::vector<std::vector<int>> input;
  input.push_back(std::vector<int>({1, 2, 3, 4}));
  input.push_back(std::vector<int>({5, 6, 7, 8}));
  input.push_back(std::vector<int>({9, 10, 11, 12}));
  input.push_back(std::vector<int>({13, 14, 15, 16}));

  std::vector<std::vector<int>> expected;
  expected.push_back(std::vector<int>({13, 9, 5, 1}));
  expected.push_back(std::vector<int>({14, 10, 6, 2}));
  expected.push_back(std::vector<int>({15, 11, 7, 3}));
  expected.push_back(std::vector<int>({16, 12, 8, 4}));

  // Act
  rotateRight90(input);

  // Assert
  REQUIRE(isElementwiseEqual(input, expected));
}