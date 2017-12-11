#include "third_party/catch.hpp"

#include <string>
#include <unordered_set>
#include <vector>

/**
 * Problem:
 * Implement an algorithm to print all valid (e.g. properly opened and closed)
 * combinations of n-pairs of parentheses).
 *
 * EXAMPLE:
 * Input: 3
 * Output: ((())), (()()), (())(), ()(()), ()()()
 */

/**
 * INPUT: 1 OUTPUT: ()
 * INPUT: 2 OUTPUT: ()(), (())
 * INPUT: 3 OUTPUT: (()()), ((())), ()()(), ()(()), (())()
 */

std::vector<std::string> getAllValidCombos(int n) {
  std::vector<std::string> ans;
  std::unordered_set<std::string> unique;
  if (n == 1) {
    ans.push_back("()");
  } else {
    std::vector<std::string> prev = getAllValidCombos(n - 1);
    for (std::string combo : prev) {
      // insert a "()" after every left parenthesis to generate new combo.
      // since we could generate duplicate, only include the new combo if it's
      // not duplicate
      for (int i = 0; i < combo.size(); i++) {
        if (combo[i] == '(') {
          std::string newCombo = combo;
          newCombo.insert(i + 1, "()");
          if (unique.find(newCombo) == unique.end()) {
            ans.push_back(newCombo);
            unique.insert(newCombo);
          }
        }
      }
      // add a new combo by inserting "()" before the previous combo
      std::string newcombo1 = "()";
      newcombo1.insert(newcombo1.size(), combo);
      if (unique.find(newcombo1) == unique.end()) {
        ans.push_back(newcombo1);
        unique.insert(newcombo1);
      }
    }
  }
  return ans;
}

TEST_CASE("ch9.6 getAllValidCombos - 1") {
  REQUIRE(getAllValidCombos(1) == std::vector<std::string>({"()"}));
}

TEST_CASE("ch9.6 getAllValidCombos - 2") {
  REQUIRE(getAllValidCombos(2) == std::vector<std::string>({"(())", "()()"}));
}

TEST_CASE("ch9.6 getAllValidCombos - 3") {
  REQUIRE(getAllValidCombos(3) ==
          std::vector<std::string>(
              {"(()())", "((()))", "()(())", "(())()", "()()()"}));
}