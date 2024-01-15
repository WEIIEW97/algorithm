/**
Given an unsorted array of integers nums, return the
length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109

source from: leetcode 128.
*/

#include "algobase.h"
using namespace std;

int longestConsecutive(vector<int>& nums) {
  if (nums.empty() || nums.size() == 1)
    return nums.size();
  sort(nums.begin(), nums.end());
  int temp = 1;
  int count = -1;
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] - nums[i - 1] == 1)
      temp++;
    else if (nums[i] - nums[i - 1] == 0)
      continue;
    else {
      count = max(count, temp);
      temp = 1;
    }
  }
  count = max(count, temp);
  return count;
}

int main() {
  vector<int> num1 = {100, 4, 200, 1, 3, 2};
  vector<int> num2 = {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6};
  vector<int> num3 = {0, 1, 2, 1};
  cout << longestConsecutive(num1) << endl;
  cout << longestConsecutive(num2) << endl;
  cout << longestConsecutive(num3) << endl;
  return 0;
}
