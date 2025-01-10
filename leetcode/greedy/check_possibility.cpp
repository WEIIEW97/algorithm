/**
Given an array nums with n integers, your task is to check if it could become
non-decreasing by modifying at most one element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i
(0-based) such that (0 <= i <= n - 2).



Example 1:

Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
Example 2:

Input: nums = [4,2,1]
Output: false
Explanation: You cannot get a non-decreasing array by modifying at most one
element.


Constraints:

n == nums.length
1 <= n <= 104
-105 <= nums[i] <= 105

source from: leetcode 665.
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

bool checkPossibility(vector<int>& nums) {
  int n = nums.size();
  int prev = nums[0], modify = 0;
  for (int i = 0; i < n; ++i) {
    if (nums[i] < prev) {
      if (++modify > 1) // if modification>1, return false
        return false;
      if (i - 2 >= 0 && nums[i - 2] > nums[i])
        continue;
    }
    prev = nums[i];
  }
  return true;
}

int main() {
  vector<int> nums1, nums2;
  nums1 = parse_vector("[-1,4,2,3]");
  nums2 = parse_vector("[5,7,1,8]");

  print_res(checkPossibility, nums1);
  print_res(checkPossibility, nums2);

  return 0;
}
