/**
You are given a sorted array consisting of only integers where every element
appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.



Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10


Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105

source from: leetcode 540.
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

int singleNonDuplicate(vector<int>& nums) {
  int l = 0, r = nums.size()-1;
  while (l < r) {
    int m = l + (r - l) / 2;
    if (m % 2 == 1)
      m--;
    if (nums[m] == nums[m + 1])
      l = m + 2;
    else
      r = m;
  }
  return nums[l];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // Your code here
  vector<int> n1, n2;
  n1 = parse_vector("[1,1,2,3,3,4,4,8,8]");
  n2 = parse_vector("[3,3,7,7,10,11,11]");

  print_res(singleNonDuplicate, n1);
  print_res(singleNonDuplicate, n2);

  return 0;
}
