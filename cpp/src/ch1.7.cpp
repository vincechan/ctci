#include "third_party/catch.hpp"

#include "test_helper.h"
#include <vector>

/**
 * Given a MxN matrix, if an element is zero,  zero out the corresponding row
 * and column
 */
void zeroRowAndCol(std::vector<std::vector<int>> &matrix) {
  size_t row_count = matrix.size();
  size_t col_count = matrix[0].size();

  std::vector<bool> zero_rows(row_count, false);
  std::vector<bool> zero_cols(col_count, false);

  for (size_t r = 0; r < row_count; r++) {
    for (size_t c = 0; c < col_count; c++) {
      if (matrix[r][c] == 0) {
        zero_rows[r] = true;
        zero_cols[c] = true;
      }
    }
  }

  for (size_t r = 0; r < row_count; r++) {
    for (size_t c = 0; c < col_count; c++) {
      if (zero_rows[r] || zero_cols[c]) {
        matrix[r][c] = 0;
      }
    }
  }
}

TEST_CASE("ch1.7 zeroRowAndCol - 3x3 identity matrix") {
  // create a 3x3 identity matrix
  std::vector<std::vector<int>> input(3, std::vector<int>(3, 0));
  input[0][0] = 1;
  input[1][1] = 1;
  input[2][2] = 1;

  // expect a 3x3 matrix with all zero elements
  std::vector<std::vector<int>> expected(3, std::vector<int>(3, 0));

  // Act
  zeroRowAndCol(input);

  // Assert
  REQUIRE(isElementwiseEqual(input, expected));
}

TEST_CASE("ch1.7 zeroRowAndCol - 3x3 matrix all ones") {
  // create a 3x3 matrix with all ones element
  std::vector<std::vector<int>> input(3, std::vector<int>(3, 1));

  // expect a 3x3 matrix with all ones elements
  std::vector<std::vector<int>> expected(3, std::vector<int>(3, 1));

  // Act
  zeroRowAndCol(input);

  // Assert
  REQUIRE(isElementwiseEqual(input, expected));
}

TEST_CASE(
    "ch1.7 zeroRowAndCol - 3x3 matrix all zeroes except element (1,1) = 0") {
  // create a 3x3 matrix with all ones element
  std::vector<std::vector<int>> input(3, std::vector<int>(3, 1));
  input[1][1] = 0;

  // expect a matrix with second row and second column to be all zeroes
  std::vector<std::vector<int>> expected(3, std::vector<int>(3, 1));
  for (int i = 0; i < 3; i++) {
    expected[i][1] = 0;
    expected[1][i] = 0;
  }

  // Act
  zeroRowAndCol(input);

  // Assert
  REQUIRE(isElementwiseEqual(input, expected));
}
