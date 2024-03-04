/**
Given an array arr of 4 digits, find the latest 24-hour time that can be made
using each digit exactly once. 24-hour times are formatted as "HH:MM", where HH
is between 00 and 23, and MM is between 00 and 59. The earliest 24-hour time is
00:00, and the latest is 23:59. Return the latest 24-hour time in "HH:MM"
format. If no valid time can be made, return an empty string.

Example 1:
Input: arr = [1,2,3,4]
Output: "23:41"
Explanation: The valid 24-hour times are "12:34", "12:43", "13:24", "13:42",
"14:23", "14:32", "21:34", "21:43", "23:14", and "23:41". Of these times,
"23:41" is the latest.

Example 2:
Input: arr = [5,5,5,5]
Output: ""
Explanation: There are no valid 24-hour times as "55:55" is not valid.

Constraints:

arr.length == 4
0 <= arr[i] <= 9

source from: leetcode 949.
*/

#include "algobase.h"
using namespace std;

string largestTimeFromDigits(vector<int>& arr) {
  auto is_valid = [](const string& h, const string& m) {
    return h < "24" && m < "60";
  };
  sort(arr.begin(), arr.end(), greater<int>());
  do {
    const string h = to_string(arr[0]) + to_string(arr[1]);
    const string m = to_string(arr[2]) + to_string(arr[3]);
    if (is_valid(h, m))
      return h + ":" + m;
  } while (prev_permutation(arr.begin(), arr.end()));
  return "";
}

int main() {
  vector<int> arr1 = {1, 2, 3, 4};
  vector<int> arr2 = {5, 5, 5, 5};

  // sort(arr1.begin(), arr1.end(), greater<int>());
  // cout << "array after sorting ..." << endl;
  // PRINT_VECTOR_1D(arr1);

  // do {
  //   cout << arr1[0] << "," << arr1[1] << "," << arr1[2] << "," << arr1[3] << "\n"; 
  // } while (prev_permutation(arr1.begin(), arr1.end()));

  cout << largestTimeFromDigits(arr1) << endl;
  cout << largestTimeFromDigits(arr2) << endl;
  return 0;
}
