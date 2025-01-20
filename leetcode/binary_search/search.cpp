/**
There is an integer array nums sorted in non-decreasing order (not necessarily
with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index
k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1],
..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example,
[0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become
[4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if
target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.



Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false


Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
nums is guaranteed to be rotated at some pivot.
-104 <= target <= 104
source from: leetcode 81.
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

bool search11(vector<int>& nums, int target) {
  int l = 0, r = nums.size() - 1, m;
  while (l <= r) {
    m = l + (r - l) / 2;
    if (nums[m] == target) {
      return true;
    }

    // When nums[m] == nums[l] or nums[m] == nums[r], just skip them
    if (nums[m] == nums[l] && nums[m] == nums[r]) {
      ++l;
      --r;
    }
    // If the left segment is sorted
    else if (nums[m] >= nums[l]) {
      if (target >= nums[l] && target < nums[m]) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    // If the right segment is sorted
    else {
      if (target > nums[m] && target <= nums[r]) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // Your code here
  vector<int> nums1, nums2;
  nums1 = parse_vector("[2,5,6,0,0,1,2]");
  nums2 = parse_vector("[2,5,6,0,0,1,2]");
  print_res(search11, nums1, 0);
  print_res(search11, nums2, 3);
  return 0;
}
