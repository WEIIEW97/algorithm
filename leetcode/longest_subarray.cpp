/**
You are given an integer array nums of size n.

Consider a non-empty subarray from nums that has the maximum possible bitwise
AND.

In other words, let k be the maximum value of the bitwise AND of any subarray of
nums. Then, only subarrays with a bitwise AND equal to k should be considered.
Return the length of the longest such subarray.

The bitwise AND of an array is the bitwise AND of all the numbers in it.

A subarray is a contiguous sequence of elements within an array.



Example 1:

Input: nums = [1,2,3,3,2,2]
Output: 2
Explanation:
The maximum possible bitwise AND of a subarray is 3.
The longest subarray with that value is [3,3], so we return 2.
Example 2:

Input: nums = [1,2,3,4]
Output: 1
Explanation:
The maximum possible bitwise AND of a subarray is 4.
The longest subarray with that value is [4], so we return 1.


Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106

source from: leetcode 2419.
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

int longestSubarray(vector<int>& nums) {
  auto maxv = max_element(nums.begin(), nums.end());
  int max_len = 0, cur_len = 0;
  for (auto& num : nums) {
    if (num == *maxv) {
      cur_len++;
      max_len = max(max_len, cur_len);
    } else {
      cur_len = 0;
    }
  }
  return max_len;
}

int main() {
  auto nums1 = parse_vector("1,2,3,3,2,2");
  auto nums2 = parse_vector("1,2,3,4");

  print_res(longestSubarray, nums1);
  print_res(longestSubarray, nums2);
  return 0;
}
