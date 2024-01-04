/**
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a
single digit. Add the two numbers and return the sum as a linked list. You may
assume the two numbers do not contain any leading zero, except the number 0
itself. Example 1: Input: l1 = [2,4,3], l2 = [5,6,4] Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

Constraints:

The number of nodes in each linked list is in the range [1, 100]
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading
zeros.

source from leetcode: 2. Add Two Numbers
*/

#include "algobase.h"
using namespace std;

void push(ListNode **head_ref, int new_key) {
  ListNode *new_node = new ListNode();
  new_node->val = new_key;
  new_node->next = *head_ref;
  *head_ref = new_node;
}

void pb(ListNode *&head, int value) {
  // Step 1: Create the new node
  ListNode *new_node = new ListNode();
  new_node->val = value;
  new_node->next = nullptr;

  if (!head) {
    head = new_node;
    return;
  }

  ListNode *temp = head;
  while (temp->next) {
    temp = temp->next;
  }

  temp->next = new_node;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  int i1 = 0, i2 = 0, s;
  int iter = 0;
  while (l1 != nullptr) {
    i1 += l1->val * pow(10, iter);
    l1 = l1->next;
    iter++;
  }
  iter = 0;
  while (l2 != nullptr) {
    i2 += l2->val * pow(10, iter);
    l2 = l2->next;
    iter++;
  }
  ListNode *res(0);
  s = i1 + i2;
  if (s == 0) {
    pb(res, 0);
    return res;
  }
  while (s) {
    int r = s % 10;
    pb(res, r);
    s = s / 10;
  }
  return res;
}

int main() {
  ListNode *l1 = nullptr;
  push(&l1, 0);
  //   push(&l1, 4);
  //   push(&l1, 2);

  ListNode *l2 = nullptr;
  push(&l2, 0);
  //   push(&l2, 6);
  //   push(&l2, 5);

  ListNode *sum;
  sum = addTwoNumbers(l1, l2);

  return 0;
}