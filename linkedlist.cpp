#include <algorithm>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};


void push(ListNode** head_ref, int new_key) {
    /* allocade new node*/
    ListNode* new_node = new ListNode();
    /* put new value in the key*/
    new_node->val = new_key;
    /* link the old list of the new node*/
    new_node->next = *head_ref;
    /* move the head to point to the new node*/
    *head_ref = new_node;
}

void pb(ListNode*& head, int value) {
    // Step 1: Create the new node
    ListNode* new_node = new ListNode();
    new_node->val = value;
    new_node->next = nullptr;

    if (!head) {
        head = new_node;
        return;
    }

    ListNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }

    temp->next = new_node;
}


int main() {
    ListNode* head = nullptr;
    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);

    vector<int> v;
    ListNode* temp = head;
    while(temp!=nullptr){
        v.push_back(temp->val);
        temp = temp->next;
    }

    for (auto& v_:v) {
        cout << v_ << endl;
    }    
    return 0;
}