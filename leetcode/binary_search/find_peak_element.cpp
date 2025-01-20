/**
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index.
If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is
always considered to be strictly greater than a neighbor that is outside the
array.

You must write an algorithm that runs in O(log n) time.



Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index
number 2. Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak
element is 2, or index number 5 where the peak element is 6.


Constraints:

1 <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
nums[i] != nums[i + 1] for all valid i.

source from: leetcode 162.
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

int findPeakElement(vector<int>& nums) {
  int n = nums.size();
  if (n == 1)
    return 0;
  if (nums[0] > nums[1])
    return 0;
  if (nums[n - 1] > nums[n - 2])
    return n - 1;

  int l = 1, r = n - 2, m;
  while (l <= r) {
    m = l + (r - l) / 2;
    if (nums[m] > nums[m + 1] && nums[m] > nums[m - 1]) {
      return m;
    } else if (nums[m] > nums[m - 1]) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // Your code here
  vector<int> nums1, nums2;
  nums1 = parse_vector("[1,2,3,1]");
  nums2 = parse_vector("[1,2,1,3,5,6,4]");

  print_res(findPeakElement, nums1);
  print_res(findPeakElement, nums2);

  return 0;
}
