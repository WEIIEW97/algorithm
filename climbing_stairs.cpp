/**
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct
ways can you climb to the top?

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Constraints:
1 <= n <= 45

source from: leetcode 70
*/

#include "algobase.h"
using namespace std;

// this is theorectial right but `tgamma` would throw precision problem
int climbStairsV1(int m) {
  int res = 0;
  int n, r;
  for (n = m, r = 0; r <= n; --n, ++r) {
    res += tgamma(n + 1) / (tgamma(r + 1) * tgamma(n - r + 1));
  }

  return res;
}

// this is a more solid way, in combinations
int BC(int n, int r) {
  int coeff = 1;
  if (r > n - r)
    r = n - r; // Because C(n, r) == C(n, n-r)

  for (int i = 0; i < r; ++i) {
    coeff *= (n - i);
    coeff /= (i + 1);
  }

  return coeff;
}

int climbStairsV2(int m) {
  int res = 0;
  for (int r = 0; r <= m / 2; ++r) {
    int n = m - r;
    res += BC(n, r);
  }
  return res;
}

// use dynamic programming
int climbStarisV3(int m) {
  vector<int> dp(m + 1, -1);
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i < m + 1; i++) {
    dp[i] = dp[i - 2] + dp[i - 1];
  }
  return dp[m];
}

int main() {
  int n1 = 2;
  int n2 = 3;
  auto ans = climbStarisV3(31);
  cout << ans << endl;
  return 0;
}