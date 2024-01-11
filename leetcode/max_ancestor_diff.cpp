/**
Given the root of a binary tree, find the maximum value v for which there exist
different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.
A node a is an ancestor of b if either: any child of a is equal to b or any
child of a is an ancestor of b.

Example 1:
Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given
below : |8 - 3| = 5 |3 - 7| = 4 |8 - 1| = 7 |10 - 13| = 3 Among all possible
differences, the maximum value of 7 is obtained by |8 - 1| = 7.

Example 2:
Input: root = [1,null,2,null,0,3]
Output: 3

Constraints:
The number of nodes in the tree is in the range [2, 5000].
0 <= Node.val <= 105

source from: leetcode 1026
*/

#include "algobase.h"
#include "node.h"
using namespace std;

int ans;

void traverse(TreeNode* root, int maxv, int minv) {
  if (root == nullptr) {
    ans = max(ans, abs(maxv - minv));
    return;
  }
  maxv = max(maxv, root->val);
  minv = min(minv, root->val);
  traverse(root->left, maxv, minv);
  traverse(root->right, maxv, minv);
}

int maxAncestorDiff(TreeNode* root) {
  if (!root)
    return 0;
  ans = 0;
  traverse(root, root->val, root->val);
  return ans;
}

int main() {
  vector<int> vec1 = {8, 3, 10, 1, 6, null, 14, null, null, 4, 7, 13};
  vector<int> vec2 = {1, null, 2, null, 0, 3};
  TreeNode* root1 = build_tree(vec1);
  TreeNode* root2 = build_tree(vec2);
  cout << maxAncestorDiff(root1) << endl;
  cout << maxAncestorDiff(root2) << endl;

  delete_tree(root1);
  delete_tree(root2);
  return 0;
}
