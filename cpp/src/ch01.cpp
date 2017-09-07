#include "third_party/catch.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

/******************************************************************************
 * isUnique
 *
 * Determine if a given string has all unique characters.
 */

bool isUnique(const std::string &input) {
  std::unordered_set<char> set;
  for (auto character : input) {
    if (set.find(character) != set.end()) {
      return false;
    }
    set.insert(character);
  }
  return true;
}

// same as isUnique, without using additinal data structure
bool isUniqueNoDataStructure(std::string input) {
  if (input.size() <= 1) {
    return true;
  }

  // sort the input string in place
  std::sort(input.begin(), input.end());

  // iterate the string, if the current char is the same as last char, it's not
  // unique
  char last = input[0];
  for (size_t i = 1; i < input.size(); i++) {
    if (input[i] == last) {
      return false;
    }
    last = input[i];
  }
  return true;
}

TEST_CASE("isUnique") {
  REQUIRE(isUnique("abcde"));
  REQUIRE(isUnique("aabcde") == false);
}

TEST_CASE("isUniqueNoDataStructure") {
  REQUIRE(isUniqueNoDataStructure("abcde"));
  REQUIRE(isUniqueNoDataStructure("aabcde") == false);
}

/******************************************************************************
 * reverse
 *
 * Reverse a null terminated string.
 */
void reverse(char *input) {
  if (input) {
    char *end = input;
    while (*end != '\0') {
      end++;
    }
    end--;

    char *start = input;
    while (start < end) {
      char tmp = *start;
      *start++ = *end;
      *end-- = tmp;
    }
  }
}

TEST_CASE("reverse") {
  char input[] = "abcde";
  reverse(input);
  REQUIRE(strcmp(input, "edcba") == 0);
}

/******************************************************************************
 * isPermutation
 *
 * Determine if two strings are permutation of each other
 */

bool isPermutation(const std::string &first, const std::string &second) {
  if (first.size() == second.size()) {
    std::string s1 = first;
    std::sort(s1.begin(), s1.end());
    std::string s2 = second;
    std::sort(s2.begin(), s2.end());

    for (size_t i = 0; i < s1.size(); i++) {
      if (s1[i] != s2[i]) {
        return false;
      }
    }
    return true;
  }
  return false;
}

TEST_CASE("isPermutation") {
  REQUIRE(isPermutation("", ""));
  REQUIRE(isPermutation("vince", "nicev"));
  REQUIRE(isPermutation("vince", "vinc") == false);
  REQUIRE(isPermutation("first", "second") == false);
}

/******************************************************************************
 * replaceSpaces
 *
 * Replace all spaces ' ' within a string with "%20".
 * The input string will have enough space at the end.
 *  Perform this operation in place.
 *
 * example:
 * input:  "Mr John Smith    "
 * output: "Mr%20John%20Smith"
 */
void replaceSpaces(std::string &input) {
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

TEST_CASE("replaceSpaces") {
  std::string input = "Mr John Smith    ";
  std::string expected = "Mr%20John%20Smith";
  replaceSpaces(input);
  REQUIRE(input == expected);
}

TEST_CASE("replaceSpaces - empty string") {
  std::string input = "";
  std::string expected = "";
  replaceSpaces(input);
  REQUIRE(input == expected);
}

TEST_CASE("replaceSpaces - no space") {
  std::string input = "test";
  std::string expected = "test";
  replaceSpaces(input);
  REQUIRE(input == expected);
}

/******************************************************************************
 * compressString
 *
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

TEST_CASE("compressString") {
  std::string expected = "a2b1c5a3";
  std::string actual = compressString("aabcccccaaa");
  REQUIRE(expected == actual);
}

TEST_CASE("compressString - [aa]") {
  std::string expected = "aa";
  std::string actual = compressString("aa");
  REQUIRE(expected == actual);
}

TEST_CASE("compressString - [aaa]") {
  std::string expected = "a3";
  std::string actual = compressString("aaa");
  REQUIRE(expected == actual);
}

/******************************************************************************
 * zeroRowAndCol
 *
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

bool isElementwiseEqual(const std::vector<std::vector<int>> &m1,
                        const std::vector<std::vector<int>> &m2) {
  if (m1.size() == m2.size() && m1[0].size() == m2[0].size()) {
    for (size_t r = 0; r < m1.size(); r++) {
      for (size_t c = 0; c < m1[0].size(); c++) {
        if (m1[r][c] != m2[r][c]) {
          return false;
        }
      }
    }
    return true;
  }

  return false;
}

TEST_CASE("zeroRowAndCol - 3x3 identity matrix") {
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

TEST_CASE("zeroRowAndCol - 3x3 matrix all ones") {
  // create a 3x3 matrix with all ones element
  std::vector<std::vector<int>> input(3, std::vector<int>(3, 1));

  // expect a 3x3 matrix with all ones elements
  std::vector<std::vector<int>> expected(3, std::vector<int>(3, 1));

  // Act
  zeroRowAndCol(input);

  // Assert
  REQUIRE(isElementwiseEqual(input, expected));
}

TEST_CASE("zeroRowAndCol - 3x3 matrix all zeroes except element (1,1) = 0") {
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