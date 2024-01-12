/**
You are a hiker preparing for an upcoming hike. You are given heights, a 2D
array of size rows x columns, where heights[row][col] represents the height of
cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to
travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can
move up, down, left, or right, and you wish to find a route that requires the
minimum effort. A route's effort is the maximum absolute difference in heights
between two consecutive cells of the route. Return the minimum effort required
to travel from the top-left cell to the bottom-right cell.

Example 1:
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in
consecutive cells. This is better than the route of [1,2,2,2,5], where the
maximum absolute difference is 3.

Example 2:
Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in
consecutive cells, which is better than route [1,3,5,3,5].

Example 3:
Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.

Constraints:

rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106

source from: leetcode 1631
 */

#include "algobase.h"
using namespace std;

int minimumEffortPath(vector<vector<int>>& heights) {
  vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
  int n = heights.size(), m = heights[0].size();
  vector<vector<int>> dp(n, vector<int>(m, 0));

  set<pair<int, pair<int, int>>> s = {{0, {0, 0}}};

  while (s.size()) {
    auto a = *s.begin();
    s.erase(s.begin());
    int val = a.first, x = a.second.first, y = a.second.second;
    if (dp[x][y])
      continue;
    dp[x][y] = 1;

    if (x == n - 1 && y == m - 1)
      return val;

    for (auto& [i, j] : dir) {
      if (x + i < n && x + i >= 0 && y + j < m && y + j >= 0) {
        if (dp[x + i][y + j] == 0) {
          int v = abs(heights[x + i][y + j] - heights[x][y]);
          s.insert({max(v, val), {x + i, y + j}});
        }
      }
    }
  }
  return 0;
}

int main() {
  vector<vector<int>> height1 = {
      {1, 2, 2},
      {3, 8, 2},
      {5, 3, 5},
  };

  vector<vector<int>> height2 = {
      {1, 2, 3},
      {3, 8, 4},
      {5, 3, 5},
  };

  vector<vector<int>> height3 = {
      {1, 2, 1, 1, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1},
      {1, 2, 1, 2, 1}, {1, 1, 1, 2, 1},
  };

  cout << minimumEffortPath(height2) << endl;
  return 0;
}