/**
Given an array of strings strs, group the anagrams together. You can return the
answer in any order. An Anagram is a word or phrase formed by rearranging the
letters of a different word or phrase, typically using all the original letters
exactly once.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]


Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.

source: leetcode 49
*/

#include "algobase.h"
using namespace std;

// it is theorectically correst but will consume lots of time
vector<vector<string>> groupAnagrams(vector<string>& strs) {
  vector<vector<string>> group;
  vector<string> strsc = strs;
  unordered_map<string, int> book;
  for (auto& str : strsc) {
    sort(str.begin(), str.end());
    book[str]++;
  }

  for (auto& key : book) {
    vector<string> t;
    for (auto& str : strs) {
      string s = str;
      sort(s.begin(), s.end());
      if (s == key.first) {
        t.push_back(str);
      }
    }
    group.push_back(t);
  }

  return group;
}

// fasrer version. use sorted string as key
vector<vector<string>> groupAnagramsV2(vector<string>& strs) {
  unordered_map<string, vector<string>> mp;
  for (auto& s : strs) {
    string t = s;
    sort(t.begin(), t.end());
    mp[t].emplace_back(s);
  }
  vector<vector<string>> anagrams;
  for (auto& kv : mp) {
    anagrams.emplace_back(kv.second);
  }
  return anagrams;
}

int main() {
  vector<string> v = {"eat", "tea", "tan", "ate", "nat", "bat"};
  //   vector<string> v = {"a"};
  auto res = groupAnagramsV2(v);

  PRINT_VECTOR_2D(res);
  return 0;
}