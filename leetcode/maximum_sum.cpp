/**
You are given a 0-indexed array nums consisting of positive integers. You can
choose two indices i and j, such that i != j, and the sum of digits of the
number nums[i] is equal to that of nums[j].

Return the maximum value of nums[i] + nums[j] that you can obtain over all
possible indices i and j that satisfy the conditions.



Example 1:

Input: nums = [18,43,36,13,7]
Output: 54
Explanation: The pairs (i, j) that satisfy the conditions are:
- (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36
= 54.
- (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7
= 50. So the maximum sum that we can obtain is 54. Example 2:

Input: nums = [10,12,19,14]
Output: -1
Explanation: There are no two numbers that satisfy the conditions, so we return
-1.


Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109

source from: leetcode 2342.
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

int sumdigits(int v) {
  int s = 0;
  while (v != 0) {
    s += v % 10;
    v /= 10;
  }
  return s;
}

int maximumSum(vector<int>& nums) {
  unordered_map<int, vector<int>> freq(nums.size());
  for (int num : nums) {
    freq[sumdigits(num)].push_back(num);
  }

  int ans = -1;
  for (auto [k, v] : freq) {
    if (v.size() > 1) {
      sort(v.rbegin(), v.rend());
      int tmp = v[0] + v[1];
      ans = max(ans, tmp);
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // Your code here
  vector<int> n1, n2;
  n1 = parse_vector("[18,43,36,13,7]");
  n2 = parse_vector("[10,12,19,14]");
  print_res(maximumSum, n1);
  print_res(maximumSum, n2);
  
  return 0;
}
