/**
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and
'-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and
concatenate them to build the expression "+2-1". Return the number of different
expressions that you can build, which evaluates to target.



Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be
target 3. -1 + 1 + 1 + 1 + 1 = 3 +1 - 1 + 1 + 1 + 1 = 3 +1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1


Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000

source from: leetcode 494.
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

int findTargetSumWays(vector<int>& nums, int target) {
  int n = nums.size();
  auto sum = accumulate(nums.begin(), nums.end(), 0);
  int diff = sum - target;

  if (diff < 0 || diff % 2 != 0)
    return 0;
  diff /= 2;

  int dp[21][1001] = {{0}};

  dp[0][0] = 1;
  for (int j = 1; j <= n; j++) {
    for (int sum = 0; sum <= diff; sum++) {
      dp[j][sum] = dp[j - 1][sum];
      if (sum >= nums[j - 1])
        dp[j][sum] += dp[j - 1][sum - nums[j - 1]];
    }
  }
  return dp[n][diff];
}

int main() {
  vector<int> nums1, nums2;
  nums1 = parse_vector("[1,1,1,1,1]");
  nums2 = parse_vector("[1]");

  print_res(findTargetSumWays, nums1, 3);
  print_res(findTargetSumWays, nums2, 1);

  return 0;
}
