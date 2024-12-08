/**
You are given a 0-indexed 2D integer array of events where events[i] =
[startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at
endTimei, and if you attend this event, you will receive a value of valuei. You
can choose at most two non-overlapping events to attend such that the sum of
their values is maximized.

Return this maximum sum.

Note that the start time and end time is inclusive: that is, you cannot attend
two events where one of them starts and the other ends at the same time. More
specifically, if you attend an event with end time t, the next event must start
at or after t + 1.



Example 1:


Input: events = [[1,3,2],[4,5,2],[2,4,3]]
Output: 4
Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.
Example 2:

Example 1 Diagram
Input: events = [[1,3,2],[4,5,2],[1,5,5]]
Output: 5
Explanation: Choose event 2 for a sum of 5.
Example 3:


Input: events = [[1,5,3],[1,5,1],[6,6,5]]
Output: 8
Explanation: Choose events 0 and 2 for a sum of 3 + 5 = 8.


Constraints:

2 <= events.length <= 105
events[i].length == 3
1 <= startTimei <= endTimei <= 109
1 <= valuei <= 106

source from: leetcode 2054.
*/

#include "algobase.h"
using namespace std;

// Linux-specific optimizations with GCC or Clang
#if defined(__linux__)
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC optimize("Ofast")
static auto __optimize = []() {
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
static auto __optimize = []() {
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
static auto __optimize = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();
#endif
#endif

int maxTwoEvents(vector<vector<int>>& events) {
  int n = events.size();
  vector<uint64_t> time(n * 2);
  for (int i = 0; i < n; i++) {
    int s = events[i][0], e = events[i][1], v = events[i][2];
    time[2 * i] = ((uint64_t)s << 21) + v; // packing
    time[2 * i + 1] = ((uint64_t)e << 21) + (1 << 20) + v; //packing
  }
  sort(time.begin(), time.end());
  int ans = 0, maxV = 0, n2 = n * 2;
  for (auto info : time) {
    bool is_end = (info >> 20) & 1; //extract isEnd from info
    int v = info & ((1 << 20) - 1); //extract isEnd from info
    if (is_end)
      maxV = max(maxV, v);
    else
      ans = max(ans, maxV + v);
  }

  return ans;
}

using info = tuple<int, bool, int>;
int maxTwoEventsV1(vector<vector<int>>& events) {
  const int n = events.size();
  vector<info> time(n * 2);
  for (int i = 0; i < n; i++) {
    int s = events[i][0], e = events[i][1], v = events[i][2];
    time[2 * i] = {s, 0, v};
    time[2 * i + 1] = {e, 1, v};
  }
  sort(time.begin(), time.end());
  int ans = 0, maxV = 0, n2 = n * 2;
  for (auto& [t, isEnd, v] : time) {
    if (isEnd)
      maxV = max(maxV, v);
    else
      ans = max(ans, maxV + v);
  }
  return ans;
}

int main() {
  vector<vector<int>> events1, events2, events3;
  events1 = parse_matrix("[[1,3,2],[4,5,2],[2,4,3]]");
  events2 = parse_matrix("[[1,3,2],[4,5,2],[1,5,5]]");
  events3 = parse_matrix("[[1,5,3],[1,5,1],[6,6,5]]");

  cout << maxTwoEvents(events1) << endl;
  cout << maxTwoEvents(events2) << endl;
  cout << maxTwoEvents(events3) << endl;
}
