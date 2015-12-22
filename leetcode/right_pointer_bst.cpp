#include <iostream>

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
    void connect(TreeLinkNode *root);
};

TreeLinkNode * get_next_node(TreeLinkNode *node, TreeLinkNode *parent) {
    if(parent->left == node) return parent->right;

    if(!parent->next) return NULL;

    return parent->next->left;
}

void Solution::connect(TreeLinkNode *root) {
    if(!root) return;

    TreeLinkNode *vertical = root;
    while(vertical->left) {
        TreeLinkNode *traverse = vertical;
        while(traverse != NULL) {
            if(traverse->left) {
                TreeLinkNode *next = get_next_node(traverse->left, traverse);
                traverse->left->next = next;
            }
            if(traverse->right) {
                TreeLinkNode *next = get_next_node(traverse->right, traverse);
                traverse->right->next = next;
            }
            traverse = traverse->next;
        }
        vertical = vertical->left;
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
    sol->connect(root);
}