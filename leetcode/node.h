#include <vector>
#include <queue>

#define null -1

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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
