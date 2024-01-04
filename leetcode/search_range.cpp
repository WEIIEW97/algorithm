/**
Given an array of integers nums sorted in non-decreasing order,
find the starting and ending position of a given target value.
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

source from: leetcode 34
*/

#include "algobase.h"
using namespace std;

// time complexity: O(n)
vector<int> searchRangeV1(vector<int>& nums, int target) {
  vector<int> res = {-1, -1};
  vector<int> rec;
  if (nums.empty())
    return res;
  int n = nums.size();
  bool seen = false;
  for (int i = 0; i < n; i++) {
    if (nums[i] == target)
      rec.push_back(i);
  }

  if (!rec.empty()) {
    res[0] = *rec.begin(), res[1] = rec.back();
  }
  return res;
}

int bs(vector<int>& nums, int target, int pos) {
  int res = -1;
  int l = 0, r = nums.size() - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (nums[m] > target)
      r = m - 1;
    else if (nums[m] < target)
      l = m + 1;
    else {
      res = m;
      if (pos == 1)
        l = m + 1;
      if (pos == -1)
        r = m - 1;
    }
  }
  return res;
}

vector<int> searchRangeV2(vector<int>& nums, int target) {
  return {bs(nums, target, -1), bs(nums, target, 1)};
}

// // binary search time complexity O(log n), failed to manage in one while loop
// vector<int> searchRangeV3(vector<int>& nums, int target) {
//     vector<int> res = {-1, -1};
//     if (nums.empty()) return res;
//     int l = 0;
//     int r = nums.size()-1;
//     while (l <= r) {
//         int m = l + (r - l)/2;
//         if((nums[m] < target) || (nums[m] == target && nums[m+1] == target))
//         l = m+1; if((nums[m] > target) || (nums[m] == target && nums[m-1] ==
//         target)) r = m-1; if(nums[m] == target && nums[m+1] > target) res[1]
//         = m; if(nums[m] == target && nums[m-1] < target) res[0] = m;
//     }
//     return res;
// }

// using stl `lower_bound` and `upper_bound`
vector<int> searchRangeV3(vector<int>& nums, int target) {
  const int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
  if (l == nums.size() || nums[l] != target)
    return {-1, -1};
  const int r =
      upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
  return {l, r};
}

int main() {
  vector<int> nums1 = {5, 7, 7, 8, 8, 10};
  vector<int> nums2 = {5, 7, 7, 8, 8, 10};
  vector<int> nums3 = {};
  vector<int> nums4 = {1, 3};

  int target1 = 8;
  int target2 = 6;
  int target3 = 0;
  int target4 = 1;
  auto ans = searchRangeV2(nums4, target4);
  PRINT_VECTOR_1D(ans);
  return 0;
}