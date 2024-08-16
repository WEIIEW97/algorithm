/**
You are given m arrays, where each array is sorted in ascending order.

You can pick up two integers from two different arrays (each array picks one)
and calculate the distance. We define the distance between two integers a and b
to be their absolute difference |a - b|.

Return the maximum distance.



Example 1:

Input: arrays = [[1,2,3],[4,5],[1,2,3]]
Output: 4
Explanation: One way to reach the maximum distance 4 is to pick 1 in the first
or third array and pick 5 in the second array. Example 2:

Input: arrays = [[1],[1]]
Output: 0


Constraints:

m == arrays.length
2 <= m <= 105
1 <= arrays[i].length <= 500
-104 <= arrays[i][j] <= 104
arrays[i] is sorted in ascending order.
There will be at most 105 integers in all the arrays.

source from: leetcode 624.
*/

#include "algobase.h"
using namespace std;

int maxDistancev1(vector<vector<int>>& arrays) {
  vector<int> minvs, maxvs;
  for (const auto& arr : arrays) {
    auto [minv, maxv] = minmax_element(arr.begin(), arr.end());
    minvs.push_back(*minv);
    maxvs.push_back(*maxv);
  }
  auto maxv = max_element(maxvs.begin(), maxvs.end());
  auto maxv_id = distance(maxvs.begin(), maxv);
  auto minv = min_element(minvs.begin(), minvs.end());
  auto minv_id = distance(minvs.begin(), minv);
  int result = 0;

  if (maxv_id != minv_id) {
    result = *maxv - *minv;
  } else {
    int second_min = std::numeric_limits<int>::max();
    for (size_t i = 0; i < minvs.size(); ++i) {
      if (i != minv_id && minvs[i] < second_min) {
        second_min = minvs[i];
      }
    }
    int result1 = *maxv - second_min;

    int second_max = std::numeric_limits<int>::min();
    for (size_t i = 0; i < maxvs.size(); ++i) {
      if (i != maxv_id && maxvs[i] > second_max) {
        second_max = maxvs[i];
      }
    }
    int result2 = second_max - *minv;

    result = result1 >= result2 ? result1 : result2;
  }

  return result;
}

int maxDistance(std::vector<std::vector<int>>& arrays) {
  int maxDist = 0;
  int minVal = arrays[0].front(); // Smallest element of the first array
  int maxVal = arrays[0].back();  // Largest element of the first array

  // Start from the second array
  for (int i = 1; i < arrays.size(); i++) {
    // Current array extremes
    int curMin = arrays[i].front();
    int curMax = arrays[i].back();

    // Calculate potential max distances using the current array extremes
    // and the global extremes (excluding the current array)
    int dist1 = std::abs(curMax - minVal);
    int dist2 = std::abs(maxVal - curMin);

    // Update maxDist if any of these new distances are greater
    maxDist = std::max(maxDist, dist1);
    maxDist = std::max(maxDist, dist2);

    // Update global min and max values
    minVal = std::min(minVal, curMin);
    maxVal = std::max(maxVal, curMax);
  }

  return maxDist;
}

int main() {
  vector<vector<int>> array1, array2, array3, array4;
  array1 = {{1, 2, 3}, {4, 5}, {1, 2, 3}};
  array2 = {{1}, {1}};
  array3 = {{1, 4}, {0, 5}};
  array4 = {{1, 5}, {3, 4}};

  cout << maxDistance(array1) << endl;
  cout << maxDistance(array2) << endl;
  cout << maxDistance(array3) << endl;
  cout << maxDistance(array4) << endl;
  return 0;
}
