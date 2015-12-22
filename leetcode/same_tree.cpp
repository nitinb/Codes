#include <iostream>

using namespace std;

#define max(a, b) a > b ? a : b

/**
 * Definition for binary tree
 */

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q);
};

bool Solution::isSameTree(TreeNode *p, TreeNode *q) {
      if(p == NULL && q == NULL) {
            return true;
      }
      if(p == NULL || q == NULL || (p->val != q->val)) {
            return false;
      }

      return (this->isSameTree(p->left, q->left)) && (this->isSameTree(p->right, q->right));
}

int main() {
    Solution *sol = new Solution();
    TreeNode *root1 = new TreeNode(21);
    TreeNode *root2 = new TreeNode(21);

    bool num = sol->isSameTree(root1, root2);
    std::cout << num << std::endl;
}