#include "third_party/catch.hpp"

#include <algorithm>
#include <string>


/**
 * Determine if s2 is a substring of s1.
 */
bool isSubstring(const std::string &s1, const std::string &s2) {
  size_t found = s1.find(s2);
  if (found != std::string::npos) {
    return true;
  }
  return false;
}

/**
 * Determine if s2 is a rotation of s1.
 * e can use isSubString function one time
 *
 * e.g. "waterbottle" is a rotation of "erbottlewat"
 */
bool isRotation(const std::string &s1, const std::string &s2) {
  std::string haystack = s1 + s1;
  return isSubstring(haystack, s2);
}

TEST_CASE("ch1.8 isRotation") {
  REQUIRE(isRotation("waterbottle", "erbottlewat") == true);
  REQUIRE(isRotation("waterbottle", "waterbottl0") == false);
}
