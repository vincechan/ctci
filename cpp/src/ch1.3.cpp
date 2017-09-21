#include "third_party/catch.hpp"

#include <algorithm>
#include <string>

bool isPermutation(const std::string& first, const std::string& second) {
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

TEST_CASE("ch1.3 isPermutation") {
  REQUIRE(isPermutation("", ""));
  REQUIRE(isPermutation("vince", "nicev"));
  REQUIRE(isPermutation("vince", "vinc") == false);
  REQUIRE(isPermutation("first", "second") == false);
}
