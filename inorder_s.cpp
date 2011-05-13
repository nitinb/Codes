/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : BST.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Friday 13 May 2011 07:58:00 PM IST

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
 *   FIND inorder_s of a key from BStree
 * @param:
 *   key whose inorder_s to find 
 */
node* inorder_s (int key){
  node *temp = root, *parent = NULL;
  bool flag = false;

  // search for the key
  while(1){
    if(temp == NULL || temp->data == key) break;
    parent = temp;
    if(temp->data >= key) { temp = temp->left; flag = true; }
    else { temp = temp->right; flag = false; }
  }
  /*
   * temp: node whose inorder_s we need to find ( can be NULL if key not found in tree )
   * parent: ptr to parent of temp 
   *   ( if temp is root node of tree then parent is NULL )
   */
  if(temp == NULL ) return NULL;

  /* inorder successor of a node =>
   *   if left child then parent of node
   *   if right child
   *      leftmost child of right sub-tree ( if right sub-tree is there )
   *        OR first left ancestor of node 
   */
  node *inorder_s;
  if(temp->right != NULL){
    inorder_s = temp->right;
    while(inorder_s->left != NULL) { inorder_s = inorder_s->left; }
  }
  else{
   inorder_s = parent; 
  } 
  return inorder_s;
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

  node * _ret;
  while( value != -2){
    std::cin >> value;
    _ret = inorder_s(value);
    if( _ret ) std::cout << "inorder successor : " << _ret->data << std::endl;
    else std::cout << value << " doesn't exist in tree " << std::endl;
  }
}
