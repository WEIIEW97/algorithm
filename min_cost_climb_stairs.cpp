/**
You are given an integer array cost where cost[i] is the cost of ith step on a
staircase. Once you pay the cost, you can either climb one or two steps. You can
either start from the step with index 0, or the step with index 1. Return the
minimum cost to reach the top of the floor.

Example 1:
Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Example 2:
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.

Constraints:
2 <= cost.length <= 1000
0 <= cost[i] <= 999

source from: leetcode 746
*/

#include "algobase.h"
using namespace std;

// iterative dp
int minCostClimbingStairsV1(vector<int>& cost) {
  int N = cost.size();
  vector<int> dp(N + 1, 0);
  for (int i = N - 2; i >= 0; i--) {
    dp[i] = min(cost[i] + dp[i + 1], cost[i + 1] + dp[i + 2]);
  }
  return dp[0];
}

// alternative
int minCostClimbingStairsV2(vector<int>& cost) {
  int N = cost.size();
  for (int i = 2; i < N; i++) {
    cost[i] += min(cost[i - 1], cost[i - 2]);
  }
  return min(cost[N - 1], cost[N - 2]);
}

int main() {
  vector<int> cost = {10, 15, 20};
  auto ans = minCostClimbingStairsV1(cost);
  cout << ans << endl;
  return 0;
}