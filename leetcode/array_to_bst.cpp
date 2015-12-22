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
    TreeNode *sortedArrayToBST(std::vector<int> &num);
};

TreeNode *_sortedArrayToBST(std::vector<int> &num, int start, int end) {
      if(end < start) { return NULL; }
      int mid = (start + end) / 2;
      TreeNode *root = new TreeNode(num[mid]);
      if(start < end) {
            root->left = _sortedArrayToBST(num, start, mid - 1);
            root->right = _sortedArrayToBST(num, mid + 1, end);
      }
      return root;
}

TreeNode *Solution::sortedArrayToBST(std::vector<int> &num) {
      return _sortedArrayToBST(num, 0, num.size()-1);
}

void rec_inorder(TreeNode * root){
   if(root == NULL) return;
  
   rec_inorder(root->left);
   std::cout << root->val << "  ";
   rec_inorder(root->right);
   return;
}


int main() {
    Solution *sol = new Solution();
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> num (arr, arr + sizeof(arr)/sizeof(int));
    TreeNode * root = sol->sortedArrayToBST(num);
    rec_inorder(root);
    std::cout << std::endl;
}