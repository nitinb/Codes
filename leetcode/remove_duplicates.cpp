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
    ListNode *deleteDuplicates(ListNode *head);
};

ListNode* Solution::deleteDuplicates(ListNode *head){
      if(!head || !head->next) return head;

      ListNode *prev = head, *iter = head->next;
      do {
            if(prev->val == iter->val) {
                  prev->next = iter->next;
                  ListNode *temp = iter;
                  iter = iter->next;
                  delete(temp);
            }
            else{
                  prev = iter;
                  iter = iter->next;
            }
            
      }while(iter);
      return head;
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
    ListNode *head = new ListNode(20);
    ListNode *node1 = new ListNode(21);
    ListNode *node2 = new ListNode(22);
    head->next = node1;
    head->next->next = node2;

    ListNode* new_head = sol->deleteDuplicates(head);
    print(new_head);
}