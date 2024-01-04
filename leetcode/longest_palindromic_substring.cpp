/**
Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters.

source from: leetcode 5
*/

#include "algobase.h"
using namespace std;

string longestPalindrome(string s) {
  if (s.size() < 2)
    return s;
  int max_len = 0;
  int i = 0;
  int start_idx = 0;
  while (i < s.size()) {
    int l_ptr = i;
    int r_ptr = i;
    while (r_ptr < s.size() - 1 && s[r_ptr] == s[r_ptr + 1])
      r_ptr++;
    i = r_ptr + 1;
    while (r_ptr < s.size() - 1 && l_ptr > 0 && s[r_ptr + 1] == s[l_ptr - 1]) {
      r_ptr++;
      l_ptr--;
    }
    int new_len = r_ptr - l_ptr + 1;
    if (new_len > max_len) {
      max_len = new_len;
      start_idx = l_ptr;
    }
  }
  return s.substr(start_idx, max_len);
}

int main() {
  cout << longestPalindrome("babad") << endl;
  return 0;
}
