/**
There are n students in a class numbered from 0 to n - 1. The teacher will give
each student a problem starting with the student number 0, then the student
number 1, and so on until the teacher reaches the student number n - 1. After
that, the teacher will restart the process, starting with the student number 0
again.

You are given a 0-indexed integer array chalk and an integer k. There are
initially k pieces of chalk. When the student number i is given a problem to
solve, they will use chalk[i] pieces of chalk to solve that problem. However, if
the current number of chalk pieces is strictly less than chalk[i], then the
student number i will be asked to replace the chalk.

Return the index of the student that will replace the chalk pieces.



Example 1:

Input: chalk = [5,1,5], k = 22
Output: 0
Explanation: The students go in turns as follows:
- Student number 0 uses 5 chalk, so k = 17.
- Student number 1 uses 1 chalk, so k = 16.
- Student number 2 uses 5 chalk, so k = 11.
- Student number 0 uses 5 chalk, so k = 6.
- Student number 1 uses 1 chalk, so k = 5.
- Student number 2 uses 5 chalk, so k = 0.
Student number 0 does not have enough chalk, so they will have to replace it.
Example 2:

Input: chalk = [3,4,1,2], k = 25
Output: 1
Explanation: The students go in turns as follows:
- Student number 0 uses 3 chalk so k = 22.
- Student number 1 uses 4 chalk so k = 18.
- Student number 2 uses 1 chalk so k = 17.
- Student number 3 uses 2 chalk so k = 15.
- Student number 0 uses 3 chalk so k = 12.
- Student number 1 uses 4 chalk so k = 8.
- Student number 2 uses 1 chalk so k = 7.
- Student number 3 uses 2 chalk so k = 5.
- Student number 0 uses 3 chalk so k = 2.
Student number 1 does not have enough chalk, so they will have to replace it.


Constraints:

chalk.length == n
1 <= n <= 105
1 <= chalk[i] <= 105
1 <= k <= 109

source from: leetcode 1894.
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

int chalkReplacer(vector<int>& chalk, int k) {
  int B = chalk.size();
  auto Bn = std::accumulate(chalk.begin(), chalk.end(), 0LL);
  k %= Bn;
  for (int i = 0; i < chalk.size(); ++i) {
    if (chalk[i] > k) {
      return i;
    }
    k -= chalk[i];
  }
  return -1;
}

// would cause TLE
int chalkReplacerV1(vector<int>& chalk, int k) {
  int B = chalk.size();
  int b = 0;
  while (k >= 0) {
    if (k < chalk[b])
      return b;
    k -= chalk[b];
    b++;
    if (b == B)
      b = 0;
  }
  return b;
}

int main() {
  auto chalk1 = parse_vector("[5,1,5]");
  auto chalk2 = parse_vector("[3,4,1,2]");
  auto chalk3 = parse_vector("[3,22,9,28,48,40,47,5,19,4,9,7,11,48]");

  print_res(chalkReplacer, chalk1, 22);
  print_res(chalkReplacer, chalk2, 25);
  print_res(chalkReplacer, chalk3, 953);
  return 0;
}
