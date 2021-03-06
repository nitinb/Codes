/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : BST.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Tuesday 12 July 2011 02:29:12 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <cmath>
#include <cstdio>

/*STL *algorithm* */
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

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

/**
 * @desc: 
 *   DELETE a key From BStree
 * @param:
 *   key to delete from tree
 */
void delete_n(int key){
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

  if(temp->right == NULL){
      if(parent == NULL){
          root = temp->left;
      }
      else if(flag == true){
          parent->left = temp->left;
      }
      else{
          parent->right = temp->left;
      }

      delete temp;
      return;
  }

  node *inorder_s = temp->right;
  parent = temp;
  while(inorder_s->left != NULL){
      parent = inorder_s;
      inorder_s = inorder_s->left;
  }
  temp->data = inorder_s->data;
  
  //Delete inorder_s node
  if(parent == temp){
      parent->right = inorder_s->right; 
  }
  else{
      parent->left = inorder_s->right;
  }
  delete inorder_s;
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
         if(root->right != NULL){
             S.push(root->right);
         }
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
    std::cout << "Level order " << std::endl;
    if(temp == NULL) return;  

    std::queue<node *> Q;
    node *sep = NULL;
    int count_non_sep = 0;

    Q.push(temp);
    Q.push(sep);
    while(!Q.empty()){
        temp = Q.front();
        Q.pop();

        if(temp == sep){
            std::cout << std::endl;
            Q.push(sep);
            if(count_non_sep == 0){
               break;
            }
            count_non_sep = 0;
        }
        else{
            std::cout << temp->data << " ";

            if(temp->left != NULL){
                Q.push(temp->left);
                count_non_sep++;
            }
            if(temp->right != NULL){
                Q.push(temp->right);
                count_non_sep++;
            }
        }
    }
}

void spiral_level_order(node* temp){
    std::cout << "Spiral level order " << std::endl;
    if(temp == NULL) return;  
    
    std::queue<node *> Q;
    std::stack<int> T_S;
 
    int level = 1, count_non_sep = 0;
    Q.push(temp);
    node *sep = NULL;
    Q.push(sep);

    while(!Q.empty()){
        temp = Q.front();
        Q.pop();
        if(temp == sep){
            level++;
            if(level % 2 == 1){
                while(!T_S.empty()){
                    std::cout << T_S.top() << " ";
                    T_S.pop();
                }
            }
            if(count_non_sep == 0) { break; }
            count_non_sep = 0;
            std::cout << std::endl;
            Q.push(sep);
        }
        else{
            if(level % 2 == 1){
                std::cout << temp->data << " ";
            }
            else{
                T_S.push(temp->data);     
            }

            if(temp->left != NULL){
                Q.push(temp->left);
                count_non_sep++;
            }
            if(temp->right != NULL){
                Q.push(temp->right);
                count_non_sep++;
            }
        }
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

  spiral_level_order(root);
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
}
