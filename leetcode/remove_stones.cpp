/**
On a 2D plane, we place n stones at some integer coordinate points. Each
coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as
another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the
location of the ith stone, return the largest possible number of stones that can
be removed.



Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another
stone still on the plane. Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column
with another stone still on the plane. Example 3:

Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.


Constraints:

1 <= stones.length <= 1000
0 <= xi, yi <= 104
No two stones are at the same coordinate point.

source from: leetcode 947.
*/

#include "algobase.h"
using namespace std;

// Linux-specific optimizations with GCC or Clang
#if defined(__linux__)
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC optimize("Ofast")
static auto _linux_optimize = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();
#endif
#endif

// macOS-specific optimizations with Clang
#if defined(__APPLE__) && defined(__MACH__)
#if defined(__clang__)
#pragma clang optimize on
static auto _macos_optimize = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();
#endif
#endif

// Windows-specific optimizations with MSVC
#if defined(_WIN32)
#if defined(_MSC_VER)
#include <cstdlib>
#pragma optimize("t", on)
static auto _windows_optimize = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();
#endif
#endif

unordered_map<int, int> parent_;
unordered_map<int, int> rank_;

int find(int x) {
  if (parent_.find(x) == parent_.end()) {
    parent_[x] = x;
    rank_[x] = 0;
  }

  if (parent_[x] != x) {
    parent_[x] = find(parent_[x]);
  }
  return parent_[x];
}

void unionSet(int x, int y) {
  int root_x = find(x);
  int root_y = find(y);

  if (root_x != root_y) {
    if (rank_[root_x] > rank_[root_y])
      parent_[root_y] = root_x;
    else if (rank_[root_x] < rank_[root_y])
      parent_[root_x] = root_y;
    else {
      parent_[root_y] = root_x;
      rank_[root_x]++;
    }
  }
}

int removeStones(vector<vector<int>>& stones) {
  int n = stones.size();

  for (const auto& stone : stones) {
    unionSet(stone[0] + 10001, stone[1]);
  }

  unordered_map<int, int> root_cnt;
  for (const auto& stone : stones) {
    int root = find(stone[0] + 10001);
    root_cnt[root]++;
  }

  return n - root_cnt.size();
}

vector<int> row[10001], col[10001];
bitset<1001> viz; // bitset is good

void dfs(int idx, vector<vector<int>>& stones) {
  const int i = stones[idx][0], j = stones[idx][1];
  viz[idx] = 1;
  for (auto k : row[i]) {
    if (!viz[k])
      dfs(k, stones);
  }
  for (auto k : col[j]) {
    if (!viz[k])
      dfs(k, stones);
  }
}

int removeStonesV2(vector<vector<int>>& stones) {
  const int n = stones.size();

  for (int idx = 0; idx < n; idx++) {
    const int i = stones[idx][0], j = stones[idx][1];
    row[i].push_back(idx);
    col[j].push_back(idx);
  }

  int component = 0;
  for (int idx = 0; idx < n; idx++) {
    const int i = stones[idx][0], j = stones[idx][1];
    if (!viz[idx]) {
      dfs(idx, stones);
      component++;
    }
  }
  return n - component;
}

int main() {
  vector<vector<int>> stones1, stones2, stones3;
  stones1 = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
  stones2 = {{0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}};
  stones3 = {{0, 0}};

  print_res(removeStones, stones1);
  print_res(removeStones, stones2);
  print_res(removeStones, stones3);

  return 0;
}
