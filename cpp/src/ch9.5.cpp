#include "third_party/catch.hpp"

#include <vector>

using namespace std;

/**
 * write a method to return all permutations of a string
 */

vector<string> getAllPermutations(const string& s, int n) {
  vector<string> ans;
  if (n == 0) {
    ans.push_back(s.substr(0, 1));
  } else {
    vector<string> previous = getAllPermutations(s, n - 1);
    // create new permutations by inserting the current char in every available
    // positions in all previous permutations. e.g. if current char is 'c' and a
    // previous permutation is "ab", create new permutations of "cab", "acb",
    // "abc"
    char current = s.at(n);
    for (const string& p : previous) {
      for (int i = 0; i <= p.size(); i++) {
        string new_permutation = p;
        new_permutation.insert(i, 1, current);
        ans.push_back(new_permutation);
      }
    }
  }
  return ans;
}

vector<string> getAllPermutations(const string& s) {
  vector<string> ans;
  if (s.size() > 0) {
    ans = getAllPermutations(s, s.size() - 1);
  }
  return ans;
}

TEST_CASE("ch9.5 getAllPermutations - 0") {
  string input = "";
  vector<string> expected = {};
  REQUIRE(getAllPermutations(input) == expected);
}

TEST_CASE("ch9.5 getAllPermutations - 1") {
  string input = "a";
  vector<string> expected = {"a"};
  REQUIRE(getAllPermutations(input) == expected);
}

TEST_CASE("ch9.5 getAllPermutations - 2") {
  string input = "ab";
  vector<string> expected = {"ba", "ab"};
  REQUIRE(getAllPermutations(input) == expected);
}

TEST_CASE("ch9.5 getAllPermutations - 3") {
  string input = "abc";
  vector<string> expected = {"cba", "bca", "bac", "cab", "acb", "abc"};
  REQUIRE(getAllPermutations(input) == expected);
}