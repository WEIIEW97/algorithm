/*
 * Copyright (c) 2022-2023, William Wei. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * Description
Given an integer array nums of length n where all the integers of nums are in
the range [1, n] and each integer appears once or twice, return an array of all
the integers that appears twice. You must write an algorithm that runs in O(n)
time and uses only constant extra space.

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]
Example 3:

Input: nums = [1]
Output: []


Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
Each element in nums appears once or twice.

leetcode 442. Find All Duplicates in an Array
*/

// solution 1, using unordered_map
vector<int> findDuplicates(vector<int>& nums) {
  unordered_map<int, int> map;
  vector<int> d;
  for (auto& v : nums) {
    map[v]++;
  }

  for (auto& m : map) {
    if (m.second == 2) {
      d.push_back(m.first);
    }
  }
  return d;
}

// solution 2
vector<int> findDuplicatesV1(vector<int>& nums) {
  vector<int> d;
  int max = *max_element(nums.begin(), nums.end());
  vector<bool> seen(max + 1, false);

  for (auto& v : nums) {
    if (seen[v]) {
      d.push_back(v);
    } else {
      seen[v] = true;
    }
  }
  return d;
}

// solution 3
vector<int> findDuplicatesV2(vector<int>& nums) {
  vector<int> d;
  sort(nums.begin(), nums.end());
  for (auto i = 0; i < nums.size(); i++) {
    if (nums[i - 1] == nums[i]) {
      d.push_back(nums[i]);
    }
  }
  return d;
}
