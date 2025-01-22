/**
Given an m x n binary matrix mat, return the distance of the nearest 0 for each
cell.

The distance between two cells sharing a common edge is 1.



Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]


Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.

source from: leetcode 542.
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

vector<vector<int>> updateMatrix(vector<vector<int>>& m) {
  int N = m.size();
  int M = m[0].size();
  const int d[5] = {-1, 0, 1, 0, -1};
  queue<pair<int, int>> q;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (m[i][j] == 0)
        q.push({i, j});
      else
        m[i][j] = -1;
    }
  }

  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int y = r + d[i], x = c + d[i + 1];
      if (y >= 0 && y < N && x >= 0 && x < M && m[y][x] == -1) {
        m[y][x] = m[r][c] + 1;
        q.push({y, x});
      }
    }
  }
  return m;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // Your code here
  vector<vector<int>> m1, m2;
  m1 = parse_matrix("[[0,0,0],[0,1,0],[0,0,0]]");
  m2 = parse_matrix("[[0,0,0],[0,1,0],[1,1,1]]");

  PRINT_VECTOR_2D(updateMatrix(m1));
  PRINT_VECTOR_2D(updateMatrix(m2));
  return 0;
}
