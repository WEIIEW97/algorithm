/**
You are given an array of integers nums and the head of a linked list. Return
the head of the modified linked list after removing all nodes from the linked
list that have a value that exists in nums.



Example 1:

Input: nums = [1,2,3], head = [1,2,3,4,5]

Output: [4,5]

Explanation:



Remove the nodes with values 1, 2, and 3.

Example 2:

Input: nums = [1], head = [1,2,1,2,1,2]

Output: [2,2,2]

Explanation:



Remove the nodes with value 1.

Example 3:

Input: nums = [5], head = [1,2,3,4]

Output: [1,2,3,4]

Explanation:



No node has value 5.



Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
All elements in nums are unique.
The number of nodes in the given list is in the range [1, 105].
1 <= Node.val <= 105
The input is generated such that there is at least one node in the linked list
that has a value not present in nums.

source from: leetcode 3217.
*/

#include "algobase.h"
#include "node.h"
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

ListNode* modifiedList(vector<int>& nums, ListNode* head) {
  set<int> st(nums.begin(), nums.end());
  ListNode* fast = new ListNode(0);
  fast->next = head;
  ListNode* slow = fast;

  while (fast->next) {
    if (st.count(fast->next->val)) {
      auto d = fast->next;
      fast->next = fast->next->next;
      delete d;
    } else {
      fast = fast->next;
    }
  }

  return slow->next;
}

// ListNode* f(ListNode* head, set<int>& st) {
//   if (!head)
//     return NULL;
//   head->next = f(head->next, st);
//   if (st.count(head->val)) {
//     ListNode* next = head->next;
//     delete (head);
//     return next;
//   }
//   return head;
// }

// ListNode* modifiedList(vector<int>& nums, ListNode* head) {
//   set<int> st(nums.begin(), nums.end());
//   return f(head, st);
// }

int main() {
  auto nums1 = parse_vector("[1,2,3]");
  auto nums2 = parse_vector("[1]");
  auto nums3 = parse_vector("[5]");
  auto head1 = build_list(vector<int>({1, 2, 3, 4, 5}));
  auto head2 = build_list(vector<int>({1, 2, 1, 2, 1, 2}));
  auto head3 = build_list(vector<int>({1, 2, 3, 4}));

  print_list(modifiedList(nums1, head1));
  print_list(modifiedList(nums2, head2));
  print_list(modifiedList(nums3, head3));

  return 0;
}
