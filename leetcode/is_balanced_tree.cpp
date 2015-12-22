#include <iostream>
#include <cstdlib>

using namespace std;

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
    bool isBalanced(TreeNode *root);
};

bool _is_balanced(TreeNode *root, int *height) {
    if(!root) { *height = 0; return true; }

    int lh = 0, rh = 0;
    bool l_balanced = _is_balanced(root->left, &lh);
    bool r_balanced = _is_balanced(root->right, &rh);
    *height = lh > rh ? lh + 1 : rh + 1;
    return l_balanced && r_balanced && abs(lh - rh) <= 1;
}

bool Solution::isBalanced(TreeNode *root) {
    int height = 0;
    return _is_balanced(root, &height);
}

int main() {
    Solution *sol = new Solution();
    TreeNode *root1 = new TreeNode(21);
    TreeNode *n1 = new TreeNode(21);
    TreeNode *n2 = new TreeNode(21);
    root1->left = n1;
    root1->right = n2;

    bool num = sol->isBalanced(root1);
    std::cout << num << std::endl;
}