/**
We build a table of n rows (1-indexed). We start by writing 0 in the 1st row.
Now in every subsequent row, we look at the previous row and replace each
occurrence of 0 with 01, and each occurrence of 1 with 10. For example, for n =
3, the 1st row is 0, the 2nd row is 01, and the 3rd row is 0110. Given two
integer n and k, return the kth (1-indexed) symbol in the nth row of a table of
n rows.

Example 1:
Input: n = 1, k = 1
Output: 0
Explanation: row 1: 0

Example 2:
Input: n = 2, k = 1
Output: 0
Explanation:
row 1: 0
row 2: 01

Example 3:
Input: n = 2, k = 2
Output: 1
Explanation:
row 1: 0
row 2: 01

Constraints:
1 <= n <= 30
1 <= k <= 2n - 1

source from: leetcode 779
*/

#include "algobase.h"
#ifdef _MSC_VER
#include <intrin.h>
#define __builtin_popcount __popcnt
#define __builtin_clz      _lzcnt_u32
#endif
using namespace std;

int kthGrammarV1(int n, int k) {
  if (k == 1)
    return 0; // Base case

  int bL = 31 - __builtin_clz(k); // Calculate log2(k)
  if (k == 1 << bL)
    return bL & 1;
  // invert the symbol
  else
    return 1 - kthGrammarV1(n, k - (1 << bL));
}

int kthGrammarV2(int n, int k) { return __builtin_popcount(k - 1) & 1; }

int main() {
  cout << kthGrammarV1(30, 434991989) << endl;
  return 0;
}
