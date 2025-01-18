/**
Given the head of a linked list, return the node where the cycle begins. If
there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be
reached again by continuously following the next pointer. Internally, pos is
used to denote the index of the node that tail's next pointer is connected to
(0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a
parameter.

Do not modify the linked list.



Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the
second node. Example 2:


Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the
first node. Example 3:


Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.


Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.

source from: leetcode 142.
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

ListNode* detectCycle(ListNode* head) {
  ListNode *slow = head, *fast = head;
  bool is_first_cycle = true;
  while (fast != slow || is_first_cycle) {
    if (fast == nullptr || fast->next == nullptr)
      return nullptr;
    fast = fast->next->next;
    slow = slow->next;
    is_first_cycle = false;
  }
  fast = head;
  while (fast != slow) {
    slow = slow->next;
    fast = fast->next;
  }
  return fast;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // Your code here
  ListNode* head1 = build_list(vector<int>{3, 2, 0, -4});
  ListNode* head2 = build_list(vector<int>{1, 2});
  ListNode* head3 = build_list(vector<int>{1});

  print_list(detectCycle(head1));
  print_list(detectCycle(head2));
  print_list(detectCycle(head3));

  delete_list(head3);
  delete_list(head2);
  delete_list(head1);

  return 0;
}
