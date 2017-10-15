#include "third_party/catch.hpp"

#include "TreeNode.h"

/**
 * determine if a binary tree is balanced
 */
int get_child_count(TreeNode* tree) {
  if (tree == nullptr) {
    return 0;
  }
  int leftCount = get_child_count(tree->left);
  int rightCount = get_child_count(tree->right);
  if (leftCount < 0 || rightCount < 0 || abs(leftCount - rightCount) < 0) {
    // not balanced, return a negative number so all caller will detect not
    // balance
    return -1;
  }
  return leftCount + rightCount;
}

bool is_balanced(TreeNode* tree) {
  if (tree == nullptr) {
    return true;
  }

  if (get_child_count(tree) < 0) {
    return false;
  }
  return true;
}

TEST_CASE("ch4.1 is_balanced - balanced") {
  TreeNode* tree = new TreeNode(1);
  tree->left = new TreeNode(2);
  tree->right = new TreeNode(3);

  REQUIRE(is_balanced(tree) == true);
}

TEST_CASE("ch4.1 is_balanced - 6 nodes balanced") {
  TreeNode* tree = new TreeNode(1);
  tree->left = new TreeNode(2);
  tree->right = new TreeNode(3);
  tree->left->left = new TreeNode(4);
  tree->left->right = new TreeNode(5);
  tree->right->left = new TreeNode(6);

  REQUIRE(is_balanced(tree) == true);
}

TEST_CASE("ch4.1 is_balanced - not balaced") {
  TreeNode* tree = new TreeNode(1);
  tree->left = new TreeNode(2);
  tree->right = new TreeNode(3);
  tree->left->left = new TreeNode(4);
  tree->left->left->left = new TreeNode(5);

  REQUIRE(is_balanced(tree) == true);
}
