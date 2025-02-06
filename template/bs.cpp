// binary search template
// array should be sorted

#include "algobase.h"
using namespace std;

bool exist(vector<int>& arr, int num) {
  int l = 0, r = arr.size() - 1, m;
  while (l <= r) {
    m = l + (r - l) / 2;
    if (arr[m] == num)
      return true;
    else if (arr[m] > num)
      r = m - 1;
    else
      l = m + 1;
  }
  return false;
}

// find the leftmost index of sorted arr[m]>=num
int find_left(vector<int>& arr, int num) {
  int l = 0, r = arr.size() - 1, m;
  int ans = -1;
  while (l <= r) {
    m = l + (r - l) / 2;
    if (arr[m] >= m) {
      ans = m;
      r = m - 1;
    } else
      l = m + 1;
  }
  return ans;
}

// find the rightmost index of sorted arr[m]<=num
int find_right(vector<int>& arr, int num) {
  int l = 0, r = arr.size() - 1, m;
  int ans = -1;
  while (l <= r) {
    m = l + (r - l) / 2;
    if (arr[m] <= m) {
      ans = m;
      l = m + 1;
    } else
      r = m - 1;
  }
  return ans;
}