/**
Given an array of integers nums sorted in non-decreasing order, find the
starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]


Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109

source from: leetcode 34.
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

vector<int> searchRange(vector<int>& nums, int target) {
  if (nums.empty())
    return {-1, -1};
  int l = 0, r = nums.size() - 1, m;
  while (l <= r) {
    m = l + (r - l) / 2;
    if (nums[m] < target) {
      l = m + 1;
    } else if (nums[m] > target) {
      r = m - 1;
    } else {
      r = m - 1;
    }
  }

  if (l >= nums.size() || nums[l] != target)
    return {-1, -1};
  int lx = l;
  r = nums.size() - 1;

  while (l <= r) {
    m = l + (r - l) / 2;
    if (nums[m] <= target) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  int rx = r;

  return {lx, rx};
}

vector<int> searchRangeV1(vector<int>& nums, int target) {
  const int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
  if (l == nums.size() || nums[l] != target)
    return {-1, -1};
  const int r =
      upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
  return {l, r};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // Your code here
  vector<int> nums1, nums2, nums3;
  nums1 = parse_vector("[5,7,7,8,8,10]");
  nums2 = parse_vector("[0,0,1,2,3,3,4]");
  nums3 = parse_vector("[1]");

  print_res(searchRange, nums1, 8);
  print_res(searchRange, nums2, 2);
  print_res(searchRange, nums3, 1);

  return 0;
}
