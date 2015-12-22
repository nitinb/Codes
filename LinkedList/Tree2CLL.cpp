/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : Tree2CLL.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Friday 13 May 2011 04:55:46 PM IST

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
void insert(int value){
    if (root == NULL) {
      root = new node();
      root->data = value;
      return;
    }

    node *curr = root, *prev;
    while(1){
        prev = curr;
        curr = curr->data >= value ? curr->left : curr->right;
        if(curr == NULL){
            node *n = new node();
            n->data  = value;
            if(value < prev->data){
                prev->left = n;
            }
            else{
                prev->right = n;
            }
            break;
        }
    }
}

/*
 * @desc: 
 *   recursive inorder traversal of tree 
 * @param: 
 *   root node of the tree/sub-tree 
 */
void rec_inorder( node * root){
   if(root == NULL){
       return;
   }
  
   rec_inorder(root->left);
   std::cout << root->data << "  ";
   rec_inorder(root->right);
}

/*
 * @desc: convert a tree to CLL
 */
node* T2CLL(node *temp){
   if(!temp) return temp;
   
   node *a = T2CLL(temp->left);
   node *b = T2CLL(temp->right);
   node *x;
   
   // IMP-Step
   temp->left = temp; temp->right = temp;
   
   // a is a headPtr of circular linked list
   // append `temp` in the last of CLL
   if(a){  
       a->left->right = temp;
       temp->left  = a->left;
       temp->right = a;
       a->left  = temp;
   }
   else{
       a = temp;
   }

   // a & b are headPtrs of 2 circular linked list
   // append 'b' to the end of CLL a
   // Same as prev step only diff is, here b is a list (temp was a node!!)
   //  So we need to use a var ptr 'x' to store the last node of 'b' list
   if(b){
       a->left->right = b;
       x  = b->left;
       b->left  = a->left;
       x->right = a;
       a->left  = x;
   }
   return a;
}

void Print(){
   if(root == NULL){
       return;
   }
   
   node *current = root;
   std::cout << "LL=> ";
   do{
       std::cout << current->data << "  ";
       current = current->right; 
   }while(current != root);
   std::cout << std::endl;
   
   std::cout << "Circular-LL=> ";
   do{
       std::cout << current->data << "  ";
       current = current->left; 
   }while(current != root);
   std::cout << std::endl;
}

int main(){
  int value;
  std::cout << "input value to insert in tree (( untill -1 )) " << std::endl;
  while(1){
    std::cin >> value;
    if(value == -1) break;
    insert(value);
  }
  rec_inorder(root);
  std::cout << std::endl;  

  root = T2CLL(root);
  Print();
  
  while(1){continue;}
}
