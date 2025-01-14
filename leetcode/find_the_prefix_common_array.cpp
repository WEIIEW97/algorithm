/**
You are given two 0-indexed integer permutations A and B of length n.

A prefix common array of A and B is an array C such that C[i] is equal to the
count of numbers that are present at or before the index i in both A and B.

Return the prefix common array of A and B.

A sequence of n integers is called a permutation if it contains all integers
from 1 to n exactly once.



Example 1:

Input: A = [1,3,2,4], B = [3,1,2,4]
Output: [0,2,3,4]
Explanation: At i = 0: no number is common, so C[0] = 0.
At i = 1: 1 and 3 are common in A and B, so C[1] = 2.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
At i = 3: 1, 2, 3, and 4 are common in A and B, so C[3] = 4.
Example 2:

Input: A = [2,3,1], B = [3,1,2]
Output: [0,1,3]
Explanation: At i = 0: no number is common, so C[0] = 0.
At i = 1: only 3 is common in A and B, so C[1] = 1.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.


Constraints:

1 <= A.length == B.length == n <= 50
1 <= A[i], B[i] <= n
It is guaranteed that A and B are both a permutation of n integers.

source from: leetcode 2657.
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

vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
  int n = A.size();
  vector<int> memo(n, 0);
  vector<int> C(n, 0);
  int prev_sum = 0;
  for (int i = 0; i < n; i++) {
    if (A[i] == B[i]) {
      prev_sum++;
    } else {
      int seen_a = memo[A[i] - 1];
      int seen_b = memo[B[i] - 1];
      prev_sum += (seen_a ? 1 : 0) + (seen_b ? 1 : 0);
    }
    memo[A[i] - 1]++;
    memo[B[i] - 1]++;
    C[i] = prev_sum;
  }
  return C;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // Your code here

  vector<int> A1, B1, A2, B2;
  A1 = parse_vector("[1,4,5,2,3]"), B1 = parse_vector("[3,5,2,4,1]");
  A2 = parse_vector("[2,3,1]"), B2 = parse_vector("[3,1,2]");

  print_res(findThePrefixCommonArray, A1, B1);
  print_res(findThePrefixCommonArray, A2, B2);

  return 0;
}
