#include "third_party/catch.hpp"

#include <algorithm>
#include <vector>

using namespace std;

/**
 * write a function to generate all subsets for a given set
 */

/**
 * generate all subsets for a given set's first n elements
 */
vector<vector<int>> get_subsets(const vector<int>& set, int n) {
  vector<vector<int>> ans;
  if (n == 0) {
    ans.push_back({});
  } else {
    // get all previous subsets up to n - 1
    vector<vector<int>> previous = get_subsets(set, n - 1);
    ans.insert(ans.end(), previous.begin(), previous.end());
    // create new subsets for adding the nth element, we will double the number
    // of subset from n - 1. the new subsets will be same as previous subsets
    // adding a new element
    int element = set[n - 1];
    for (const auto& s : previous) {
      auto newset = s;
      newset.push_back(element);
      sort(newset.begin(), newset.end());  // sort it to make testing easier
      ans.push_back(newset);
    }
  }
  return ans;
}

vector<vector<int>> get_all_subsets(const vector<int>& set) {
  return get_subsets(set, set.size());
}

TEST_CASE("ch9.4 get all subsets - 0") {
  vector<int> set = {};
  vector<vector<int>> expected;
  expected.push_back(vector<int>());

  auto actual = get_all_subsets(set);
  REQUIRE(expected == actual);
}

TEST_CASE("ch9.4 get all subsets - 1") {
  vector<int> set = {1};
  vector<vector<int>> expected;
  expected.push_back({});
  expected.push_back({1});

  auto actual = get_all_subsets(set);
  REQUIRE(expected == actual);
}

TEST_CASE("ch9.4 get all subsets - 2") {
  vector<int> set = {1, 2};
  vector<vector<int>> expected;
  expected.push_back({});
  expected.push_back({1});
  expected.push_back({2});
  expected.push_back({1, 2});

  auto actual = get_all_subsets(set);
  REQUIRE(expected == actual);
}

TEST_CASE("ch9.4 get all subsets - 3") {
  vector<int> set = {1, 2, 3};
  vector<vector<int>> expected;
  expected.push_back({});
  expected.push_back({1});
  expected.push_back({2});
  expected.push_back({1, 2});
  expected.push_back({3});
  expected.push_back({1, 3});
  expected.push_back({2, 3});
  expected.push_back({1, 2, 3});

  auto actual = get_all_subsets(set);
  REQUIRE(expected == actual);
}