/**
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's
triangle. In Pascal's triangle, each number is the sum of the two numbers
directly above it as shown:

Example 1:
Input: rowIndex = 3
Output: [1,3,3,1]

Example 2:
Input: rowIndex = 0
Output: [1]

Example 3:
Input: rowIndex = 1
Output: [1,1]

Constraints:
0 <= rowIndex <= 33

Follow up: Could you optimize your algorithm to use only O(rowIndex) extra
space?

source from: leetcode 119
*/

#include "algobase.h"
using namespace std;

// intuitive way
vector<int> getRowV1(int rowIndex) {
  vector<vector<int>> r(rowIndex + 1);

  for (int i = 0; i <= rowIndex; i++) {
    r[i].resize(i + 1);
    r[i][0] = r[i][i] = 1;

    for (int j = 1; j < i; j++) {
      r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
    }
  }
  return r[rowIndex];
}

// use combinations
vector<int> getRowV2(int rowIndex) {
  vector<int> r(rowIndex + 1, 1);
  for (int i = 1; i <= rowIndex / 2; i++) {
    r[i] = r[rowIndex - i] = NCR(rowIndex, i);
  }
  return r;
}

int main() {
  auto ans = getRowV2(6);
  PRINT_VECTOR_1D(ans);
  return 0;
}