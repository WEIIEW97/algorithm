/**
Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return
false.

A matrix is Toeplitz if every diagonal from top-left to bottom-right has the
same elements.



Example 1:


Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: true
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.
Example 2:


Input: matrix = [[1,2],[2,2]]
Output: false
Explanation:
The diagonal "[1, 2]" has different elements.


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 20
0 <= matrix[i][j] <= 99

source from: leetcode 766.
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

bool isToeplitzMatrix(vector<vector<int>>& matrix) {
  int r = matrix.size(), c = matrix[0].size();
  for (int i = 0; i < r - 1; i++) {
    for (int j = 0; j < c - 1; j++) {
      if (matrix[i][j] == matrix[i + 1][j + 1])
        continue;
      else
        return false;
    }
  }
  return true;
}

int main() {
  vector<vector<int>> matrix1, matrix2;
  matrix1 = parse_matrix("[[1,2,3,4],[5,1,2,3],[9,5,1,2]]");
  matrix2 = parse_matrix("[[1,2],[2,2]]");
  print_res(isToeplitzMatrix, matrix1);
  print_res(isToeplitzMatrix, matrix2);

  return 0;
}
