/**
You are given an integer array nums. In one operation, you can replace any
element in nums with any integer. nums is considered continuous if both of the
following conditions are fulfilled:

All elements in nums are unique.
The difference between the maximum element and the minimum element in nums
equals nums.length - 1. For example, nums = [4, 2, 5, 3] is continuous, but nums
= [1, 2, 3, 5, 6] is not continuous.

Return the minimum number of operations to make nums continuous.

Example 1:
Input: nums = [4,2,5,3]
Output: 0
Explanation: nums is already continuous.

Example 2:
Input: nums = [1,2,3,5,6]
Output: 1
Explanation: One possible solution is to change the last element to 4.
The resulting array is [1,2,3,5,4], which is continuous.

Example 3:
Input: nums = [1,10,100,1000]
Output: 3
Explanation: One possible solution is to:
- Change the second element to 2.
- Change the third element to 3.
- Change the fourth element to 4.
The resulting array is [1,2,3,4], which is continuous.

Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 109

source from: leetcode 2009
*/

#include "algobase.h"
using namespace std;

// shrinkable sliding window
int minOperationsV1(vector<int>& nums) {
  int n = nums.size(), i = 0, j = 0, moves = 0;
  sort(nums.begin(), nums.end());
  nums.erase(unique(nums.begin(), nums.end()), nums.end());
  for (int m = nums.size(); j < m; j++) {
    while (nums[i] + n <= nums[j])
      ++i;
    moves = max(moves, j - i + 1);
  }
  return n - moves;
}

// non-shrinkable sliding window
int minOperationsV2(vector<int>& nums) {
  int n = nums.size(), i = 0, j = 0;
  sort(nums.begin(), nums.end());
  nums.erase(unique(nums.begin(), nums.end()), nums.end());
  for (int m = nums.size(); j < m; j++) {
    if (nums[i] + n <= nums[j])
      i++;
  }
  return n - j + i;
}

int main() {
  vector<int> nums1, nums2, nums3;
  nums1 = {4, 2, 3, 5};
  nums2 = {1, 2, 3, 5, 6};
  nums3 = {1, 10, 100, 1000};
  auto ans = minOperationsV2(nums3);
  cout << ans << endl;
  return 0;
}