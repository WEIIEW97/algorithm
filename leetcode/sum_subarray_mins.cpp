/**
Given an array of integers arr, find the sum of min(b), where b ranges over
every (contiguous) subarray of arr. Since the answer may be large, return
the answer modulo 109 + 7.

Example 1:
Input: arr = [3,1,2,4]
Output: 17
Explanation:
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4],
[3,1,2,4]. Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1. Sum is 17.

Example 2:
Input: arr = [11,81,94,43,3]
Output: 444

Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104

source from: leetcode 907.
*/

#include "algobase.h"
using namespace std;

int sumSubarrayMins(vector<int>& arr) {
  int M = 1e9 + 7;
  long long ans = 0;
  for (int i = 0; i < arr.size(); i++) {
    int right = 0, left = 0;
    long long curr = 0;
    int j = i;
    while (j < arr.size() && arr[j] >= arr[i]) {
      right++;
      j++;
    }
    curr = curr + (arr[i] * right);
    ans += curr;
    j = i - 1;
    while (j >= 0 && arr[j] > arr[i]) {
      left++;
      j--;
    }
    ans += (left * curr);
    ans = ans % M;
  }
  return (int)ans;
}

int main() {
  vector<int> arr1 = {3, 1, 2, 4};
  vector<int> arr2 = {11, 81, 94, 43, 3};
  cout << sumSubarrayMins(arr1) << endl;
  cout << sumSubarrayMins(arr2) << endl;
  return 0;
}
