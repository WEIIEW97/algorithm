/**
Given the head of a linked list, remove the nth node from the end of the list
and return its head.



Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]


Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

source from: leetcode 19.
*/

#include "algobase.h"
#include "node.h"
using namespace std;
ListNode* removeNthFromEnd(ListNode* head, int n) {
  
}

int main() {
  vector<int> root1 = {1, 2, 3, 4, 5};
  vector<int> root2 = {1};
  vector<int> root3 = {1, 2};

  auto node1 = build_list(root1);
  auto node2 = build_list(root2);
  auto node3 = build_list(root3);

  ListNode* res1 = removeNthFromEnd(node1, 2);
  print_list(res1);
  ListNode* res2 = removeNthFromEnd(node2, 1);
  print_list(res2);
  ListNode* res3 = removeNthFromEnd(node3, 1);
  print_list(res3);

  delete_list(node3);
  delete_list(node2);
  delete_list(node1);
  return 0;
}
