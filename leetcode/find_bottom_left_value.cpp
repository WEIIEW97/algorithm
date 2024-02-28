/**
Given the root of a binary tree, return the leftmost value in the last row of
the tree.

Example 1:
Input: root = [2,1,3]
Output: 1

Example 2:
Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7

Constraints:

The number of nodes in the tree is in the range [1, 104].
-2^31 <= Node.val <= 2^31 - 1

source from: leetcode 513.
*/

#include "algobase.h"
#include "node.h"
using namespace std;

int hmax = -1, ans = 0;

void traverse(TreeNode* root, int level) {
  if (!root)
    return;
  if (level > hmax)
    hmax = level, ans = root->val;
  traverse(root->left, level + 1);
  traverse(root->right, level + 1);
}

void trace_path(TreeNode* root, int level) {
  if (!root)
    return;
  if (level > hmax)
    hmax = level, ans = root->val, cout << "currently viewing: " << ans << endl;
  cout << "traversing on left" << endl;
  trace_path(root->left, level + 1);
  cout << "traversing on right" << endl;
  trace_path(root->right, level + 1);
}

int findBottomLeftValue(TreeNode* root) {
  trace_path(root, 0);
  return ans;
}

int main() {
  vector<int> node1 = {1, 2, 3, 4, null, 5, 6, null, null, 7};
  auto root1 = build_tree(node1);
  vector<int> node2 = {2, 1, 3};
  auto root2 = build_tree(node2);
  cout << findBottomLeftValue(root1) << endl;
  // cout << findBottomLeftValue(root2) << endl;
  delete_tree(root1);
  delete_tree(root2);
  return 0;
}
