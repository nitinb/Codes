#include <iostream>

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
    bool isSymmetric(TreeNode *root);
};

bool is_symmetric(TreeNode *tree1, TreeNode *tree2) {
      if(!tree1 && !tree2) { return true; }
      if(!tree1 || !tree2) { return false; }
      
      return (tree1->val == tree2->val) && is_symmetric(tree1->left, tree2->right) \
                  && is_symmetric(tree1->right, tree2->left);
}

bool Solution::isSymmetric(TreeNode *root) {
      if(!root) { return true; }

      return is_symmetric(root->left, root->right);
}

int main() {
    Solution *sol = new Solution();
    TreeNode *root = new TreeNode(21);
    TreeNode *left1 = NULL; //new TreeNode(3);
    TreeNode *right1 = NULL; //new TreeNode(3);
    root->left = left1; root->right = right1;

    bool num = sol->isSymmetric(root);
    std::cout << num << std::endl;
}