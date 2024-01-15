/**
You are given an integer array matches where matches{i} = {winneri, loseri}
indicates that the player winneri defeated player loseri in a match.

Return a list answer of size 2 where:

answer{0} is a list of all players that have not lost any matches.
answer{1} is a list of all players that have lost exactly one match.
The values in the two lists should be returned in increasing order.

Note:

You should only consider the players that have played at least one match.
The testcases will be generated such that no two matches will have the same
outcome.


Example 1:
Input: matches = {{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}}
Output: {{1,2,10},{4,5,7,8}}
Explanation:
Players 1, 2, and 10 have not lost any matches.
Players 4, 5, 7, and 8 each have lost one match.
Players 3, 6, and 9 each have lost two matches.
Thus, answer{0} = {1,2,10} and answer{1} = {4,5,7,8}.

Example 2:
Input: matches = {{2,3},{1,3},{5,4},{6,4}}
Output: {{1,2,5,6},{}}
Explanation:
Players 1, 2, 5, and 6 have not lost any matches.
Players 3 and 4 each have lost two matches.
Thus, answer{0} = {1,2,5,6} and answer{1} = {}.

Constraints:

1 <= matches.length <= 105
matches{i}.length == 2
1 <= winneri, loseri <= 105
winneri != loseri
All matches{i} are unique.

source from: leetcode 2225.
*/

#include "algobase.h"
using namespace std;

vector<vector<int>> findWinners1(vector<vector<int>>& matches) {
  unordered_map<int, int> loses;
  unordered_map<int, int> wins;
  set<int> ids;
  set<int> loses_set;

  for (auto& pair : matches) {
    loses[pair[1]]++;
    wins[pair[0]]++;
    ids.insert(pair[0]);
    ids.insert(pair[1]);
    loses_set.insert(pair[1]);
  }

  set<int> diff;
  set_difference(ids.begin(), ids.end(), loses_set.begin(), loses_set.end(),
                 inserter(diff, diff.begin()));

  vector<int> lose1;
  vector<int> allwin(diff.begin(), diff.end());
  for (auto& p : loses) {
    if (p.second == 1)
      lose1.push_back(p.first);
  }
  sort(allwin.begin(), allwin.end());
  sort(lose1.begin(), lose1.end());
  return {allwin, lose1};
}

vector<vector<int>> findWinners2(vector<vector<int>>& matches) {
  int loss[100001];
  memset(loss, -1, sizeof(loss));
  for (auto& p : matches) {
    int &x = p[0], &y = p[1];
    loss[x] = (loss[x] == -1) ? 0 : loss[x];
    loss[y] = (loss[y] <= 0) ? 1 : loss[y] + 1;
  }
  vector<vector<int>> ans(2);
  for (int i = 1; i <= 100000; i++) {
    if (loss[i] == 0)
      ans[0].push_back(i);
    else if (loss[i] == 1)
      ans[1].push_back(i);
  }
  return ans;
}

int main() {
  vector<vector<int>> matches1 = {{1, 3}, {2, 3}, {3, 6}, {5, 6},  {5, 7},
                                  {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}};
  vector<vector<int>> matches2 = {{2, 3}, {1, 3}, {5, 4}, {6, 4}};

  PRINT_VECTOR_2D(findWinners2(matches1));
  PRINT_VECTOR_2D(findWinners2(matches2));
  return 0;
}
