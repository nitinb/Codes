/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : delete_ll.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Friday 13 May 2011 07:58:00 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <cmath>
#include <cstdlib>

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
  void delete_ll(node*);
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
}


void linkedlist::delete_ll(node *temp){
    node *_t;
    while(temp != NULL){
       _t   = temp;
       temp = temp->next;
       delete _t;
    }
    root = NULL;
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
   ll->delete_ll(ll->root);
   ll->Print();
      
   while(1){ continue; }
}
