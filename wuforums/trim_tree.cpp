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

void new_iterative_inorder(node* root, int direction=0){
    std::stack<node*> st;

    init_stack(root, st, 0);

    while(st.empty() != true){
        std::cout << get_next(st, 0)->data << " ";
    }
    std::cout << std::endl;
}

void trim_tree(node* root, int min, int max){
    if(root == NULL){
        return;
    }

    if(root->left != NULL && root->left->data >= min){
        trim_tree(root->left, min, max);
    }
    else{
        root->left = NULL;
    }

    if(root->right != NULL && root->right->data <= max){
        trim_tree(root->right, min, max);
    }
    else{
        root->right = NULL;
    }
}

int main(){
    int value, min, max;
    std::cout << "input value to insert (( untill -1 )) " << std::endl;
    while(1){
        std::cin >> value;
        if(value == -1) break;
        insert(value);
    }

    std::cout << "min-range ";
    std::cin >> min;
    std::cout << "max-range ";
    std::cin >> max;
    new_iterative_inorder(root);
    trim_tree(root, min, max);
    new_iterative_inorder(root);
}
