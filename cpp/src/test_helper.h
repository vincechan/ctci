#ifndef TEST_HELPER_INCLUDED_
#define TEST_HELPER_INCLUDED_

#include <vector>

/**
 * Determine is two vectors are elementwise equal.
 */
inline bool isElementwiseEqual(const std::vector<std::vector<int>> &m1,
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

#endif