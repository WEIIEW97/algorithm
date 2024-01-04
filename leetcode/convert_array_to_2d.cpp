/**
You are given an integer array nums. You need to create a 2D array from nums s
atisfying the following conditions:
The 2D array should contain only the elements of the array nums.
Each row in the 2D array contains distinct integers.
The number of rows in the 2D array should be minimal.
Return the resulting array. If there are multiple answers, return any of them.

Note that the 2D array can have a different number of elements on each row.

Example 1:
Input: nums = [1,3,4,1,2,3,1]
Output: [[1,3,4,2],[1,3],[1]]
Explanation: We can create a 2D array that contains the following rows:
- 1,3,4,2
- 1,3
- 1
All elements of nums were used, and each row of the 2D array contains distinct
integers, so it is a valid answer. It can be shown that we cannot have less than
3 rows in a valid array.

Example 2:
Input: nums = [1,2,3,4]
Output: [[4,3,2,1]]
Explanation: All elements of the array are distinct, so we can keep all of them
in the first row of the 2D array.

Constraints:
1 <= nums.length <= 200
1 <= nums[i] <= nums.length

source from: leetcode 2610
*/

#include "algobase.h"
using namespace std;

vector<vector<int>> findMatrix(vector<int>& nums) {
  vector<int> frequency(nums.size() + 1);

  vector<vector<int>> result;
  for (int num : nums) {
    if (frequency[num] >= result.size()) {
      result.push_back({});
    }

    result[frequency[num]].push_back(num);
    frequency[num]++;
  }

  return result;
}

int main() {
  vector<int> nums1 = {1, 3, 4, 1, 2, 3, 1};
  vector<int> nums2 = {2, 1, 1};

  PRINT_VECTOR_2D(findMatrix(nums2));
  return 0;
}
