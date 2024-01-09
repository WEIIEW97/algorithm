/**
Consider all the leaves of a binary tree, from left to right order, the values
of those leaves form a leaf value sequence. For example, in the given tree
above, the leaf value sequence is (6, 7, 4, 9, 8). Two binary trees are
considered leaf-similar if their leaf value sequence is the same. Return true if
and only if the two given trees with head nodes root1 and root2 are
leaf-similar.

Example 1:
Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 =
[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8] Output: true

Example 2:
Input: root1 = [1,2,3], root2 = [1,3,2]
Output: false

Constraints:
The number of nodes in each tree will be in the range [1, 200].
Both of the given trees will have values in the range [0, 200].

source from: leetcode 872
*/

#include "algobase.h"
using namespace std;

#define null -1

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

TreeNode* build_tree(const std::vector<int>& values) {
  if (values.empty() || values[0] == -1)
    return nullptr;

  TreeNode* root = new TreeNode(values[0]);
  std::queue<TreeNode*> q;
  q.push(root);

  for (size_t i = 1; i < values.size(); i += 2) {
    TreeNode* parent = q.front();
    q.pop();

    if (values[i] != -1) {
      parent->left = new TreeNode(values[i]);
      q.push(parent->left);
    }

    if (i + 1 < values.size() && values[i + 1] != -1) {
      parent->right = new TreeNode(values[i + 1]);
      q.push(parent->right);
    }
  }

  return root;
}

void delete_tree(TreeNode* node) {
  if (node == nullptr)
    return;
  delete_tree(node->left);
  delete_tree(node->right);
  delete node;
}

void traverse(TreeNode* node, vector<int>& leaf) {
  if (node->left != nullptr)
    traverse(node->left, leaf);
  if (node->right != nullptr)
    traverse(node->right, leaf);
  if (node->left == nullptr && node->right == nullptr)
    leaf.push_back(node->val);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
  vector<int> leaf1, leaf2;
  traverse(root1, leaf1);
  traverse(root2, leaf2);
  return leaf1 == leaf2;
}

int main() {
  // -1 for nullptr
  vector<int> val1 = {3, 5, 1, 6, 2, 9, 8, null, null, 7, 4};
  vector<int> val2 = {3,    5,    1,    6,    7,    4, 2, null,
                      null, null, null, null, null, 9, 8};
  TreeNode* root1 = build_tree(val1);
  TreeNode* root2 = build_tree(val2);

  if (leafSimilar(root1, root2)) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }

  delete_tree(root1);
  delete_tree(root2);
  return 0;
}
