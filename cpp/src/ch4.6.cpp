#include "third_party/catch.hpp"

#include "TreeNode.h"

/**
 * find the next node (in-order successor, left->current->right order) of a
 * given node in a binary search tree. you maybe assume each node has a link to
 * its parent.
 */

TreeNode* findSuccessor(TreeNode* tree) {
  TreeNode* successor = nullptr;
  if (tree == nullptr) {
    // no successor
    return nullptr;
  } else if (tree->right != nullptr) {
    // return the left most node on right subtree
    successor = tree->right;
    while (successor->left != nullptr) {
      successor = successor->left;
    }
  } else {
    // find the first parent that hasn't been visited (i.e.
    // this happens if we are the left child of the parent)
    successor = tree;
    while (successor->parent == nullptr ||
           successor == successor->parent->right) {
      successor = successor->parent;
    }
  }
  return successor;
}

TEST_CASE("ch4.6 findSuccessor - empty tree") {
  TreeNode* root = nullptr;
  TreeNode* expected = nullptr;

  auto actual = findSuccessor(root);

  REQUIRE(expected == actual);
}

TEST_CASE("ch4.6 findSuccessor - successor on the right subtree") {
  TreeNode* root = new TreeNode(10);
  root->left = new TreeNode(7);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(9);
  root->left->right->left = new TreeNode(8);
  root->right = new TreeNode(13);
  TreeNode* expected = root->left->right->left;

  auto actual = findSuccessor(root->left);

  REQUIRE(expected == actual);
  REQUIRE(actual->value == 8);
}

TEST_CASE("ch4.6 findSuccessor - successor on the parent") {
  TreeNode* root = new TreeNode(10);
  root->left = new TreeNode(7);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(9);
  root->left->right->left = new TreeNode(8);
  root->right = new TreeNode(13);
  TreeNode* expected = root;

  auto actual = findSuccessor(root->left->right);

  REQUIRE(expected == actual);
  REQUIRE(actual->value == 10);
}

TEST_CASE("ch4.6 findSuccessor - no successor") {
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->right = new TreeNode(3);
  root->right->right->right = new TreeNode(4);
  TreeNode* expected = nullptr;

  auto actual = findSuccessor(root->right->right);

  REQUIRE(expected == actual);
}