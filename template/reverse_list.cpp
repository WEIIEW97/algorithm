#include "algobase.h"
#include "node.h"

using namespace std;

ListNode* reverse_list(ListNode* head) {
  ListNode* pre = nullptr;
  ListNode* next = nullptr;

  while (head != nullptr) {
    next = head->next;
    head->next = pre;
    pre = head;
    head = next;
  }
  return pre;
}

DoubleListNode* reverse_double_list(DoubleListNode* head) {
  DoubleListNode* pre = nullptr;
  DoubleListNode* next = nullptr;

  while (head != nullptr) {
    next = head->next;
    head->next = pre;
    head->last = next;
    pre = head;
    head = next;
  }
  return pre;
}
