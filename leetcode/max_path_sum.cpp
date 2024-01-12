/**
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes
i n the sequence has an edge connecting them. A node can only appear in the
sequence at most once. Note that the path does not need to pass through the
root. The path sum of a path is the sum of the node's values in the path. Given
the root of a binary tree, return the maximum path sum of any non-empty path.

Example 1:
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

Example 2:
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7
= 42.

Constraints:
The number of nodes in the tree is in the range [1, 3 * 104].
-1000 <= Node.val <= 1000

source from: leetcode 124.
*/

#include "algobase.h"
#include "node.h"
using namespace std;

int max_sum = INT_MIN;

int solve(TreeNode* root) {
  if (!root)
    return 0;
  int l = max(solve(root->left), 0);
  int r = max(solve(root->right), 0);
  int new_price = root->val + l + r;
  max_sum = max(max_sum, new_price);
  return root->val + max(l, r);
}

int maxPathSum(TreeNode* root) {
  solve(root);
  return max_sum;
}

int main() {
  vector<int> vec1 = {1, 2, 3};
  vector<int> vec2 = {-10, 9, 20, null, null, 15, 7};
  TreeNode* root1 = build_tree(vec1);
  TreeNode* root2 = build_tree(vec2);
  cout << maxPathSum(root1) << endl;
  cout << maxPathSum(root2) << endl;

  delete_tree(root1);
  delete_tree(root2);
  return 0;
}
