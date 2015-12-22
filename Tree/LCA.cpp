/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : LCA.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Tuesday 12 July 2011 11:17:39 AM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>

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

node* find_lca(node* temp, node* p, node* q){
    if(temp == NULL){
        return NULL;
    }

    if(temp->left == p || temp->left == q || temp->right == p ||
           temp->right == q){
        return temp;
    }

    node* l1 = find_lca(temp->left, p, q);
    node* l2 = find_lca(temp->right, p, q);
    if(l1 && l2){
        return temp;
    }

    return l1 != NULL ? l1 : l2;
}

int main(){
  int value;
  std::cout << "input value to insert (( untill -1 )) " << std::endl;
  while(1){
    std::cin >> value;
    if(value == -1) break;
    insert(value);
  }

  node *p,  *q;

  find_lca(root, p, q);
}
