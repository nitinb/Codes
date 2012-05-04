/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : ReverseLL.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Friday 13 May 2011 07:58:00 PM IST

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
#define MAX_SIZE 100

struct node {
  public:
    int data;
    node *next;
    node(){
       data = -1;
       next = NULL;
    }
};

class linkedlist{
 public:
  node * root;
  linkedlist(){
    root = NULL;
  }
  void Insert(int);
  void Print();
  node* reverse();
  node* rec_reverse(node*, node*);
  node* rec_reverse(node*);
};

void linkedlist::Insert(int value){
    node *nn = new node();
    nn->data = value;
    node *temp;

    if(!root) { root = nn; }
    else{
       temp = root;
       while(temp->next){ temp = temp->next; }
       temp->next = nn;
    }
    return;
}

void linkedlist::Print(){
   node *temp = root;
   while(temp){
     std::cout << "Data : " << temp->data << std::endl;
     temp = temp->next;
   }
   std::cout << std::endl;
}


node* linkedlist::reverse(){
   node *current = root, *prev = NULL, *temp;
   if(current == NULL || current->next == NULL){
       return current;
   }

   while(current){
      temp    = current->next;
      current->next = prev;
      prev    = current;
      current = temp;
   }
   return prev;
}

node* linkedlist::rec_reverse(node *prev, node *curr){
   if(curr == NULL){
       return prev;
   }
   node *temp = curr->next;
   curr->next = prev;
   return rec_reverse(curr, temp);
}

node* linkedlist::rec_reverse(node *curr){
    if(curr == NULL || curr->next == NULL){
        return curr;
    }

    node* new_root = rec_reverse(curr->next);
    curr->next->next = curr;
    curr->next = NULL;
    return new_root;
}

int main(){
   linkedlist *ll = new linkedlist();

   int num;
   std::cin >> num;
   while(num!=-1){
      ll->Insert(num);
      std::cin >> num;
   }
   ll->Print();
   ll->root = ll->reverse();
   ll->Print();
   ll->root = ll->rec_reverse(NULL, ll->root);
   ll->Print();
   ll->root = ll->rec_reverse(ll->root);
   ll->Print();

   while(1){ continue; }
}
