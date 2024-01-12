/**
You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's
(representing civilians). The soldiers are positioned in front of the civilians.
That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to
strongest.

Example 1:

Input: mat =
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]],
k = 3
Output: [2,0,3]
Explanation:
The number of soldiers in each row is:
- Row 0: 2
- Row 1: 4
- Row 2: 1
- Row 3: 2
- Row 4: 5
The rows ordered from weakest to strongest are [2,0,3,1,4].

Example 2:

Input: mat =
[[1,0,0,0],
 [1,1,1,1],
 [1,0,0,0],
 [1,0,0,0]],
k = 2
Output: [0,2]
Explanation:
The number of soldiers in each row is:
- Row 0: 1
- Row 1: 4
- Row 2: 1
- Row 3: 1
The rows ordered from weakest to strongest are [0,2,3,1].

Constraints:

m == mat.length
n == mat[i].length
2 <= n, m <= 100
1 <= k <= m
matrix[i][j] is either 0 or 1.

source from: leetcode 1337
*/
#include "algobase.h"
using namespace std;

vector<int> kWeakestRowsV1(vector<vector<int>>& mat, int k) {
  int h = mat.size();

  vector<pair<int, int>> rec;
  for (int i = 0; i < h; i++) {
    rec.push_back(
        make_pair(i, std::accumulate(mat[i].begin(), mat[i].end(), 0)));
  }

  sort(rec.begin(), rec.end(), [](pair<int, int>& p1, pair<int, int>& p2) {
    if (p1.second < p2.second)
      return true;
    if (p1.second == p2.second)
      return p1.first < p2.first;
    return false;
  });

  vector<int> res;
  for (int m = 0; m < k; m++) {
    res.push_back(rec[m].first);
  }

  return res;
}

// by using std::lower_bound
vector<int> kWeakestRowsV2(vector<vector<int>>& mat, int k) {
  int n = mat.size();

  vector<int> res;
  vector<pair<int, int>> pa;
  for (int i = 0; i < n; i++) {
    int val = lower_bound(mat[i].begin(), mat[i].end(), 0, greater<int>()) -
              mat[i].begin();
    pa.push_back({val, i});
  }
  sort(pa.begin(), pa.end());
  for (auto& p : pa) {
    cout << "value: " << p.first << " idx: " << p.second << endl;
  }
  for (int i = 0; i < k; i++) {
    res.push_back(pa[i].second);
  }
  return res;
}

int main() {
  vector<vector<int>> mat1 = {{1, 1, 0, 0, 0},
                              {1, 1, 1, 1, 0},
                              {1, 0, 0, 0, 0},
                              {1, 1, 0, 0, 0},
                              {1, 1, 1, 1, 1}};
  vector<vector<int>> mat2 = {
      {1, 0, 0, 0}, {1, 1, 1, 1}, {1, 0, 0, 0}, {1, 0, 0, 0}};

  auto res = kWeakestRowsV2(mat1, 3);
  PRINT_VECTOR_1D(res);
  return 0;
}