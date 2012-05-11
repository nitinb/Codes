/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : LCA.cpp

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
 *   search for a key in BStree 
 * @param: 
 *   key to search 
 */
node * search(int key){
  node *temp = root;
  while(1){
    if(temp == NULL || temp->data == key) return temp;
    if(temp->data >= key) temp = temp->left;
    else temp = temp->right;
  }
}

/*
 * @desc: 
 *   recursive inorder traversal of tree 
 * @param: 
 *   root node of the tree/sub-tree 
 */
void rec_inorder(node * root){
   if(root == NULL) return;
  
   rec_inorder(root->left);
   std::cout << root->data << "  ";
   rec_inorder(root->right);
   return;
}


bool do_stuff(node * root, node * node1, node * node2, node ** parent1, node ** parent2){
    if(root == NULL){
         return false;
    }
    
    std::cout << "func call, data: " << root->data << std::endl;
    
    if(root->left == node1 || root->right == node1){
         std::cout << "set parent1, data: " << root->data << std::endl;
         *parent1 = root;
    }
    
    if(root->left == node2 || root->right == node2){
         std::cout << "set parent2, data: " << root->data << std::endl;                   
         *parent2 = root;
    }
    
    if(*parent1 && *parent2){
         return true;
    }
    
    if(do_stuff(root->left, node1, node2, parent1, parent2) ||
       do_stuff(root->right, node1, node2, parent1, parent2)){
         if(*parent1 == NULL && *parent2 == NULL){
             *parent1 = root;
             *parent2 = root;
         }
       
         if(parent1 == NULL){
             *parent1 = root;
         }
         
         if(parent2 == NULL){
             *parent2 = root;
         }

         if(*parent1 == *parent2){
             std::cout << "lca node data: " << (*parent1)->data << std::endl;
             return true;
         }
         
         return true;
    }
    return false;
}


node* find_lca(node * root, node * node1, node * node2){
    node * parent1 = NULL, * parent2 = NULL;
    do_stuff(root, node1, node2, &parent1, &parent2);
    return parent1;
}


int main(){
    int arr[] = {10, 19, 16, 21, 14, 5, 7, 8, 6, 3};
    int size = sizeof(arr)/sizeof(int);
    
    for(int i = 0; i < size; i++){
        insert(arr[i]);
    }
    
    rec_inorder(root);
    std::cout << std::endl;
    
    node * node1 = search(14);
    node * node2 = search(21);
    node * lca_node = find_lca(root, node1, node2);
    
    if(lca_node){
         std::cout << "{main} lca node data: " << lca_node->data << std::endl;
    }
    else{
         std::cout << "FU" << std::endl;
    }
    
    while(1){continue;}
}
