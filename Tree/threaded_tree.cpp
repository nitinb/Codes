/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : threaded_tree.cpp

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
 *   insert function for ThreadedTree 
 *  for a node in threaded tree 
 *       left ptr points to inorder_predecessor
 *  and  right ptr points to inorder_successor
 * @param: 
 *   value to be inserted
 */
void insert ( int value ){
  if (root == NULL) {
    root = new node();
    root->data = value;
    return;
  }

  node * n = new node();
  n->data  = value;
  node * curr = root;
  node * inorder_s = NULL, *inorder_p = NULL;
  while(1){
    if(curr->data >= value){
       if(curr->left && curr->left->data > value) { 
            curr = curr->left;
       }
       else{
            inorder_s = curr;            
            curr->left = n;
            break;
       }
    }
    else{
        if(curr->right && curr->right->data < value){
            curr = curr->right;
        }
        else{
            inorder_p = curr;             
            curr->right = n;           
            break;
       }
    }
  }
  n->left  = inorder_p;
  n->right = inorder_s;  
  return;
}

/*
 * @desc: 
 *   iterative inorder traversal of a Threaded-Tree 
 * @param: 
 *   root node of the tree
 */
void iterative_inorder( node * root){
   if(root == NULL) return;
  
//   rec_inorder(root->left);
   std::cout << root->data << "  ";
//   rec_inorder(root->right);
   return;
}


int main(){
  int value;
  std::cout << "input value to insert (( untill -1 )) " << std::endl;
  while(1){
    std::cin >> value;
    if(value == -1) break;
    insert(value);
    std::cout << value << " inserted in the tree " << std::endl;
  }

//  rec_inorder(root);
  std::cout << std::endl;
  while(1){continue;}
}
