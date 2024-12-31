/**
Given the root of a perfect binary tree, reverse the node values at each odd
level of the tree.

For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], then
it should become [18,29,11,7,4,3,1,2]. Return the root of the reversed tree.

A binary tree is perfect if all parent nodes have two children and all leaves
are on the same level.

The level of a node is the number of edges along the path between it and the
root node.



Example 1:


Input: root = [2,3,5,8,13,21,34]
Output: [2,5,3,8,13,21,34]
Explanation:
The tree has only one odd level.
The nodes at level 1 are 3, 5 respectively, which are reversed and become 5, 3.
Example 2:


Input: root = [7,13,11]
Output: [7,11,13]
Explanation:
The nodes at level 1 are 13, 11, which are reversed and become 11, 13.
Example 3:

Input: root = [0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]
Output: [0,2,1,0,0,0,0,2,2,2,2,1,1,1,1]
Explanation:
The odd levels have non-zero values.
The nodes at level 1 were 1, 2, and are 2, 1 after the reversal.
The nodes at level 3 were 1, 1, 1, 1, 2, 2, 2, 2, and are 2, 2, 2, 2, 1, 1, 1, 1
after the reversal.


Constraints:

The number of nodes in the tree is in the range [1, 214].
0 <= Node.val <= 105
root is a perfect binary tree.

source from: leetcode 2415.
*/

#include "algobase.h"
#include "node.h"
using namespace std;

// Linux-specific optimizations with GCC or Clang
#if defined(__linux__)
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC optimize("Ofast")
static auto __optimize = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();
#endif
#endif

// macOS-specific optimizations with Clang
#if defined(__APPLE__) && defined(__MACH__)
#if defined(__clang__)
#pragma clang optimize on
static auto __optimize = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();
#endif
#endif

// Windows-specific optimizations with MSVC
#if defined(_WIN32)
#if defined(_MSC_VER)
#include <cstdlib>
#pragma optimize("t", on)
static auto __optimize = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();
#endif
#endif

TreeNode* reverseOddLevels(TreeNode* root) {
  queue<TreeNode*> q;
  q.push(root);
  bool reverse = 0;
  while (!q.empty()) {
    int qsz = q.size();
    vector<TreeNode*> arr(qsz);
    for (int i = 0; i < qsz; i++) {
      auto node = q.front();
      q.pop();
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
      if (reverse) {
        arr[i] = node;
        if (i >= qsz / 2)
          swap(arr[i]->val, arr[qsz - 1 - i]->val);
      }
    }
    reverse = !reverse;
  }
  return root;
}

int main() {
  TreeNode *root1, *root2, *root3;
  root1 = build_tree(parse_vector("[2,3,5,8,13,21,34]"));
  root2 = build_tree(parse_vector("[7,13,11]"));
  root3 = build_tree(parse_vector("[0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]"));

  print_tree(reverseOddLevels(root1));
  print_tree(reverseOddLevels(root2));
  print_tree(reverseOddLevels(root3));

  return 0;
}
