/**
Given a string s consisting of words and spaces, return the length of the
last word in the string.
A word is a maximal substring consisting of non-space characters only.

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Example 2:
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Example 3:
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.

Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.

source from: leetcode 58
*/

#include "algobase.h"
using namespace std;

// intuitive way
int lengthOfLastWordV1(string s) {
  int cnt = 0, ans = 0;
  bool is_char;
  for (auto &v : s) {
    is_char = (v >= 'a' && v <= 'z') || (v >= 'A' && v <= 'Z') ? true : false;

    if (is_char) {
      cnt++;
      ans = cnt;
    } else {
      cnt = 0;
    }
  }
  return ans;
}

// search in reverse order
int lengthOfLastWordV2(string s) {
  int n = s.size(), cnt = 0, flag = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == ' ' && flag)
      break;
    if (s[i] != ' ') {
      flag = 1;
      cnt++;
    }
  }
  return cnt;
}

int main() {
  string s1 = "Hello World";
  auto ans = lengthOfLastWordV1(s1);
  cout << ans << endl;
  return 0;
}