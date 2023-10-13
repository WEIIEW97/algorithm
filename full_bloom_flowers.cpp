/**
You are given a 0-indexed 2D integer array flowers, where flowers[i] = [starti,
endi] means the ith flower will be in full bloom from starti to endi
(inclusive). You are also given a 0-indexed integer array people of size n,
where people[i] is the time that the ith person will arrive to see the flowers.
Return an integer array answer of size n, where answer[i] is the number of
flowers that are in full bloom when the ith person arrives.

Example 1:
Input: flowers = [[1,6],[3,7],[9,12],[4,13]], people = [2,3,7,11]
Output: [1,2,2,2]
Explanation: The figure above shows the times when the flowers are in full bloom
and when the people arrive. For each person, we return the number of flowers in
full bloom during their arrival.

Example 2:
Input: flowers = [[1,10],[3,3]], people = [3,3,2]
Output: [2,2,1]
Explanation: The figure above shows the times when the flowers are in full bloom
and when the people arrive. For each person, we return the number of flowers in
full bloom during their arrival.

Constraints:
1 <= flowers.length <= 5 * 104
flowers[i].length == 2
1 <= starti <= endi <= 109
1 <= people.length <= 5 * 104
1 <= people[i] <= 10

source from:  leetcode 2251
*/

#include "algobase.h"
using namespace std;

#define ll long long

// very intuitive way using unordered_map, but will cause memory exceed limit
vector<int> fullBloomFlowersV1(vector<vector<int>>& flowers,
                               vector<int>& people) {
  unordered_map<int, int> m;
  for (auto& i : flowers) {
    for (int k = i[0]; k <= i[1]; k++) {
      m[k]++;
    }
  }

  vector<int> ans;
  for (int s = 0; s < people.size(); s++) {
    ans.push_back(m[people[s]]);
  }

  return ans;
}

// modified version of map, memeory friendly
vector<int> fullBloomFlowersV2(vector<vector<int>>& flowers,
                               vector<int>& people) {
  int n = people.size();
  vector<int> ans(n);
  map<int, int> mp;
  mp[0] = 0;
  for (int i = 0; i < flowers.size(); i++) {
    mp[flowers[i][0]]++;
    mp[flowers[i][1] + 1]--;
  }
  for (auto it = next(mp.begin()); it != mp.end(); it++) {
    it->second += prev(it)->second;
  }
  for (int i = 0; i < n; i++) {
    ans[i] = prev(mp.upper_bound(people[i]))->second;
  }
  return ans;
}

// using binary search
int startBloom(vector<int>& flowers, int person, int cnt) {
  ll l = 0, h = flowers.size() - 1;
  while (l <= h) {
    ll mid = (h + l) / 2;
    if (flowers[mid] <= person) {
      cnt = mid;
      l = mid + 1;
    } else {
      h = mid - 1;
    }
  }
  return cnt;
}

int endBloom(vector<int>& flowers, int person, int cnt) {
  ll l = 0, h = flowers.size() - 1;
  while (l <= h) {
    ll mid = (h + l) / 2;
    if (flowers[mid] < person) {
      l = mid = 1;
    } else {
      cnt = mid;
      h = mid - 1;
    }
  }
  return cnt;
}

vector<int> fullBloomFlowersV3(vector<vector<int>>& flowers,
                               vector<int>& people) {
  vector<int> start, end;
  for (auto& flower : flowers) {
    start.emplace_back(flower[0]);
    end.emplace_back(flower[1]);
  }

  sort(start.begin(), start.end());
  sort(end.begin(), end.end());
  vector<int> res;
  for (auto& p : people) {
    int s = startBloom(start, p, -1);
    int e = endBloom(end, p, -1);
    if (s != -1 && e != -1) {
      res.emplace_back(e - s + 1);
    } else {
      res.emplace_back(0);
    }
  }
  return res;
}

int main() {
  vector<vector<int>> flowers = {{1, 6}, {3, 7}, {9, 12}, {4, 13}};
  vector<int> people = {2, 3, 7, 11};

  auto ans = fullBloomFlowersV1(flowers, people);
  PRINT_VECTOR_1D(ans);
  return 0;
}