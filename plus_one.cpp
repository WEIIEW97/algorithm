/**
You are given a large integer represented as an integer array digits, where each
digits[i] is the ith digit of the integer. The digits are ordered from most
significant to least significant in left-to-right order. The large integer does
not contain any leading 0's. Increment the large integer by one and return the
resulting array of digits.

Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Example 2:
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

Example 3:
Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].

Constraints:

1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.

source from: leetcode 66
*/

#include "algobase.h"
using namespace std;

// extremely slow and memory cost version
class Solution1 {
public:
  vector<int> plusOne(vector<int> &digits) {
    int n = digits.size();
    if (digits.back() < 9) {
      digits.back()++;
      return digits;
    } else {
      for (auto iter = digits.rbegin(); iter != digits.rend(); ++iter) {
        check9(iter);
        if (*iter != 0) {
          break;
        }
      }
      if (digits.front() == 0) {
        digits.insert(digits.begin(), 1);
      }
      return digits;
    }
  }

  void check9(vector<int>::reverse_iterator &iter) {
    if (*iter >= 9) {
      *iter = 0;
    } else {
      ++(*iter);
    }
  }
};

class Solution2 {
public:
  vector<int> plusOne(vector<int> &digits) {
    for (int i = digits.size() - 1; i >= 0; i--) {
      if (digits[i] < 9) {
        digits[i]++;
        break;
      }
      digits[i] = 0;
    }

    if (digits[0] == 0) {
      digits.insert(digits.begin(), 1);
    }
    return digits;
  }
};

int main() {
  vector<int> digits1 = {4, 3, 2, 1};
  vector<int> digits2 = {1,9, 9};
  vector<int> digits3 = {1, 2, 3};

  auto solver = Solution2();
  auto res = solver.plusOne(digits2);
  PRINT_VECTOR_1D(res);
  return 0;
}