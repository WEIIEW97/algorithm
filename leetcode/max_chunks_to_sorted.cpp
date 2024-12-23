/**
You are given an integer array arr of length n that represents a permutation of
the integers in the range [0, n - 1].

We split arr into some number of chunks (i.e., partitions), and individually
sort each chunk. After concatenating them, the result should equal the sorted
array.

Return the largest number of chunks we can make to sort the array.



Example 1:

Input: arr = [4,3,2,1,0]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2],
which isn't sorted. Example 2:

Input: arr = [1,0,2,3,4]
Output: 4
Explanation:
We can split into two chunks, such as [1, 0], [2, 3, 4].
However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks
possible.


Constraints:

n == arr.length
1 <= n <= 10
0 <= arr[i] < n
All the elements of arr are unique.

source from: leetcode 769.
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

int maxChunksToSorted(vector<int>& arr) {
  int n = arr.size();
  int cnt = 0, diff = 0;
  for (int i = 0; i < n; i++) {
    diff += arr[i] - i;
    cnt += (diff == 0);
  }

  return cnt;
}

int main() {
  vector<int> arr1, arr2;
  arr1 = parse_vector("[4,3,2,1,0]");
  arr2 = parse_vector("[1,0,2,3,4]");

  print_res(maxChunksToSorted, arr1);
  print_res(maxChunksToSorted, arr2);

  return 0;
}
