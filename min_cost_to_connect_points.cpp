/**
You are given an array points representing integer coordinates of some points on
a 2D-plane, where points[i] = [xi, yi]. The cost of connecting two points [xi,
yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|,
where |val| denotes the absolute value of val.
Return the minimum cost to make all points connected. All points are connected
if there is exactly one simple path between any two points.


Example 1:
Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation:
We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.

Example 2:
Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18


Constraints:

1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.
*/

#include "algobase.h"
using namespace std;

class Solution {
public:
  int minCostConnectPoints(vector<vector<int>> &points) {
    int n = points.size();
    vector<int> cost(n, INT_MAX); // cost from this point to minimum cost point
    vector<bool> visited(n, false);
    cost[0] = 0;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
      int u = -1;
      for (int j = 0; j < n; ++j) {
        if (!visited[j] && (u == -1 || cost[j] < cost[u])) {
          u = j;
        }
      }

      visited[u] = true;
      ans += cost[u];

      for (int v = 0; v < n; ++v) {
        int c = L1(points[u], points[v]);
        if (cost[v] > c && !visited[v]) {
          cost[v] = c;
        }
      }
    }
    return ans;
  }

  int L1(vector<int> &p1, vector<int> &p2) {
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
  }
};

int main() {
  vector<vector<int>> points1 = {
      {0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0},
  };

  vector<vector<int>> points2 = {
      {3, 12},
      {-2, 5},
      {-4, 1},
  };

  auto solver = Solution();
  cout << "minimum is " << solver.minCostConnectPoints(points2) << endl;
  return 0;
}