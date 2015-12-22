/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : threaded_tree.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Tuesday 05 July 2011 07:56:29 PM IST

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
void insert(int value){
    if(root == NULL) {
        root = new node();
        root->data = value;
        return;
    }

    node *n = new node();
    n->data  = value;
    node *curr = root, *parent = NULL, *inorder_s = NULL, *inorder_p = NULL;
    bool add_to_left = true;
    while(curr != NULL){
        parent = curr;
        if(curr->data >= value){
            inorder_s = curr;
            curr = curr->left;
            add_to_left = true;
        }
        else{
            inorder_p = curr;
            curr = curr->right;
            add_to_left = false;
        }
    }

    if(add_to_left == true){
        parent->left = n;
        n->right = parent;
        n->left = inorder_p;
    }
    else{
        parent->right = n;
        n->left = parent;
        n->right = inorder_s;
    }
    return;
}

/*
 * @dec:
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
