/**
You are given a 0-indexed integer array arr, and an m x n integer matrix mat.
arr and mat both contain all the integers in the range [1, m * n].

Go through each index i in arr starting from index 0 and paint the cell in mat
containing the integer arr[i].

Return the smallest index i at which either a row or a column will be completely
painted in mat.



Example 1:

image explanation for example 1
Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
Output: 2
Explanation: The moves are shown in order, and both the first row and second
column of the matrix become fully painted at arr[2]. Example 2:

image explanation for example 2
Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
Output: 3
Explanation: The second column becomes fully painted at arr[3].


Constraints:

m == mat.length
n = mat[i].length
arr.length == m * n
1 <= m, n <= 105
1 <= m * n <= 105
1 <= arr[i], mat[r][c] <= m * n
All the integers of arr are unique.
All the integers of mat are unique.

source from: leetcode 2661.
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

int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
  int m = mat.size(), n = mat[0].size(), N = m * n;

  vector<int> row_i(N + 1), col_j(N + 1);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      auto x = mat[i][j];
      row_i[x] = i;
      col_j[x] = j;
    }
  }

  vector<int> r(m, 0), c(n, 0);
  for (int k = 0; k < N; k++) {
    auto x = arr[k];
    if (++r[row_i[x]] == n || ++c[col_j[x]] == m)
      return k;
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // Your code here
  vector<int> arr1, arr2;
  vector<vector<int>> mat1, mat2;
  arr1 = parse_vector("[1,3,4,2]");
  arr2 = parse_vector("[2,8,7,4,1,3,5,6,9]");
  mat1 = parse_matrix("[[1,4],[2,3]]");
  mat2 = parse_matrix("[[3,2,5],[1,4,6],[8,7,9]]");

  print_res(firstCompleteIndex, arr1, mat1);
  print_res(firstCompleteIndex, arr2, mat2);

  return 0;
}
