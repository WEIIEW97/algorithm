/**
You are given the root of a binary tree with unique values, and an integer
start. At minute 0, an infection starts from the node with value start. Each
minute, a node becomes infected if: The node is currently uninfected. The node
is adjacent to an infected node. Return the number of minutes needed for the
entire tree to be infected.

Example 1:
Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.

Example 2:
Input: root = [1], start = 1
Output: 0
Explanation: At minute 0, the only node in the tree is infected so we return 0.

Constraints:
The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 105
Each node has a unique value.
A node with a value of start exists in the tree.

source from: leetcode 2385
*/

#include "algobase.h"
#include "node.h"
using namespace std;

using int2 = pair<int, int>;
vector<int> adj[100001];

void build_adj(TreeNode* root) {
  if (root == nullptr)
    return;
  int x = root->val;
  if (root->left) {
    int l = root->left->val;
    adj[x].push_back(l);
    adj[l].push_back(x);
    build_adj(root->left);
  }
  if (root->right) {
    int r = root->right->val;
    adj[x].push_back(r);
    adj[r].push_back(x);
    build_adj(root->right);
  }
}

int amountOfTime(TreeNode* root, int start) {
  fill(adj, adj + 100001, vector<int>());
  build_adj(root);
  bool viz[100001] = {0};
  queue<int2> q;
  q.emplace(start, 0);
  viz[start] = 1;
  int d = 0;
  while (!q.empty()) {
    auto [x, dd] = q.front();
    d = max(d, dd);
    q.pop();
    for (auto& y : adj[x]) {
      if (viz[y])
        continue;
      q.emplace(y, dd + 1);
      viz[y] = 1;
    }
  }
  return d;
}

int main() {
  vector<int> root1 = {1, 5, 3, null, 4, 10, 6, 9, 2};
  vector<int> root2 = {1};
  TreeNode* node1 = build_tree(root1);
  TreeNode* node2 = build_tree(root2);
  cout << amountOfTime(node1, 3) << endl;
  cout << amountOfTime(node2, 1) << endl;
  return 0;
}
