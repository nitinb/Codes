/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : print_anc.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Tuesday 05 July 2011 07:53:43 PM IST

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

bool print_anc(node *temp, int value){
    if(temp == NULL) return false;
   
    if(temp->data == value) return true;

    bool l = print_anc(temp->left, value);
    bool r = print_anc(temp->right, value);
    if(l || r){
        std::cout << temp->data << std::endl;
    }
    return l||r;
}

int main(){
  int value;
  std::cout << "input value to insert (( untill -1 )) " << std::endl;
  while(1){
    std::cin >> value;
    if(value == -1) break;
    insert(value);
  }

  std::cout << "value to search (( untill -1 )) " << std::endl;
  while(1){
    std::cin >> value;
    if(value == -1) break;
    print_anc(root, value);
  }
}
