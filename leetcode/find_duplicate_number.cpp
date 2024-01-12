/**
Given an array of integers nums containing n + 1 integers where each integer is
in the range [1, n] inclusive. There is only one repeated number in nums, return
this repeated number. You must solve the problem without modifying the array
nums and uses only constant extra space.

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2

Example 2:

Input: nums = [3,1,3,4,2]
Output: 3

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which
appears two or more times.

source from: leetcode 287
*/

#include "algobase.h"
using namespace std;

// intuitive but memory costy
int findDuplicateV1(vector<int>& nums) {
  unordered_map<int, int> seen;
  for (auto& n : nums) {
    seen[n]++;
  }

  for (auto& p : seen) {
    if (p.second > 1) {
      return p.first;
    }
  }

  return -1;
}

// use unordered_set
int findDuplicateV2(vector<int>& nums) {
  unordered_set<int> seen;
  for (auto& v : nums) {
    if (seen.find(v) != seen.end())
      return v;
    seen.insert(v);
  }
  return -1;
}

// fast-slow pointer
int findDuplicateV3(vector<int>& nums) {
  int fast = 0;
  int slow = 0;
  while (true) {
    fast = nums[nums[fast]];
    slow = nums[slow];
    if (slow == fast)
      break;
  }

  fast = 0;
  while (true) {
    fast = nums[fast];
    slow = nums[slow];
    if (fast == slow)
      return slow;
  }

  return -1;
}

int main() {
  vector<int> nums1 = {1, 3, 4, 2, 3};
  vector<int> nums2 = {3, 1, 3, 4, 2};

  auto ans = findDuplicateV3(nums1);
  cout << ans << endl;

  return 0;
}