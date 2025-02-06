/**
Suppose an array of length n sorted in ascending order is rotated between 1 and
n times. For example, the array nums = [0,1,4,4,5,6,7] might become:

[4,5,6,7,0,1,4] if it was rotated 4 times.
[0,1,4,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in
the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums that may contain duplicates, return the
minimum element of this array.

You must decrease the overall operation steps as much as possible.



Example 1:

Input: nums = [1,3,5]
Output: 1
Example 2:

Input: nums = [2,2,2,0,1]
Output: 0


Constraints:

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
nums is sorted and rotated between 1 and n times.


Follow up: This problem is similar to Find Minimum in Rotated Sorted Array, but
nums may contain duplicates. Would this affect the runtime complexity? How and
why?



source from: leetcode 154.
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

int findMin(vector<int>& nums) {
  int l = 0, r = nums.size() - 1;
  while (l < r) {
    int m = l + (r - l) / 2;
    if (nums[m] > nums[r])
      l = m + 1;
    else if (nums[m] < nums[r])
      r = m;
    else
      r -= 1;
  }
  return nums[l];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // Your code here

  vector<int> n1, n2;
  n1 = parse_vector("[1,3,5]");
  n2 = parse_vector("[2,2,2,0,1]");

  print_res(findMin, n1);
  print_res(findMin, n2);
  return 0;
}
