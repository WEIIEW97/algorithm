/**
Given two strings s and t, return true if they are equal when both are typed
into empty text editors. '#' means a backspace character.
Note that after backspacing an empty text, the text will continue empty.

Example 1:
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Example 2:
Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".

Example 3:
Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".

Constraints:
1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.

source from: leetcode 844
*/

#include "algobase.h"
using namespace std;

// use 2 pointers, space complexity O(1)
bool backspaceCompareV1(string s, string t) {
  int sPtr = 0, tPtr = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != '#') {
      if (sPtr < 0)
        sPtr = 0;
      s[sPtr] = s[i];
      sPtr++;
    } else {
      sPtr--;
    }
  }
  s = s.substr(0, sPtr);
  for (int j = 0; j < t.size(); j++) {
    if (t[j] != '#') {
      if (tPtr < 0)
        tPtr = 0;
      t[tPtr] = t[j];
      tPtr++;
    } else {
      tPtr--;
    }
  }
  t = t.substr(0, tPtr);
  return s == t;
}

// use stack-like, space complexity O(n)
bool backspaceCompareV2(string s, string t) {
  string ss, tt;
  for (auto& c : s) {
    if (c == '#') {
      if (!ss.empty())
        ss.pop_back();
    } else
      ss.push_back(c);
  }
  for (auto& c : t) {
    if (c == '#') {
      if (!tt.empty())
        tt.pop_back();
    } else
      tt.push_back(c);
  }
  return ss == tt;
}

int main() {
  string s, t;
  s = "a##c", t = "#a#c";
  auto ans = backspaceCompareV2(s, t);
  if (ans)
    cout << "true" << endl;
  else
    cout << "false" << endl;
  return 0;
}
