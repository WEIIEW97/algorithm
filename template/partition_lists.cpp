#include "algobase.h"
#include "node.h"

using namespace std;

ListNode* partition(ListNode* head, int x) {
  ListNode *l_head = nullptr, *l_tail = nullptr, *r_head = nullptr,
           *r_tail = nullptr;
  ListNode* next = nullptr;

  while (head != nullptr) {
    next = head->next;
    head->next = nullptr; // Break existing link before re-assigning
    if (head->val < x) {
      if (l_head == nullptr)
        l_head = head;
      else
        l_tail->next = head;
      l_tail = head;
    } else {
      if (r_head == nullptr)
        r_head = head;
      else
        r_tail->next = head;
      r_tail = head;
    }
    head = next;
  }
  if (l_head == nullptr)
    return r_head;
  l_tail->next = r_head;
  return l_head;
}