/**
You are given a string s of even length. Split this string into two halves
of equal lengths, and let a be the first half and b be the second half.
Two strings are alike if they have the same number of vowels ('a', 'e',
'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase
and lowercase letters. Return true if a and b are alike. Otherwise,
return false.

Example 1:
Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore,
they are alike.

Example 2:
Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2.
Therefore, they are not alike. Notice that the vowel o is counted twice.

Constraints:
2 <= s.length <= 1000
s.length is even.
s consists of uppercase and lowercase letters.

source from: leetcode 1704
*/

#include "algobase.h"
using namespace std;

bool halvesAreAlike(std::string s) {
  const int half_len = s.size() / 2;

  auto is_vowel = [](char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
  };

  int vowel_count_first_half = 0, vowel_count_second_half = 0;
  for (int i = 0; i < half_len; i++) {
    if (is_vowel(s[i]))
      vowel_count_first_half++;
    if (is_vowel(s[i + half_len]))
      vowel_count_second_half++;
  }

  return vowel_count_first_half == vowel_count_second_half;
}

int main() {
  string s1 = "book";
  string s2 = "textbook";
  cout << halvesAreAlike(s1) << endl;
  cout << halvesAreAlike(s2) << endl;
  return 0;
}
