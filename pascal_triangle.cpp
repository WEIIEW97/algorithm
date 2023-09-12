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
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> r(numRows);

    for (int i = 0; i < numRows; i++) {
        r[i].resize(i+1);
        r[i][0] = r[i][i] = 1;

        for (int j = 1; j < i; j++) {
            r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }
    }
    return r;
}

int main() {
    auto res = generate(30);
    for (auto & re : res) {
        for (int j : re) {
            cout << j;
        }
        cout << endl;
    }
    return 0;
}