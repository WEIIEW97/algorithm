/**
You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure 
and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin 
with "JFK". If there are multiple valid itineraries, you should return the itinerary that 
has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets 
once and only once.

Example 1:

Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
Output: ["JFK","MUC","LHR","SFO","SJC"]

Example 2:

Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but 
it is larger in lexical order.
 

Constraints:

1 <= tickets.length <= 300
tickets[i].length == 2
from i.length == 3
to i.length == 3
from i and to i consist of uppercase English letters.
from i != toi

source: leetcode 332
 */

#include "algobase.h"
#include "tictoc.h"
using namespace std;

// using DFS + priority_queue
class Solution1 {
  public:
    void build_graph(vector<vector<string>>& tickets) {
        for(auto& edge : tickets) {
            string from=edge[0], to=edge[1];
            fly[from].push(to);
        }
    }

    void dfs(string from) {
        while(!fly[from].empty()) {
            string to = fly[from].top();
            fly[from].pop();
            dfs(to);
        }
        ans.push_back(from);
    }

    vector<string> findItinerary(vector<vector<string>>& tickest) {
        build_graph(tickest);
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }

  public:
    vector<string> ans;
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> fly;

};

// use DFS + deque
class Solution2 {
  public:
    void build_graph(vector<vector<string>>& tickets) {
        for(auto& edge : tickets) {
            string from=edge[0], to=edge[1];
            fly[from].push(to);
        }
    }

    void dfs(string from) {
        while(!fly[from].empty()) {
            string to = fly[from].top();
            fly[from].pop();
            dfs(to);
        }
        ans.push_front(from);
    }

    vector<string> findItinerary(vector<vector<string>>& tickest) {
        build_graph(tickest);
        dfs("JFK");
        return vector<string>(ans.begin(), ans.end());
    }

  public:
    deque<string> ans;
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> fly;
    // unordered_map<string, int> indeg, outdeg;
};

// DFS extremely fast version
class Solution3 {
  public:
    void dfs(string s) {
        auto &x=map[s];
        while(!x.empty())
        {
            string to=x.top();
            x.pop();
            dfs(to);
        }
        ans.push_back(s);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &x:tickets)
            map[x[0]].push(x[1]);
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
  public:
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> map; 
    vector<string> ans;
};

int main() {
    // vector<vector<string>> tickets = {
    //     {"MUC","LHR"},
    //     {"JFK","MUC"},
    //     {"SFO","SJC"},
    //     {"LHR","SFO"},
    // };
    vector<vector<string>> tickets = {
        {"JFK","SFO"},
        {"JFK","ATL"},
        {"SFO","ATL"},
        {"ATL","JFK"},
        {"ATL","SFO"},
    };
    auto solver1 = Solution1();
    TIC(res1)
    auto res1 = solver1.findItinerary(tickets);
    TOC(res1)
    PRINT_VECTOR_1D(res1);

    auto solver2 = Solution2();
    TIC(res2)
    auto res2 = solver2.findItinerary(tickets);
    TOC(res2)
    PRINT_VECTOR_1D(res2);

    auto solver3 = Solution3();
    TIC(res3)
    auto res3 = solver3.findItinerary(tickets);
    TOC(res3)
    PRINT_VECTOR_1D(res3);
    return 0;
}