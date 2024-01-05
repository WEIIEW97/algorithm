/**
Given an integer array nums, return the length of the longest strictly
increasing subsequence
.

Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the
length is 4.

Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1

Constraints:
1 <= nums.length <= 2500
-104 <= nums[i] <= 104

source from: leetcode 300
*/

#include "algobase.h"
using namespace std;

// DP
int lengthOfLIS1(vector<int>& nums) {
  vector<int> dp(nums.size(), 1);
  for (int i = 0; i < nums.size(); i++) {
    for (int j = 0; j < i; j++) {
      if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
        dp[i] = dp[j] + 1;
    }
  }
  return *max_element(dp.begin(), dp.end());
}

// greedy with binary search
int lengthOfLIS2(vector<int>& nums) {
  vector<int> sub;
  for (auto& x : nums) {
    if (sub.empty() || sub.back() < x) {
      sub.push_back(x);
    } else {
      auto it = lower_bound(sub.begin(), sub.end(), x);
      *it = x;
    }
  }
  return sub.size();
}

int main() {
  vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
  vector<int> nums2 = {0, 1, 0, 3, 2, 3};
  vector<int> nums3 = {7, 7, 7, 7, 7, 7, 7};

  cout << lengthOfLIS2(nums1) << endl;
  cout << lengthOfLIS2(nums2) << endl;
  cout << lengthOfLIS2(nums3) << endl;
  return 0;
}
