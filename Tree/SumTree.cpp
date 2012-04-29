/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : SumTree.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Monday 11 July 2011 08:46:24 PM IST

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

struct node{
  public:
   int data;
   struct node *left ;
   struct node *right;
     node(int _data){
        data = _data;
        left = right = NULL;
     }
};
/*
 * GLOBAL variable representing the root
 *  node of tree
 */
node * root = NULL;

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


int sum_tree(node *temp){
     if(!temp) return 0;
     
     int ls = sum_tree(temp->left);
     if(ls < 0) return ls;
          
     int rs = sum_tree(temp->right);
     if(rs < 0) return rs;
     
     return ls==0&&rs==0 ? temp->data : ls+rs == temp->data ? 2*temp->data : -1;
}

int main(){
  int value;

  node* n1 = new node(34); root = n1;
  node* n2 = new node(10); root->left = n2;
  node* n3 = new node(7);  root->right = n3;
  
  node* n4 = new node(5); root->left->left  = n4;
  node* n5 = new node(5); root->left->right = n5;
  node* n6 = new node(4); root->right->left  = n6;
  node* n7 = new node(3); root->right->right = n7;

  node* n8 = new node(2); root->right->right->right = n8;
  node* n9 = new node(1); root->right->right->left  = n9;

  rec_inorder(root);
  std::cout << std::endl;

  int ret = sum_tree(root);
  std::cout << ret << std::endl;
  while(1){continue;}
}
