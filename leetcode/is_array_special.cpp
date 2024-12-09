/**
An array is considered special if every pair of its adjacent elements contains
two numbers with different parity.

You are given an array of integer nums and a 2D integer matrix queries, where
for queries[i] = [fromi, toi] your task is to check that subarray
 nums[fromi..toi] is special or not.

Return an array of booleans answer such that answer[i] is true if
nums[fromi..toi] is special.



Example 1:

Input: nums = [3,4,1,2,6], queries = [[0,4]]

Output: [false]

Explanation:

The subarray is [3,4,1,2,6]. 2 and 6 are both even.

Example 2:

Input: nums = [4,3,1,6], queries = [[0,2],[2,3]]

Output: [false,true]

Explanation:

The subarray is [4,3,1]. 3 and 1 are both odd. So the answer to this query is
false. The subarray is [1,6]. There is only one pair: (1,6) and it contains
numbers with different parity. So the answer to this query is true.


Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
1 <= queries.length <= 105
queries[i].length == 2
0 <= queries[i][0] <= queries[i][1] <= nums.length - 1

source from: leetcode 3152.
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

vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
  const int n = nums.size();
  int prev = nums[0] & 1;
  vector<int> sameParity(n, 0);

  for (int i = 1, j = 0; i < n; i++) {
    bool x = nums[i] & 1;
    if (x == prev)
      j++;
    sameParity[i] = j;
    prev = x;
  }
  const int m = queries.size();
  vector<bool> ans(m, 0);
  for (int i = 0; i < m; i++) {
    int s = queries[i][0], t = queries[i][1];
    ans[i] = (sameParity[s] == sameParity[t]);
  }
  return ans;
}

// will cause TLE
vector<bool> isArraySpecialV2(vector<int>& nums, vector<vector<int>>& queries) {
  int m = queries.size();
  vector<bool> res;

  auto check = [](std::vector<int>::iterator begin,
                  std::vector<int>::iterator end) {
    for (auto it = begin; it != end - 1; ++it) {
      if ((*it % 2) == (*(it + 1) % 2))
        return false;
    }
    return true;
  };

  int j = 0;
  for (auto q : queries) {
    int s = q[0], e = q[1];
    res.emplace_back(check(nums.begin() + s, nums.begin() + e + 1));
  }
  return res;
}

int main() {
  vector<int> nums1, nums2;
  vector<vector<int>> queries1, queries2;

  nums1 = parse_vector("[3,4,1,2,6]");
  queries1 = parse_matrix("[3,4,1,2,6]");
  nums2 = parse_vector("[4,3,1,6]");
  queries2 = parse_matrix("[[0,2],[2,3]]");

  print_res(isArraySpecial, nums1, queries1);
  print_res(isArraySpecial, nums2, queries2);

  return 0;
}
