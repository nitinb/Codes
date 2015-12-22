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
    ListNode *swapPairs(ListNode *head);
};

ListNode* Solution::swapPairs(ListNode *head) {
    ListNode *new_head = head, *tail = NULL;
    while(head != NULL && head->next != NULL) {
      ListNode *temp = head->next;
      head->next = head->next->next;
      temp->next = head;
      if(!tail) {
            new_head = temp;
      }
      else{
            tail->next = temp;
      }
      tail = head;
      head = head->next;
    }
    return new_head;
}

void print(ListNode *head) {
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
    ListNode *node3 = new ListNode(24);
    head1->next = node1;
    head1->next->next = node2;
    head1->next->next->next = node3;

    ListNode* new_head = sol->swapPairs(head1);
    print(new_head);
}