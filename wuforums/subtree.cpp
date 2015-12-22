#include <iostream>
#include <cmath>
#include <cstdio>

#define DEBUG 0

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

// convert the tree structure into a string
// Convert subtree check in to longest common sequence
void rec_postorder(node * root, char child){
    if(root == NULL && child == 'l'){
        std::cout << "a";
        return;
    }

    if(root == NULL && child == 'r'){
        std::cout << "b";
        return;
    }

    if(root == NULL){
        std::cout << child;
        return;
    }

    rec_postorder(root->left, 'l');
    rec_postorder(root->right, 'r');
    std::cout << child;
    return;
}

int main(){
  int value;
  std::cout << "input value to insert (( untill -1 )) " << std::endl;
  while(1){
    std::cin >> value;
    if(value == -1) break;
    insert(value);
  }

  rec_postorder(root, 'R');
  std::cout << std::endl;
}
