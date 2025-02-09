#include "algobase.h"
#include "node.h"

using namespace std;

ListNode* addTwoNumbers(ListNode* h1, ListNode* h2) {
  ListNode *ans, *cur;
  int carry = 0;

  while (h1 != nullptr || h2 != nullptr) {
    int sum =
        (h1 == nullptr ? 0 : h1->val) + (h2 == nullptr ? 0 : h2->val) + carry;
    int val = sum % 10;
    carry = sum / 10;

    if (ans == nullptr) {
      ans = new ListNode(val);
      cur = ans;
    } else {
      cur->next = new ListNode(val);
      cur = cur->next;
    }

    if (h1 != nullptr)
      h1 = h1->next;
    if (h2 != nullptr)
      h2 = h2->next;
  }

  if (carry == 1)
    cur->next = new ListNode(1);
  return ans;
}