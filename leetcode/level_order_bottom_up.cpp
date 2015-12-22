#include <iostream>
#include <vector>

using namespace std;

struct TreeLinkNode {
      int val;
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
      TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


class Solution {
  public:
    std::vector<std::vector<int> > levelOrderBottom(TreeNode *root);
};

std::vector<std::vector<int> > Solution::levelOrderBottom(TreeLinkNode *root) {
      std::vector<std::vector<int> > traversal;
      
}

void print(std::vector<std::vector<int> > tri) {
    for(int i = 0; i < tri.size(); i++) {
        std::cout << "[";
        for(int j = 0; j < tri[i].size(); j++) {
            std::cout << tri[i][j] << ",";
        }
        std::cout << "]" << std::endl;
    }
}

int main() {
    Solution *sol = new Solution();

    TreeLinkNode *root = new TreeLinkNode(1);
    TreeLinkNode *left = new TreeLinkNode(2);
    TreeLinkNode *right = new TreeLinkNode(3);
    TreeLinkNode *left1 = new TreeLinkNode(4);
    root->left = left; root->right = right;
    root->left->left = left1;
    std::vector<std::vector<int> >traversal = sol->levelOrderBottom(root);
    print(traversal);
}