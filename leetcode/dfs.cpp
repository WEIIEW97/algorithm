#include "algobase.h"
using namespace std;


template <typename T>
class Graph {
  public:
    unordered_map<T, vector<T>> adj_list_;
    void add_edge(const T& u, const T& v, bool bidirectional=true) {
        adj_list_[u].push_back(v);
        if (bidirectional) {
            adj_list_[v].push_back(u);
        }
    }
};

template <typename T>
struct TreeNode {
    T val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
    ~TreeNode() {
        delete left;
        delete right;
    }
};

template <typename T>
void dfs(const T& node, unordered_map<T, bool>& visited, const Graph<T>& graph) {
    // mark the current node as visited
    visited[node] = true;
    // recur for all the adjacent vertices
    for (const T& neighbor : graph.adj_list_.at(node)) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, graph);
        }
    }
}

template <typename T>
void dfs_tree(TreeNode<T>* node) {
    if(!node) return;
    // process the current node
    dfs_tree(node->left);
    dfs_tree(node->right);
}


int main() {
    Graph<int> graph;
    graph.add_edge(1, 2);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);
    graph.add_edge(2, 4);

    unordered_map<int, bool> visited;
    dfs(1, visited, graph);

    TreeNode<int>* root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);

    dfs_tree(root);
    delete root;
    return 0;
}
