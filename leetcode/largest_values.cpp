/**
Given the root of a binary tree, return an array of the largest value in each
row of the tree (0-indexed).



Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]
Example 2:

Input: root = [1,2,3]
Output: [1,3]


Constraints:

The number of nodes in the tree will be in the range [0, 104].
-231 <= Node.val <= 231 - 1

source from: leetcode 515.
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

vector<int> largestValues(TreeNode* root) {
  vector<int> res;
  if (root == nullptr)
    return {};
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    int sz = q.size();
    int maxv = INT_MIN;
    while (sz--) {
      auto node = q.front();
      q.pop();
      maxv = max(maxv, node->val);
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
    res.push_back(maxv);
  }

  return res;
}

int main() {
  TreeNode *root1, *root2;
  root1 = build_tree(parse_vector("[1,3,2,5,3,null,9]"));
  root2 = build_tree(parse_vector("[1,2,3]"));

  PRINT_VECTOR_1D(largestValues(root1));
  PRINT_VECTOR_1D(largestValues(root2));

  return 0;
}
