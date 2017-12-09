#include "third_party/catch.hpp"

/**
 * A magic index in an array A[1...n-1] is defined to be an index such that A[i]
 * = i. Given a sorted array of distinct integers, write a method to find a
 * magic index, if one exists, in array A
 */

bool has_magic_index_brute_force(const std::vector<int>& A) {
  for (int i = 0; i < A.size(); i++) {
    if (i == A[i]) return true;
  }
  return false;
}

bool has_magic_index_bs(const std::vector<int>& A) {
  /**
   * use binary search like method to scan for magic index. Note, this method
   * does not work if A contains non distinct item
   */
  int left = 0;
  int right = A.size() - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (mid == A[mid]) return true;
    if (mid > A[mid]) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return false;
}

bool has_magic_index(const std::vector<int>& A) {
  return has_magic_index_brute_force(A);
}

TEST_CASE("ch9.3 has magic index") {
  REQUIRE(has_magic_index({-5, 0, 2, 5}) == true);
  REQUIRE(has_magic_index({-5, 0, 4, 5}) == false);
  REQUIRE(has_magic_index_bs({-5, 0, 2, 5}) == true);
  REQUIRE(has_magic_index_bs({-5, 0, 4, 5}) == false);
}