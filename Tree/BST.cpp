/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : BST.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Tuesday 05 July 2011 07:49:24 PM IST

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
 *   DELETE a key From BStree
 * @param:
 *   key to delete from tree
 */
void delete_n (int key){
  node *temp = root, *parent = NULL;
  bool flag  = false;

  // search for the key
  while(1){
    if(temp == NULL || temp->data == key) break;
    parent = temp;
    if(temp->data >= key) { temp = temp->left; flag = true; }
    else { temp = temp->right; flag = false; }
  }
  /*
   * temp: node we have to delete ( can be NULL if key not found in tree )
   * parent: ptr to parent of temp 
   *   ( if temp is root node of tree then parent is NULL )
   */
  if(temp == NULL ) return;

  // leaf node ( both child ptrs are NULL )
  if(temp->right == NULL && temp->left == NULL){
    if(parent == NULL) root = NULL;
    else if(flag) parent->left = NULL;
    else parent->right = NULL;
    delete(temp);
    return;
  }

  // case: only one child
  if(temp->left == NULL || temp->right == NULL){
    node *move = temp->left == NULL ? temp->right : temp->left;
    
    if(parent == NULL) root    = move;
    else if(flag) parent->left = move;
    else parent->right = move;
    delete(temp);
    return;
  }

  // case: both child ptrs are non-null
  // find inorder successor of the temp node.. 
  // ..copy its value to temp node
  // ..delete the inorder successor node
  node *inorder_s = temp->right; parent = temp;
  while(inorder_s->left != NULL) { parent = inorder_s; inorder_s = inorder_s->left; }
  temp->data   = inorder_s->data;
  parent != temp ? parent->left = inorder_s->right : parent->right = inorder_s->right;
  delete(inorder_s);
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
 *   recursive post-order traversal of tree 
 * @param: 
 *   root node of the tree/sub-tree 
 */
void rec_postorder( node * root){
   if(root == NULL) return;
  
   rec_postorder(root->left);
   rec_postorder(root->right);
   std::cout << root->data << "  ";
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

/*
 * @desc: 
 *   iterative inorder traversal of tree
 * @param:
 *   root node of the tree/sub-tree
 */
void iterative_inorder(node *root){
   std::stack <node* > S;
   while( !S.empty() || root != NULL){
      if(root != NULL){
         S.push(root);
         root = root->left;
      }
      else{
         root = S.top();
         S.pop();
         std::cout << root->data << "  ";
         root = root->right;
      }
   }
}

/*
 * @desc: 
 *   iterative pre-order traversal of tree
 * @param:
 *   root node of the tree/sub-tree
 */
void iterative_preorder(node *root){
   std::stack <node* > S;
   while( !S.empty() || root != NULL){
      if(root != NULL){
         std::cout << root->data << "  ";
         S.push(root);
         root = root->left;
      }
      else{
         root = S.top();
         S.pop();
         root = root->right;
      }
   }
}

/*
 * @desc: 
 *   iterative post-order traversal of tree
 * @param:
 *   root node of the tree/sub-tree
 */
//TODO not working code...
void iterative_postorder(node *root){
   std::stack <node* > S;
   while( !S.empty() || root != NULL){
      if(root != NULL){
         S.push(root);
         root = root->left;
      }
      else{
         root = S.top();
         //S.pop();
         root = root->right;
      }
   }
}

void level_order(node* temp){
    std::queue<node *> Q;
    
    if(temp != NULL) Q.push(temp);
    while( !Q.empty() ){
       temp = Q.front();
       Q.pop();
       std::cout << temp->data << " ";
       if(temp->left != NULL) Q.push(temp->left);
       if(temp->right != NULL) Q.push(temp->right);
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
  rec_postorder(root);
  std::cout << std::endl;
  rec_preorder(root);
  std::cout << std::endl;
  iterative_inorder(root);
  std::cout << std::endl;
  iterative_preorder(root);
  std::cout << std::endl;
  level_order(root);
  std::cout << std::endl;

  delete_n(11);
  rec_inorder(root);
  std::cout << std::endl;

  delete_n(21);
  rec_inorder(root);
  std::cout << std::endl;

  delete_n(100);
  rec_inorder(root);
  std::cout << std::endl;

  delete_n(80);
  rec_inorder(root);
  std::cout << std::endl;

  delete_n(40);
  rec_inorder(root);
  std::cout << std::endl;
  while(1){continue;}
}
