#include "third_party/catch.hpp"

#include <vector>
#include "TreeNode.h"

void inOrder(TreeNode* tree, std::vector<int>& list) {
  if (tree == nullptr) {
    return;
  }

  inOrder(tree->left, list);
  list.push_back(tree->value);
  inOrder(tree->right, list);
}

std::vector<int> getInOrderList(TreeNode* tree) {
  std::vector<int> list;
  inOrder(tree, list);
  return list;
}

/**
 * determine if a tree is a binary search tree
 */
bool isBST(TreeNode* tree) {
  std::vector<int> list = getInOrderList(tree);

  if (list.size() <= 1) {
    return true;
  }

  for (int i = 1; i < list.size(); i++) {
    if (list[i] < list[i - 1]) {
      return false;
    }
  }
  return true;
}

TEST_CASE("ch4.5 isBST - true") {
  TreeNode* tree = new TreeNode(4);
  tree->left = new TreeNode(2);
  tree->left->left = new TreeNode(1);
  tree->left->right = new TreeNode(3);
  tree->right = new TreeNode(6);
  tree->right->left = new TreeNode(5);
  tree->right->right = new TreeNode(7);

  REQUIRE(isBST(tree) == true);
}

TEST_CASE("ch4.5 isBST - false") {
  TreeNode* tree = new TreeNode(4);
  tree->left = new TreeNode(2);
  tree->left->left = new TreeNode(1);
  tree->left->right = new TreeNode(3);
  tree->right = new TreeNode(0);

  REQUIRE(isBST(tree) == false);
}