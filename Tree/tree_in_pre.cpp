/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : tree_in_pre.cpp

* Purpose :

* Creation Date : 05-07-2011

* Last Modified : Wednesday 06 July 2011 05:13:37 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>

/*STL *algorithm* */
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 1
#define MAX_SIZE 100

#define FORI(i, a, b) for(int i = a ; i < b ; i++)
#define getInt(a) scanf("%d",&a);
#define getUInt(a) scanf("%ud",&a);
#define getLong(a) scanf("%lld",&a);
#define getULong(a) scanf("%ulld",&a);
#define getdouble(a) scanf("%lf",&a);
#define getCh(a) scanf("%c",&a);


struct node{
  public:
   int data;
   struct node *left ;
   struct node *right;
     node(){
        data = -1;
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
 *   insert function for BST **
 * @param: 
 *   value to be inserted
 */
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

/*
 * @desc: 
 *   recursive pre-order traversal of tree 
 * @param: 
 *   root node of the tree/sub-tree 
 */
void rec_preorder( node * root){
   if(root == NULL) return;
  
   std::cout << root->data << "  ";
   rec_preorder(root->left);
   rec_preorder(root->right);
   return;
}

int search_array(int *a, int n, int key){
   FORI(i, 0, n){
       if(a[i] == key){ return i; }
   }
   std::cout << "error, " << key << " not found in array!!" << std::endl;
}

node* make_tree(int *in_order, int *pre_order, int start, int end, int max){
    static int preorder_start = 0;  
 
    if(preorder_start >= max) return NULL;
    if(start < 0) return NULL;
    if(end > max) return NULL;
    if(end < start) return NULL;

    int index = search_array(in_order, max, pre_order[preorder_start]);
    node * n = new node();
    n->data  = pre_order[preorder_start];
    preorder_start++;

    n->left  = make_tree(in_order, pre_order, start, index-1, max);
    n->right = make_tree(in_order, pre_order, index+1, end, max);
    return n;
}

int main(){
  int value, num_nodes = 0;
  std::cout << "input value to insert (( untill -1 )) " << std::endl;
  while(1){
    std::cin >> value;
    if(value == -1) break;
    num_nodes++;
    insert(value);
  }

  std::cout << "in-order traversal of tree" << std::endl;
  rec_inorder(root);
  std::cout << std::endl;
  std::cout << "pre-order traversal of tree" << std::endl;
  rec_preorder(root);
  std::cout << std::endl;

  int in_order[MAX_SIZE] = {0}, pre_order[MAX_SIZE] = {0};
//  std::cout << "in-order traversal" << std::endl;
  FORI(i, 0, num_nodes){
     std::cin >> in_order[i];  
  }

//  std::cout << "pre-order traversal" << std::endl;
  FORI(i, 0, num_nodes){
     std::cin >> pre_order[i];
  }
  
  node *n_root = NULL; 
  n_root = make_tree(in_order, pre_order, 0, num_nodes, num_nodes);
  rec_inorder(n_root);
  std::cout << std::endl;
}
