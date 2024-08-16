/**
The distance of a pair of integers a and b is defined as the absolute difference
between a and b. Given an integer array nums and an integer k, return the kth
smallest distance among all the pairs nums[i} and nums[j} where 0 <= i < j <
nums.length.

Example 1:

Input: nums = [1,3,1}, k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
Example 2:

Input: nums = [1,1,1}, k = 2
Output: 0
Example 3:

Input: nums = [1,6,1}, k = 3
Output: 5


Constraints:

n == nums.length
2 <= n <= 104
0 <= nums[i} <= 106
1 <= k <= n * (n - 1) / 2

source from: leetcode 719.
*/

#include "algobase.h"
using namespace std;

int smallestDistancePair_brutal(vector<int>& nums, int k) {
  vector<int> diff;
  int n = nums.size();
  for (int i = 0; i < n - 1; ++i) {
    for (int j = n; i < j; j--) {
      diff.push_back(abs(nums[i] - nums[j]));
    }
  }
  sort(diff.begin(), diff.end());
  return diff[k - 1];
}

int smallestDistancePair(vector<int>& nums, int k) {
  sort(nums.begin(), nums.end());

  int n = nums.size();
  int low = 0;
  int high = nums[n - 1] - nums[0];

  auto countPairs = [&](int max_distance) {
    int count = 0;
    int left = 0;
    for (int right = 0; right < n; right++) {
      while (nums[right] - nums[left] > max_distance) {
        left++;
      }
      count += right - left;
    }
    return count;
  };

  while (low < high) {
    int mid = (low + high) / 2;
    if (countPairs(mid) < k) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }

  return low;
}

int main() {
  vector<int> num1 = {1, 3, 1};
  vector<int> num2 = {
      1,
      1,
      1,
  };
  vector<int> num3 = {1, 6, 1};

  cout << smallestDistancePair(num1, 1) << "\n";
  cout << smallestDistancePair(num2, 2) << "\n";
  cout << smallestDistancePair(num3, 3) << "\n";
  return 0;
}
