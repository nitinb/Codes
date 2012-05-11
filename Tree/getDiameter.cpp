/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : getDiameter.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Wednesday 13 July 2011 12:07:59 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <cmath>

/*STL *algorithm* */
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 1
#define max(a,b) a>b?a:b

struct node{
  public:
   int data;
   struct node *left ;
   struct node *right;
     node(){
        left = right = NULL;
     }
};
/*
 * GLOBAL variable representing the root
 *  node of tree
 */
node * root = NULL;

void insert ( int value ){
  if (root == NULL) {
    root = new node();
    root->data = value;
    return;
  }

  node * curr = root;
  node * prev = curr;
  while(1){
    prev = curr;
    curr = curr->data >= value ? curr->left : curr->right;
    if(curr == NULL){
       node * n = new node();
       n->data  = value;
       if( value < prev->data ) prev->left = n;
       else prev->right = n;
       break;
    }
  }
  return;
}

/*
 * @desc:
 *   recursive inorder traversal of tree
 * @param:
 *   root node of the tree/sub-tree
 */
void rec_inorder( node * root){
   if(root == NULL) return;

   rec_inorder(root->left);
   std::cout << root->data << "  ";
   rec_inorder(root->right);
   return;
}

int getDiameter(node *temp, int *height){
    if(temp == NULL){
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0, ld = 0, rd = 0;

    ld = getDiameter(temp->left, &lh);
    rd = getDiameter(temp->right,&rh);

    *height = max(lh, rh) + 1;
    return max(max(lh + rh + 1, ld), rd);
}

int main(){
  int value;
  std::cout << "input value to insert (( untill -1 )) " << std::endl;
  while(1){
    std::cin >> value;
    if(value == -1) break;
    insert(value);
  }

  rec_inorder(root);
  std::cout << std::endl;

  int var;
  int ret = getDiameter(root, &var);
  std::cout << ret << std::endl;
  std::cout << var << std::endl;
}
