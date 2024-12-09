/**
You are given an integer array nums where the ith bag contains nums[i] balls.
You are also given an integer maxOperations.

You can perform the following operation at most maxOperations times:

Take any bag of balls and divide it into two new bags with a positive number of
balls. For example, a bag of 5 balls can become two new bags of 1 and 4 balls,
or two new bags of 2 and 3 balls. Your penalty is the maximum number of balls in
a bag. You want to minimize your penalty after the operations.

Return the minimum possible penalty after performing the operations.



Example 1:

Input: nums = [9], maxOperations = 2
Output: 3
Explanation:
- Divide the bag with 9 balls into two bags of sizes 6 and 3. [9] -> [6,3].
- Divide the bag with 6 balls into two bags of sizes 3 and 3. [6,3] -> [3,3,3].
The bag with the most number of balls has 3 balls, so your penalty is 3 and you
should return 3. Example 2:

Input: nums = [2,4,8,2], maxOperations = 4
Output: 2
Explanation:
- Divide the bag with 8 balls into two bags of sizes 4 and 4. [2,4,8,2] ->
[2,4,4,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,4,4,4,2] ->
[2,2,2,4,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,4,4,2] ->
[2,2,2,2,2,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,2,2,4,2] ->
[2,2,2,2,2,2,2,2]. The bag with the most number of balls has 2 balls, so your
penalty is 2, and you should return 2.


Constraints:

1 <= nums.length <= 105
1 <= maxOperations, nums[i] <= 109

source from: leetcode 1760.
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

int minimumSize(vector<int>& nums, int maxOperations) {
  int n = nums.size();
  int l = 1, r = *max_element(nums.begin(), nums.end()), m;
  while (l < r) {
    m = l + (r - l) / 2;
    long long cnt = 0;
    for (int j = 0; j < n && cnt <= maxOperations; j++) {
      cnt += (nums[j] - 1) / m;
    }
    if (cnt <= maxOperations)
      r = m;
    else
      l = m + 1;
  }
  return r;
}

int main() {
  vector<int> nums1, nums2;
  nums1 = parse_vector("[9]");
  nums2 = parse_vector("[2,4,8,2]");

  print_res(minimumSize, nums1, 2);
  print_res(minimumSize, nums2, 4);

  return 0;
}
