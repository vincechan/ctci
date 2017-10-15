#include "third_party/catch.hpp"

#include <vector>
#include "TreeNode.h"

/**
 * given a sorted ascending array, write a function to create a binary search
 * tree with minimal height
 */

TreeNode* createBST(const std::vector<int>& array, int start, int end) {
  if (end < start) {
    return nullptr;
  }

  int mid = (end + start) / 2;
  TreeNode* node = new TreeNode(array[mid]);
  node->left = createBST(array, start, mid - 1);
  node->right = createBST(array, mid + 1, end);

  return node;
}

TreeNode* createBST(const std::vector<int>& array) {
  return createBST(array, 0, array.size() - 1);
}

TEST_CASE("ch4.3 createBST") {
  std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7};

  TreeNode* tree = createBST(expected);

  std::vector<int> actual = get_in_order(tree);
  REQUIRE(expected == actual);
}