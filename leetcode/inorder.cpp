#include <iostream>
#include <stack>
#include <vector>

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
    std::vector<int> inorderTraversal(TreeNode *root);
};

std::vector<int> Solution::inorderTraversal(TreeNode *root) {
    std::vector<int> retval;
    std::stack<TreeNode *> cache;
    while(root != NULL || !cache.empty()) {
      if(!root) {
          root = cache.top();
          cache.pop();
          retval.push_back(root->val);
          root = root->right;
      }

      if(root) {
            cache.push(root);
            root = root->left;
      }
    }
    return retval;
}

void print_vector(std::vector<int> vect){
  std::vector<int>::iterator it;
  for(it = vect.begin(); it != vect.end(); it++){
     std::cout << *it << " ";
  }
  std::cout << "\n";
}

int main() {
    Solution *sol = new Solution();
    TreeNode *root = new TreeNode(21);
    TreeNode *l1 = new TreeNode(2);
    TreeNode *r1 = new TreeNode(22);
    root->left = l1;
    root->right = r1;
    
    std::vector<int> num = sol->inorderTraversal(NULL);
    print_vector(num);
}