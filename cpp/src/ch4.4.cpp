#include "third_party/catch.hpp"

#include <map>
#include <vector>
#include "TreeNode.h"

/**
 * Given a binary search tree, return a linked list of all nodes at each depth
 * (e.g. if a tree has D dpeth, return D linked lists )
 */

void createList(TreeNode* tree, std::vector<std::vector<TreeNode*>>& lists,
                int level) {
  if (tree == nullptr) {
    return;
  }

  if (lists.size() == level) {
    lists.push_back(std::vector<TreeNode*>());
  }
  lists[level].push_back(tree);

  createList(tree->left, lists, level + 1);
  createList(tree->right, lists, level + 1);
}

TEST_CASE("ch4.1 createNodeListPerHeight") {
  TreeNode* root = new TreeNode(0);
  root->left = new TreeNode(1);
  root->left->left = new TreeNode(2);
  root->left->left->left = new TreeNode(3);
  root->right = new TreeNode(4);

  std::vector<std::vector<TreeNode*>> lists;
  createList(root, lists, 0);

  REQUIRE(lists.size() == 4);
  REQUIRE(lists[0] == std::vector<TreeNode*>({root}));
  REQUIRE(lists[1] == std::vector<TreeNode*>({root->left, root->right}));
  REQUIRE(lists[2] == std::vector<TreeNode*>({root->left->left}));
  REQUIRE(lists[3] == std::vector<TreeNode*>({root->left->left->left}));
}
