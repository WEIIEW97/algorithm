/**
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the
median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).



Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

source from: leetcode 4.
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

// using binary search
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  if (nums1.size() > nums2.size())
    return findMedianSortedArrays(nums2, nums1);
  int m = nums1.size(), n = nums2.size();
  int l = 0, r = m;
  while (l <= r) {
    int mx = l + (r - l) / 2;
    int my = (m + n + 1) / 2 - mx;
    int max_left_x = (mx == 0) ? INT_MIN : nums1[mx - 1];
    int min_right_x = (mx == m) ? INT_MAX : nums1[mx];

    int max_left_y = (my == 0) ? INT_MIN : nums2[my - 1];
    int min_right_y = (my == n) ? INT_MAX : nums2[my];

    if (max_left_x <= min_right_y && max_left_y <= min_right_x) {
      if ((m + n) % 2 == 0)
        return (max(max_left_x, max_left_y) + min(min_right_x, min_right_y)) /
               2.0;
      else
        return double(max(max_left_x, max_left_y));
    } else if (max_left_x > min_right_y) {
      r = mx - 1;
    } else {
      l = mx + 1;
    }
  }
  return -1;
}

// staright-forward
double findMedianSortedArraysV1(vector<int>& nums1, vector<int>& nums2) {
  vector<int> merged;
  merged.reserve(nums1.size() + nums2.size());
  merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(),
        back_inserter(merged));

  int n = merged.size();
  if (n % 2 == 1) {
    return static_cast<double>(merged[n / 2]);
  } else {
    return (static_cast<double>(merged[n / 2 - 1]) + merged[n / 2]) / 2.0;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // Your code here
  vector<int> m1, m2, n1, n2;
  m1 = parse_vector("[1,3]");
  n1 = parse_vector("[2]");
  m2 = parse_vector("[1,2]");
  n2 = parse_vector("[3,4]");

  print_res(findMedianSortedArrays, m1, n1);
  print_res(findMedianSortedArrays, m2, n2);

  return 0;
}
