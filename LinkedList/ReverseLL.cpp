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
  void reverse();
  void rec_reverse(node*, node*);
  void rec_reverse(node*);  
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


void linkedlist::reverse(){
   node *current = root, *prev = NULL, *temp;
   if(!(current && current->next)) return; // 0 or 1 length linked list
   
   prev = current; current = current->next; prev->next = NULL;
   while(current){
      temp    = current->next;
      current->next = prev;
      prev    = current;
      current = temp;
   }
   root = prev;
}

void linkedlist::rec_reverse(node *prev, node *curr){
   if(curr == NULL){ root = prev; return; }
   node *temp = curr->next;
   curr->next = prev;
   rec_reverse(curr,temp);
}

void linkedlist::rec_reverse(node *curr){
    node *first, *rest;
    if(curr == NULL) return; 
    
    first = curr;
    rest  = curr->next;
    if(rest == NULL) { root = first; return; }
    
    rec_reverse(rest);
    first->next->next = first;
    first->next = NULL;
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
   ll->reverse();
   ll->Print();
   ll->rec_reverse(NULL, ll->root);
   ll->Print();
   ll->rec_reverse(ll->root);
   ll->Print();
            
   while(1){ continue; }
}
