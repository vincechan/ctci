#ifndef TREENODE_INCLUDE_
#define TREENODE_INCLUDE_

#include <vector>

/**
 * given a sorted ascending array, write a function to create a binary search
 * tree with minimal height
 */

struct TreeNode {
  int value;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
};

inline void in_order(TreeNode* node, std::vector<int>& result) {
  if (node != nullptr) {
    in_order(node->left, result);
    result.push_back(node->value);
    in_order(node->right, result);
  }
}

inline std::vector<int> get_in_order(TreeNode* node) {
  std::vector<int> result;
  in_order(node, result);
  return result;
}

#endif