/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : PProblems.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Tuesday 05 July 2011 07:51:41 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <cmath>
#include <sstream>

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
void rec_inorder(node * temp){
   if(temp == NULL) return;
  
   rec_inorder(temp->left);
   std::cout << temp->data << "  ";
   rec_inorder(temp->right);
   return;
}

int count_nodes(node * temp){
  if(temp == NULL) return 0;
  else return 1 + count_nodes(temp->left) + count_nodes(temp->right) ;   
}

#define max(a,b) a>b?a:b
int depth(node * temp){    
    if(temp == NULL) { return 0; }
    else { 
      int ld = depth(temp->left);
      int rd = depth(temp->right);
      return 1 + (max(ld,rd)); 
    }
}

bool has_path_sum(node * temp, int sum){
  if(temp == NULL && sum == 0) return true;
  if(temp == NULL && sum != 0) return false;
  else{
    return (has_path_sum(temp->left, sum-temp->data)||has_path_sum(temp->right, sum-temp->data));
  }
}

void print_path(node *temp, int arr[], int len){
  if(temp != NULL){ arr[len++] = temp->data; }
  
  if(temp == NULL || !(temp->left || temp->right) ){//leaf node(both children are null)
     for(int i = 0; i < len; i++) std::cout << arr[i] <<" ";
     std::cout << std::endl;
     return;
  }
  else {
    if(temp->left != NULL) print_path(temp->left, arr, len);
    if(temp->right != NULL) print_path(temp->right, arr, len);    
  }
}

void mirror_a_tree(node *temp){
  if(temp == NULL){ return; }
  else{
     node *swap = temp->left;
     temp->left = temp->right;
     temp->right= swap;
     mirror_a_tree(temp->left);
     mirror_a_tree(temp->right);     
  }
}

void double_tree(node *temp){
  if(temp == NULL){ return; }
  else{
     node *nn   = new node();
     nn->data   = temp->data;
     nn->left   = temp->left;
     temp->left = nn;
     double_tree(temp->left->left);
     double_tree(temp->right);
  }
}

bool same_tree(node *temp1, node *temp2){
   if(!(temp1 || temp2)) return true; // both are null
   else if(!(temp1 && temp2)) return false; // one of them is null
   else{ 
    if(temp1->data != temp2->data) return false;
    else return (same_tree(temp1->left,temp2->left)&&same_tree(temp1->right,temp2->right) );
   }
}
node *root2 = NULL;

int count_trees(int num_keys){
    if(num_keys <= 1) return 1;
    else{
        int tot_trees = 0;
        for(int i = 1; i < num_keys; i++)
            tot_trees += count_trees(i-1) * count_trees(num_keys - i);
        return tot_trees;
    }
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

  int _count = count_nodes(root);
  std::cout << _count << std::endl;
  
  int _depth = depth(root);
  std::cout << _depth << std::endl;  
  
//  bool _flag = same_tree(root, root2);
//  std::cout << "same tree: " << _flag << std::endl;
  
  std::cout << has_path_sum(root, 23) << std::endl;
  std::cout << has_path_sum(root, 20) << std::endl;
  std::cout << has_path_sum(root, 50) << std::endl;  
    
  int arr[10];  
  print_path(root, arr, 0);
  
  mirror_a_tree(root);
  double_tree(root);  
  rec_inorder(root);
  std::cout << std::endl;
  
  _count = count_trees(3);
  std::cout << _count << std::endl;
    
  _count = count_trees(1);
  std::cout << _count << std::endl;    
    
  _count = count_trees(4);
  std::cout << _count << std::endl;
      
  while(1){ continue; }
}
