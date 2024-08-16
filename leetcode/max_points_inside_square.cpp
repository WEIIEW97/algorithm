/**
You are given a 2D array points and a string s where, points[i] represents the
coordinates of point i, and s[i] represents the tag of point i.

A valid square is a square centered at the origin (0, 0), has edges parallel to
the axes, and does not contain two points with the same tag.

Return the maximum number of points contained in a valid square.

Note:

A point is considered to be inside the square if it lies on or within the
square's boundaries. The side length of the square can be zero.


Example 1:



Input: points = [[2,2],[-1,-2],[-4,4],[-3,1],[3,-3]], s = "abdca"

Output: 2

Explanation:

The square of side length 4 covers two points points[0] and points[1].

Example 2:



Input: points = [[1,1],[-2,-2],[-2,2]], s = "abb"

Output: 1

Explanation:

The square of side length 2 covers one point, which is points[0].

Example 3:

Input: points = [[1,1],[-1,-1],[2,-2]], s = "ccd"

Output: 0

Explanation:

It's impossible to make any valid squares centered at the origin such that it
covers only one point among points[0] and points[1].



Constraints:

1 <= s.length, points.length <= 105
points[i].length == 2
-109 <= points[i][0], points[i][1] <= 109
s.length == points.length
points consists of distinct coordinates.
s consists only of lowercase English letters.

source from: leetcode 3143.
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

int maxPointsInsideSquare(vector<vector<int>>& points, string s) {}

int main() {
  vector<vector<int>> points1, points2, points3;
  points1 = parse_matrix("[[2,2],[-1,-2],[-4,4],[-3,1],[3,-3]]");
  points2 = parse_matrix("[[1,1],[-2,-2],[-2,2]]");
  points3 = parse_matrix("[[1,1],[-1,-1],[2,-2]]");
  string tag1, tag2, tag3;
  tag1 = "abdca";
  tag2 = "abb";
  tag3 = "ccd";

  print_res(maxPointsInsideSquare, points1, tag1);
  print_res(maxPointsInsideSquare, points2, tag2);
  print_res(maxPointsInsideSquare, points3, tag3);

  return 0;
}
