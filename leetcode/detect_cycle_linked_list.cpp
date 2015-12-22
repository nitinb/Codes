#include <iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head);
};

bool Solution::hasCycle(ListNode *head) {
    if(head == NULL) return false;

    ListNode *fast = head, *slow = head;
    while(true) {
        fast = fast->next;
        slow = slow->next;
        if(fast == NULL) {
            return false;
        }

        fast = fast->next;
        if(fast == NULL) {
            return false;
        }
        if(fast == slow) {
            return true;
        }
    }
}

int main() {
    Solution *sol = new Solution();

    bool num = sol->hasCycle(NULL);
    std::cout << num << std::endl;
}