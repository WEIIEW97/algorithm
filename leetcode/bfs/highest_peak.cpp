/**
You are given an integer matrix isWater of size m x n that represents a map of
land and water cells.

If isWater[i][j] == 0, cell (i, j) is a land cell.
If isWater[i][j] == 1, cell (i, j) is a water cell.
You must assign each cell a height in a way that follows these rules:

The height of each cell must be non-negative.
If the cell is a water cell, its height must be 0.
Any two adjacent cells must have an absolute height difference of at most 1. A
cell is adjacent to another cell if the former is directly north, east, south,
or west of the latter (i.e., their sides are touching). Find an assignment of
heights such that the maximum height in the matrix is maximized.

Return an integer matrix height of size m x n where height[i][j] is cell (i,
j)'s height. If there are multiple solutions, return any of them.



Example 1:



Input: isWater = [[0,1],[0,0]]
Output: [[1,0],[2,1]]
Explanation: The image shows the assigned heights of each cell.
The blue cell is the water cell, and the green cells are the land cells.
Example 2:



Input: isWater = [[0,0,1],[1,0,0],[0,0,0]]
Output: [[1,1,0],[0,1,1],[1,2,2]]
Explanation: A height of 2 is the maximum possible height of any assignment.
Any height assignment that has a maximum height of 2 while still meeting the
rules will also be accepted.


Constraints:

m == isWater.length
n == isWater[i].length
1 <= m, n <= 1000
isWater[i][j] is 0 or 1.
There is at least one water cell.


source from: leetcode 1765.
*/

#include "algobase.h"
using namespace std;

// Linux-specific optimizations with GCC or Clang
#if defined(__linux__)
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC optimize("Ofast")
static auto __optimize = []() {
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
static auto __optimize = []() {
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
static auto __optimize = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();
#endif
#endif

vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
  int m = isWater.size(), n = isWater[0].size();
  const int d[5] = {-1, 0, 1, 0, -1};
  queue<pair<int, int>> q;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (isWater[i][j]) {
        isWater[i][j] = 0;
        q.push({i, j});
      } else {
        isWater[i][j] = INT_MAX;
      }
    }
  }

  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int y = r + d[i], x = c + d[i + 1];
      if (y >= 0 && y < m && x >= 0 && x < n && isWater[y][x] != 0) {
        if (isWater[y][x] > isWater[r][c] + 1) {
          isWater[y][x] = isWater[r][c] + 1;
          q.push({y, x});
        }
      }
    }
  }
  return isWater;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // Your code here
  vector<vector<int>> m1, m2;
  m1 = parse_matrix("[[0,1],[0,0]]");
  m2 = parse_matrix("[[0,0,1],[1,0,0],[0,0,0]]");

  PRINT_VECTOR_2D(highestPeak(m1));
  PRINT_VECTOR_2D(highestPeak(m2));
  return 0;
}
