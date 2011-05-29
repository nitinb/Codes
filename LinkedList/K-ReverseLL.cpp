/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : K-ReverseLL.cpp

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
  void kreverse(int);
  node* rec_kreverse(node*, int);
};

void linkedlist::Insert(int value){
    node *nn = new node();
    nn->data = value;
    node *current;
    
    if(!root) { root = nn; }
    else{
       current = root;
       while(current->next){ current = current->next; }
       current->next = nn;
    }
    return;
}

void linkedlist::Print(){
   node *current = root;
   while(current){
     std::cout << "Data : " << current->data << std::endl;
     current = current->next; 
   }
   std::cout << std::endl;
}

void linkedlist::kreverse(int k){
   node *current = root; 
   if(!(current && current->next) || k <= 1) return;
   
   node *prev, *next, *tail, *plink;
   root = NULL;
   while(1){
      int count = k; tail = current; prev = NULL;
      while(current && count > 0){
         next = current->next;
         current->next = prev;
         prev = current; current = next; count--;                    
      }
      if(root == NULL){ root = prev; }
      else{ plink->next = prev;}
      plink = tail;
      if(current == NULL) break;
   }
}

node* linkedlist::rec_kreverse(node *temp, int k){
   int count = k;
   node *prev = NULL, *next, *current = temp;
   
   while(current && count > 0){
      next = current->next;
      current->next = prev;
      prev = current; current = next; count--;                    
   }
   if(current != NULL){
      temp->next = rec_kreverse(current, k);
   }
   return prev;
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
   ll->kreverse(3);
   ll->Print();
   ll->root = ll->rec_kreverse(ll->root,3);   
   ll->Print();
               
   while(1){ continue; }
}
