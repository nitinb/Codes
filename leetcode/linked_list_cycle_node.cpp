#include <iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *detectCycle(ListNode *head);
};

ListNode* Solution::detectCycle(ListNode *head) {
    if(head == NULL) return NULL;

    ListNode *fast = head, *slow = head;
    while(true) {
        fast = fast->next;
        slow = slow->next;
        if(fast == NULL) {
            return NULL;
        }

        fast = fast->next;
        if(fast == NULL) {
            return NULL;
        }
        if(fast == slow) {
            break;
        }
    }

    int count = 0;
    do {
      slow = slow->next;
      fast = fast->next->next;
      count++;
      
    } while(fast != slow);

    ListNode *front = head, *back = head;
    while(count > 0) {
      front = front->next;
      count--;
    }

    while(front != back) {
      front = front->next;
      back = back->next;
    }
    return front;
}

int main() {
    Solution *sol = new Solution();

    ListNode* head = new ListNode(1);
    ListNode* first = new ListNode(2);
    ListNode* second = new ListNode(3);
    head->next = first;
    first->next = second;
    second->next = first;
    
    ListNode* retval = sol->detectCycle(head);
    std::cout << retval->val << std::endl;
}