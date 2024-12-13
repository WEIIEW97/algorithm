/**
You are given an array nums consisting of positive integers.

Starting with score = 0, apply the following algorithm:

Choose the smallest integer of the array that is not marked. If there is a tie,
choose the one with the smallest index. Add the value of the chosen integer to
score. Mark the chosen element and its two adjacent elements if they exist.
Repeat until all the array elements are marked.
Return the score you get after applying the above algorithm.



Example 1:

Input: nums = [2,1,3,4,5,2]
Output: 7
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent
elements: [2,1,3,4,5,2].
- 2 is the smallest unmarked element, so we mark it and its left adjacent
element: [2,1,3,4,5,2].
- 4 is the only remaining unmarked element, so we mark it: [2,1,3,4,5,2].
Our score is 1 + 2 + 4 = 7.
Example 2:

Input: nums = [2,3,5,1,3,2]
Output: 5
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent
elements: [2,3,5,1,3,2].
- 2 is the smallest unmarked element, since there are two of them, we choose the
left-most one, so we mark the one at index 0 and its right adjacent element:
[2,3,5,1,3,2].
- 2 is the only remaining unmarked element, so we mark it: [2,3,5,1,3,2].
Our score is 1 + 2 + 2 = 5.


Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106

source from: leetcode 2593.
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

// straight-forward approach
long long findScoreV1(vector<int>& nums) {
  long long ans = 0;
  int n = nums.size();
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++)
    v.push_back({nums[i], i});

  sort(v.begin(), v.end());
  unordered_set<int> seen;

  for (auto s : v) {
    auto val = s.first;
    auto idx = s.second;
    if (seen.find(idx) == seen.end()) {
      ans += val;
      seen.insert(idx);
      seen.insert(idx - 1);
      seen.insert(idx + 1);
    }
  }
  return ans;
}

// downhill
long long findScore(vector<int>& nums) {
  long long ans = 0;
  for (int i = 0, n = nums.size(); i < n; i += 2) {
    // if i was chosen then i+1 whas chosen as well
    int i0 = i;
    while (i + 1 < n && nums[i] > nums[i + 1]) // find the bottom of the hill
      ++i;
    for (int j = i; j >= i0; j -= 2) // jumping add from i0 --> j
      ans += nums[j];
  }
  return ans;
}

int main() {
  vector<int> nums1, nums2;
  nums1 = parse_vector("[2,1,3,4,5,2]");
  nums2 = parse_vector("[2,3,5,1,3,2]");
  print_res(findScore, nums1);
  print_res(findScore, nums2);

  return 0;
}
