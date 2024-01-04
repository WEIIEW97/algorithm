/*
 * Copyright (c) 2022-${year}, William Wei. All rights reserved.
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

#include <iostream>
#include <string>
using namespace std;

/* Description:
 * Given two strings s and goal, return true if and only if s can become goal
after some number of shifts on s.
A shift on s consists of moving the leftmost character of s to the rightmost position.
For example, if s = "abcde", then it will be "bcdea" after one shift.


Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false


Constraints:

1 <= s.length, goal.length <= 100
s and goal consist of lowercase English letters.

leetcode: 796 rotate string
*/

// solution 1
bool rotateString(string s, string goal) {
    int n = s.size();
    if (n != goal.size()) return false;
    for (auto i = 0; i < n; i++) {
        s = s.substr(1, n - 1) + s.substr(0, 1);
        if (s == goal) {
            return true;
        }
    }
    return false;
}

// solution 2
bool rotateStringV2(string s, string goal) {
    return (s + s).find(goal) && (s.size() == goal.size());
}