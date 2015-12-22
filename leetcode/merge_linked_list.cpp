#include <iostream>

using namespace std;

#define max(a, b) a > b ? a : b

/**
 * Definition for binary tree
 */

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);
};

ListNode* Solution::mergeTwoLists(ListNode *l1, ListNode *l2){
    if(!l1) { return l2; }
    if(!l2) { return l1; }

    ListNode *new_head, *tail;
    if(l1->val <= l2->val) {
      new_head = l1;
      l1 = l1->next;
    }
    else{
      new_head = l2;
      l2 = l2->next;
    }
    tail = new_head;
    
    while(l1 && l2) {
      if(l1->val <= l2->val){
            tail->next = l1;
            l1 = l1->next;
      }
      else{
            tail->next = l2;
            l2 = l2->next;
      }
      tail = tail->next;
    }

    ListNode *rem = l1 ? l1 : l2;
    while(rem) {
      tail->next = rem;
      tail = tail->next;
      rem = rem->next;
    }
    tail->next = NULL;
    return new_head;
}

void print(ListNode *head){
    std::cout << "LL=> ";
    while(head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution *sol = new Solution();
    ListNode *head1 = new ListNode(20);
    ListNode *node1 = new ListNode(21);
    ListNode *node2 = new ListNode(22);
    head1->next = node1;
    head1->next->next = node2;

    ListNode *head2 = new ListNode(20);
    ListNode *node21 = new ListNode(21);
    ListNode *node22 = new ListNode(23);
    head2->next = node21;
    head2->next->next = node22;

    ListNode* new_head = sol->mergeTwoLists(head1, head2);
    print(new_head);
}