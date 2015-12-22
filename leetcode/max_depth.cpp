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
    int maxDepth(TreeNode *root);
};

int Solution::maxDepth(TreeNode *root) {
    if(root == NULL) {
        return 0;
    }

    int lh = this->maxDepth(root->left);
    int rh = this->maxDepth(root->right);
    int _h = max(lh, rh);
    return _h + 1;
}

int main() {
    Solution *sol = new Solution();
    TreeNode *root = new TreeNode(2);
    TreeNode *l1 = new TreeNode(21);
    TreeNode *r1 = new TreeNode(22);
    root->left = l1;
    root->left->left = r1;
    
    int num = sol->maxDepth(NULL);
    std::cout << num << std::endl;
}