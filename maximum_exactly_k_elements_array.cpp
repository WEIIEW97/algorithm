/**
You are given three integers n, m and k. Consider the following algorithm to
find the maximum element of an array of positive integers:

```
maximum_value = -1
maximum_index = -1
search_cost = 0
n = arr.length
for (i = 0; i < n; i++) {
    if (maximum_value < arr[i]) {
        maximum_value = arr[i]
        maximum_index = i
        search_cost = search_cost = 1
    }
}
return maximum_index
```

You should build the array arr which has the following properties:
arr has exactly n integers.
1 <= arr[i] <= m where (0 <= i < n).
After applying the mentioned algorithm to arr, the value search_cost is equal to
k. Return the number of ways to build the array arr under the mentioned
conditions. As the answer may grow large, the answer must be computed modulo 109
+ 7.

Example 1:
Input: n = 2, m = 3, k = 1
Output: 6
Explanation: The possible arrays are [1, 1], [2, 1], [2, 2], [3, 1], [3, 2] [3,
3]

Example 2:
Input: n = 5, m = 2, k = 3
Output: 0
Explanation: There are no possible arrays that satisify the mentioned
conditions.

Example 3:
Input: n = 9, m = 1, k = 1
Output: 1
Explanation: The only possible array is [1, 1, 1, 1, 1, 1, 1, 1, 1]

Constraints:
1 <= n <= 50
1 <= m <= 100
0 <= k <= n

source from: leetcode 1420
*/

#include "algobase.h"
using namespace std;

#define MOD int(1e9 + 7)

int dp[101][51][51] = {};

int dfs(int n, int m, int k, int i, int max_val) {
  if (n == i)
    return k == 0;
  if (k < 0)
    return 0;
  if (dp[max_val][i][k] == 0) {
    dp[max_val][i][k] = 1;
    for (auto val = 1; val <= m; ++val) {
      dp[max_val][i][k] +=
          dfs(n, m, k - (max_val < val), i + 1, max(max_val, val));
      dp[max_val][i][k] %= MOD;
    }
  }
  return dp[max_val][i][k] - 1;
}

int numOfArrays(int n, int m, int k) { return dfs(n, m, k, 0, 0); }

int numOfArraysV2(int n, int m, int k) {
  if (m < k)
    return 0;
  int dp[2][m + 1][k + 1], mod = 1e9 + 7;
  memset(dp, 0, sizeof(dp));
  for (int j = 1; j <= m; ++j)
    dp[0][j][1] = j;
  for (int i = 1; i < n; ++i)
    for (int j = 1; j <= m; ++j)
      for (int l = 1; l <= min(i + 1, min(j, k)); ++l)
        dp[i & 1][j][l] =
            (dp[i & 1][j - 1][l] +
             (long)(dp[(i - 1) & 1][j][l] - dp[(i - 1) & 1][j - 1][l]) * j +
             dp[(i - 1) & 1][j - 1][l - 1]) %
            mod;
  return (dp[(n - 1) & 1][m][k] + mod) % mod;
}

int main() {
  auto ans = numOfArrays(50, 100, 25);
  cout << ans << endl;
  return 0;
}