/**
Given two strings s and t, return true if s is a subsequence of t, or false
otherwise. A subsequence of a string is a new string that is formed from the
original string by deleting some (can be none) of the characters without
disturbing the relative positions of the remaining characters. (i.e., "ace" is a
subsequence of "abcde" while "aec" is not).

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false

Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.

Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >=
109, and you want to check one by one to see if t has its subsequence. In this
scenario, how would you change your code?

source from: leetcode 392
*/

#include "algobase.h"
using namespace std;

bool isSubsequence(string s, string t) {
  int n1 = s.size(), n2 = t.size();
  int seen = 0;
  for (int i = 0; i < n2; i++) {
    if (t[i] == s[seen])
      seen++;
  }
  return seen == n1;
}

int main() {
  string s1 = "abc", t1 = "ahbgdc";
  string s2 = "axc", t2 = "ahbgdc";
  string s3 = "", t3 = "";
  string s4 = "acb", t4 = "ahbgdc";
  auto ans = isSubsequence(s4, t4);

  cout << ans << endl;
  return 0;
}