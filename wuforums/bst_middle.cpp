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

void init_stack(node* root, std::stack<node*>& st, int direction=0){
    if(root == NULL){
        return;
    }

    do{
        st.push(root);
        if(direction == 0){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }while(root != NULL);
}

node* get_next(std::stack<node*>& st, int direction=0){
    if(st.empty() == true){
        return NULL;
    }

    node* root = st.top();
    node* next_node = root;
    st.pop();

    if(direction == 0){
        root = root->right;
    }
    else{
        root = root->left;
    }
    while(root != NULL){
        st.push(root);
        if(direction == 0){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }

    return next_node;
}

void get_middle_node(node *root){
    std::stack<node *> stack1;

    init_stack(root, stack1);

    node *next = NULL, *next_to_next = NULL;

    while(1){
        next = get_next(stack1);
        if(stack1.empty() == true){
            return next_to_next;
        }

        next_to_next = get_next(stack1);
        if(stack1.empty() == true){
            return next_to_next;
        }
    }
}

void new_iterative_inorder(node* root, int direction=0){
    std::stack<node*> st;

    init_stack(root, st, 0);

    while(st.empty() != true){
        std::cout << get_next(st, 0)->data << " ";
    }
    std::cout << std::endl;
}

int main(){
  int value, sum;
  std::cout << "input value to insert (( untill -1 )) " << std::endl;
  while(1){
    std::cin >> value;
    if(value == -1) break;
    insert(value);
  }

  new_iterative_inorder(root);

  get_middle_node(root);
}
