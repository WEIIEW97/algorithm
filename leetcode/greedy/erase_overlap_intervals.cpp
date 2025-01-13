/**
Given an array of intervals intervals where intervals[i] = [starti, endi],
return the minimum number of intervals you need to remove to make the rest of
the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For
example, [1, 2] and [2, 3] are non-overlapping.



Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are
non-overlapping. Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals
non-overlapping. Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already
non-overlapping.


Constraints:

1 <= intervals.length <= 105
intervals[i].length == 2
-5 * 104 <= starti < endi <= 5 * 104

source from: leetcode 435.
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

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
  sort(intervals.begin(), intervals.end(),
       [&](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
  int rm = 0, prev_end = intervals[0][1];
  int n = intervals.size();
  for (int i = 1; i < n; i++) {
    if (intervals[i][0] < prev_end)
      rm++;
    else
      prev_end = intervals[i][1];
  }
  return rm;
}

int main() {
  vector<vector<int>> in1, in2, in3;
  in1 = parse_matrix("[[1,2],[2,3],[3,4],[1,3]]");
  in2 = parse_matrix("[[1,2],[1,2],[1,2]]");
  in3 = parse_matrix("[[1,100],[11,22],[1,11],[2,12]]");

  print_res(eraseOverlapIntervals, in1);
  print_res(eraseOverlapIntervals, in2);
  print_res(eraseOverlapIntervals, in3);

  return 0;
}
