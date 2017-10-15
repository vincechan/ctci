#include "third_party/catch.hpp"

#include "TreeNode.h"

TEST_CASE("TreeNode") {
  TreeNode* root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right = new TreeNode(6);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(7);
  std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7};

  std::vector<int> actual = get_in_order(root);

  REQUIRE(actual == expected);
}