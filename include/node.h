#include <vector>
#include <queue>
#include <iostream>

#define null -1

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

inline ListNode* build_list(const std::vector<int>& values) {
  if (values.empty() || values[0] == -1)
    return nullptr;

  ListNode* root =
      new ListNode(values[0]); // Create the root node from the first value.
  ListNode* curr = root;       // Start with the current node at the root.

  for (size_t i = 1; i < values.size();
       ++i) { // Start from the second item since the first is already used.
    if (values[i] != -1) { // Only add non `-1` values, assuming `-1` is a
                           // sentinel not to create a node.
      curr->next = new ListNode(values[i]);
      curr = curr->next; // Move the current node pointer forward.
    }
  }

  return root; // Return the head of the list.
}

inline void delete_list(ListNode* node) {
  if (node == nullptr)
    return;
  delete_list(node->next);
  delete node;
}

inline void print_list(ListNode* head) {
  ListNode* current = head;
  while (current != nullptr) {
    std::cout << current->val << " ";
    current = current->next;
  }
  std::cout << "\n";
}

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

inline TreeNode* build_tree(const std::vector<int>& values) {
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

inline void delete_tree(TreeNode* node) {
  if (node == nullptr)
    return;
  delete_tree(node->left);
  delete_tree(node->right);
  delete node;
}
