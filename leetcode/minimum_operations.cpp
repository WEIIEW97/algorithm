/**
You are given the root of a binary tree with unique values.

In one operation, you can choose any two nodes at the same level and swap their
values.

Return the minimum number of operations needed to make the values at each level
sorted in a strictly increasing order.

The level of a node is the number of edges along the path between it and the
root node.



Example 1:


Input: root = [1,4,3,7,6,8,5,null,null,null,null,9,null,10]
Output: 3
Explanation:
- Swap 4 and 3. The 2nd level becomes [3,4].
- Swap 7 and 5. The 3rd level becomes [5,6,8,7].
- Swap 8 and 7. The 3rd level becomes [5,6,7,8].
We used 3 operations so return 3.
It can be proven that 3 is the minimum number of operations needed.
Example 2:


Input: root = [1,3,2,7,6,5,4]
Output: 3
Explanation:
- Swap 3 and 2. The 2nd level becomes [2,3].
- Swap 7 and 4. The 3rd level becomes [4,6,5,7].
- Swap 6 and 5. The 3rd level becomes [4,5,6,7].
We used 3 operations so return 3.
It can be proven that 3 is the minimum number of operations needed.
Example 3:


Input: root = [1,2,3,4,5,6]
Output: 0
Explanation: Each level is already sorted in increasing order so return 0.


Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 105
All the values of the tree are unique.

source from: leetcode 2471.
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

int minimumOperations(TreeNode* root) {
  queue<TreeNode*> q;
  q.push(root);
  int swaps = 0;
  while (!q.empty()) {
    int qz = q.size();
    vector<int> idx(qz, 0);
    iota(idx.begin(), idx.end(), 0);
    vector<int> arr(qz, 0);
    for (int i = 0; i < qz; i++) {
      auto node = q.front();
      q.pop();
      arr[i] = node->val;
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
    // each value is unique, no need for stable_sort
    sort(idx.begin(), idx.end(), [&](int i, int j) { return arr[i] < arr[j]; });
    for (int i = 0; i < qz;) {
      int j = idx[i];
      if (j != i) { // recheck
        swaps++;
        swap(idx[i], idx[j]);
      } else
        i++; // next iteration
    }
  }
  return swaps;
}

int main() {
  TreeNode *root1, *root2, *root3;
  root1 =
      build_tree(parse_vector("[1,4,3,7,6,8,5,null,null,null,null,9,null,10]"));
  root2 = build_tree(parse_vector("[1,3,2,7,6,5,4]"));
  root3 = build_tree(parse_vector("[1,2,3,4,5,6]"));

  print_res(minimumOperations, root1);
  print_res(minimumOperations, root2);
  print_res(minimumOperations, root3);

  delete_tree(root3);
  delete_tree(root2);
  delete_tree(root1);

  return 0;
}
