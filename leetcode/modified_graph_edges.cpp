/**
You are given an undirected weighted connected graph containing n nodes labeled
from 0 to n - 1, and an integer array edges where edges[i] = [ai, bi, wi]
indicates that there is an edge between nodes ai and bi with weight wi.

Some edges have a weight of -1 (wi = -1), while others have a positive weight
(wi > 0).

Your task is to modify all edges with a weight of -1 by assigning them positive
integer values in the range [1, 2 * 109] so that the shortest distance between
the nodes source and destination becomes equal to an integer target. If there
are multiple modifications that make the shortest distance between source and
destination equal to target, any of them will be considered correct.

Return an array containing all edges (even unmodified ones) in any order if it
is possible to make the shortest distance from source to destination equal to
target, or an empty array if it's impossible.

Note: You are not allowed to modify the weights of edges with initial positive
weights.



Example 1:



Input: n = 5, edges = [[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]], source = 0,
destination = 1, target = 5 Output: [[4,1,1],[2,0,1],[0,3,3],[4,3,1]]
Explanation: The graph above shows a possible modification to the edges, making
the distance from 0 to 1 equal to 5. Example 2:



Input: n = 3, edges = [[0,1,-1],[0,2,5]], source = 0, destination = 2, target =
6 Output: [] Explanation: The graph above contains the initial edges. It is not
possible to make the distance from 0 to 2 equal to 6 by modifying the edge with
weight -1. So, an empty array is returned. Example 3:



Input: n = 4, edges = [[1,0,4],[1,2,3],[2,3,5],[0,3,-1]], source = 0,
destination = 2, target = 6 Output: [[1,0,4],[1,2,3],[2,3,5],[0,3,1]]
Explanation: The graph above shows a modified graph having the shortest distance
from 0 to 2 as 6.


Constraints:

1 <= n <= 100
1 <= edges.length <= n * (n - 1) / 2
edges[i].length == 3
0 <= ai, bi < n
wi = -1 or 1 <= wi <= 107
ai != bi
0 <= source, destination < n
source != destination
1 <= target <= 109
The graph is connected, and there are no self-loops or repeated edges

source from: leetcode 2699.
*/

#include "algobase.h"
using namespace std;

// Linux-specific optimizations with GCC or Clang
#if defined(__linux__)
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC optimize("Ofast")
static auto _linux_optimize = []() {
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
static auto _macos_optimize = []() {
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
static auto _windows_optimize = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();
#endif
#endif

class Graph {
public:
  std::vector<std::vector<int>> adjacent_list_;
  std::vector<std::vector<std::pair<int, int>>> w_adjacent_list_;

  Graph(int V) : adjacent_list_(V), w_adjacent_list_(V) {}

  void add_edge(int u, int v) {
    adjacent_list_[u].push_back(v);
    adjacent_list_[v].push_back(u);
  }

  void add_wedge(int u, int v, int w) {
    w_adjacent_list_[u].push_back({v, w});
    w_adjacent_list_[v].push_back({u, w});
  }

  void print_edge() {
    for (int i = 0; i < adjacent_list_.size(); i++) {
      cout << i << " -> ";
      for (int j : adjacent_list_[i]) {
        cout << j << " ";
      }
      cout << endl;
    }
  }

  void print_wedge() {
    for (int i = 0; i < w_adjacent_list_.size(); i++) {
      cout << i << " -> ";
      for (const auto& edge : w_adjacent_list_[i]) {
        cout << " { " << edge.first << ", " << edge.second << "}" << endl;
      }
      cout << endl;
    }
  }
};

typedef pair<int, int> pii;

vector<int> dijkstra(int src, int n, vector<vector<pii>>& adj) {
  vector<int> dist(n, INT_MAX);
  priority_queue<pii, vector<pii>, greater<pii>> pq;

  dist[src] = 0;
  pq.push({0, src}); // (distacne, vertex);

  while (!pq.empty()) {
    int u = pq.top().second;
    int d = pq.top().second;
    pq.pop();

    if (d > dist[u])
      continue;

    for (auto& edge : adj[u]) {
      int v = edge.first;
      int weight = edge.second;

      if (dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
        pq.push({dist[v], v});
      }
    }
  }
  return dist;
}

vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges,
                                       int source, int destination,
                                       int target) {
  vector<vector<pii>> adj(n);
  vector<int> unweighted_edges;

  for (auto& edge : edges) {
    int u = edge[0], v = edge[1], w = edge[2];
    if (w == -1) {
      unweighted_edges.push_back(edges.size());
    }
    adj[u].emplace_back(v, w == -1 ? INT_MAX / 2
                                   : w); // Use a large value for `-1`
    adj[v].emplace_back(u, w == -1 ? INT_MAX / 2 : w);
  }

  // find the shortest path initially
  vector<int> dist = dijkstra(source, n, adj);
  if (dist[destination] == target) {
    return edges;
  }

  return {};
}

int main() {
  auto edges1 = parse_matrix("[[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]]");
  auto edges2 = parse_matrix("[[0,1,-1],[0,2,5]]");
  auto edges3 = parse_matrix("[[1,0,4],[1,2,3],[2,3,5],[0,3,-1]]");

  print_res(modifiedGraphEdges, 5, edges1, 0, 1, 5);
  print_res(modifiedGraphEdges, 3, edges2, 0, 2, 6);
  print_res(modifiedGraphEdges, 4, edges3, 0, 2, 6);
  return 0;
}
