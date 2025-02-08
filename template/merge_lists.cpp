#include "algobase.h"
#include "node.h"

using namespace std;

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  if (list1 == nullptr || list2 == nullptr)
    return list1 == nullptr ? list2 : list1;
  ListNode* head = list1->val <= list2->val ? list1 : list2;
  ListNode* cur1 = head->next;
  ListNode* cur2 = head == list1 ? list2 : list1;
  ListNode* pre = head;

  while (cur1 != nullptr && cur2 != nullptr) {
    if (cur1->val <= cur2->val) {
      pre->next = cur1;
      cur1 = cur1->next;
    } else {
      pre->next = cur2;
      cur2 = cur2->next;
    }
    pre = pre->next;
  }
  pre->next = cur1 != nullptr ? cur1 : cur2;
  return head;
}