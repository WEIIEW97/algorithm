/**
You are given two strings s and t.
String t is generated by random shuffling string s
and then add one more letter at a random position.
Return the letter that was added to t.

Example 1:
Input: s = "abcd", t = "abcde"
Output: "e"
Explanation: 'e' is the letter that was added.

Example 2:
Input: s = "", t = "y"
Output: "y"

Constraints:
0 <= s.length <= 1000
t.length == s.length + 1
s and t consist of lowercase English letters.

source from: leetcode 389
*/

#include "algobase.h"
using namespace std;

// intuitive way: double pointer
char findTheDifferenceV1(string s, string t) {
  if (s.empty())
    return t[0];
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  int seen = 0;
  int n = t.size();
  for (int i = 0; i < n; i++) {
    if (t[i] == s[seen]) {
      seen++;
    } else {
      return t[i];
    }
  }
  return 'c';
}

// use XOR
char findTheDifferenceV2(string s, string t) {
  char d = 0;
  for (const auto& c : s + t) {
    d ^= c;
  }
  return d;
}

int main() {
  string s1 = "abcd", t1 = "abcde";
  string s2 = "", t2 = "y";
  auto ans = findTheDifferenceV1(s1, t1);
  cout << ans << endl;
  return 0;
}
