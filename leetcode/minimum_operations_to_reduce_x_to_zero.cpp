/**
You are given an integer array nums and an integer x. In one operation, you can
either remove the leftmost or the rightmost element from the array nums and
subtract its value from x. Note that this modifies the array for future
operations. Return the minimum number of operations to reduce x to exactly 0 if
it is possible, otherwise, return -1.

Example 1:
Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x
to zero.

Example 2:
Input: nums = [5,6,7,8,9], x = 4
Output: -1

Example 3:
Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the
first two elements (5 operations in total) to reduce x to zero.

Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 104
1 <= x <= 109

source from: leetcode 1658
*/

#include "algobase.h"
using namespace std;

// int minOperations(vector<int> &nums, int x) {
//   int ops = 0;
//   int sum = accumulate(nums.begin(), nums.end(), 0);
//   bool rem;
//   int to_remove, offset;
//   auto min_val = min_element(nums.begin(), nums.end());
//   if (sum < x || x < *min_val)
//     return -1;
//   if (sum == x)
//     return nums.size();

//   while (x) {
//     rem = (x == nums[0] || x == nums.back()) ? true : false;
//     if (rem) {
//       ops++;
//       x = 0;
//       break;
//     } else {
//       auto leftmost = nums[0], rightmost = nums.back();
//       if (leftmost < x && rightmost < x) {
//         to_remove = max(leftmost, rightmost);
//         offset = (to_remove == leftmost) ? 0 : nums.size() - 1;
//       } else {
//         to_remove = min(leftmost, rightmost);
//         offset = (to_remove == leftmost) ? 0 : nums.size() - 1;
//       }
//       x -= to_remove;
//       cout << "to_remove: " << to_remove << " index is " << offset << endl;
//       PRINT_VECTOR_1D(nums);
//       cout << "x: " << x << endl;
//       nums.erase(nums.begin() + offset);
//       ops++;
//       if (x <= 0)
//         break;
//     }
//   }

//   return x == 0 ? ops : -1;
// }

int minOperations(vector<int>& nums, int x) {
  int i = 0, j = 0, n = nums.size(), len = INT_MIN, cur = 0;
  int tar = accumulate(nums.begin(), nums.end(), 0) - x;
  if (tar < 0)
    return -1;
  while (j < n) {
    cur += nums[j];
    while (cur > tar)
      cur -= nums[i++];
    if (cur == tar)
      len = max(len, j - i + 1);
    j++;
  }
  return len == INT_MIN ? -1 : n - len;
}

int main() {
  vector<int> nums1 = {1, 1, 4, 2, 3};
  vector<int> nums2 = {5, 6, 7, 8, 9};
  vector<int> nums3 = {3, 2, 20, 1, 1, 3};
  vector<int> nums4 = {
      5207, 5594, 477,  6938, 8010, 7606, 2356, 6349, 3970, 751,  5997, 6114,
      9903, 3859, 6900, 7722, 2378, 1996, 8902, 228,  4461, 90,   7321, 7893,
      4879, 9987, 1146, 8177, 1073, 7254, 5088, 402,  4266, 6443, 3084, 1403,
      5357, 2565, 3470, 3639, 9468, 8932, 3119, 5839, 8008, 2712, 2735, 825,
      4236, 3703, 2711, 530,  9630, 1521, 2174, 5027, 4833, 3483, 445,  8300,
      3194, 8784, 279,  3097, 1491, 9864, 4992, 6164, 2043, 5364, 9192, 9649,
      9944, 7230, 7224, 585,  3722, 5628, 4833, 8379, 3967, 5649, 2554, 5828,
      4331, 3547, 7847, 5433, 3394, 4968, 9983, 3540, 9224, 6216, 9665, 8070,
      31,   3555, 4198, 2626, 9553, 9724, 4503, 1951, 9980, 3975, 6025, 8928,
      2952, 911,  3674, 6620, 3745, 6548, 4985, 5206, 5777, 1908, 6029, 2322,
      2626, 2188, 5639};
  auto ans = minOperations(nums4, 565610);
  cout << ans << endl;
  return 0;
}