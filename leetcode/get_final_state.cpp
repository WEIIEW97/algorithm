/**
You are given an integer array nums, an integer k, and an integer multiplier.

You need to perform k operations on nums. In each operation:

Find the minimum value x in nums. If there are multiple occurrences of the
minimum value, select the one that appears first. Replace the selected minimum
value x with x * multiplier. Return an integer array denoting the final state of
nums after performing all k operations.



Example 1:

Input: nums = [2,1,3,5,6], k = 5, multiplier = 2

Output: [8,4,6,5,6]

Explanation:

Operation	Result
After operation 1	[2, 2, 3, 5, 6]
After operation 2	[4, 2, 3, 5, 6]
After operation 3	[4, 4, 3, 5, 6]
After operation 4	[4, 4, 6, 5, 6]
After operation 5	[8, 4, 6, 5, 6]
Example 2:

Input: nums = [1,2], k = 3, multiplier = 4

Output: [16,8]

Explanation:

Operation	Result
After operation 1	[4, 2]
After operation 2	[4, 8]
After operation 3	[16, 8]


Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
1 <= k <= 10
1 <= multiplier <= 5

source from: leetcode 3264.
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

vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
  using ip = pair<int, int>;
  priority_queue<ip, vector<ip>, greater<ip>> pq;
  for(int i=0; i<nums.size(); ++i) {
    pq.emplace(nums[i], i);
  }

  while(k-->0) {
    auto [v, idx] = pq.top();
    pq.pop();

    nums[idx] *= multiplier;
    pq.emplace(nums[idx], idx);
  }
  return nums;
} 

int main() {
  vector<int> nums1, nums2;
  nums1 = parse_vector("[2,1,3,5,6]");
  nums2 = parse_vector("[1,2]");

  print_res(getFinalState, nums1, 5, 2);
  print_res(getFinalState, nums2, 3, 4);

  return 0;
}
