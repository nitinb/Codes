/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : XORLinkedList.cpp

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
    node *npx;
    node(){
       data = -1;
       npx = NULL;
    } 
};

class linkedlist{
 public:
  node * root;
  linkedlist(){
    root = NULL;
  }
  node* get_next(node*, node*);
  void Insert(int);
  void Print();
  void print_reverse();
};

node* linkedlist::get_next(node* current, node* prev){
    return (node*)((int)current->npx ^ (int)prev);
}

/**
 * XOR LINKED LIST
 *  nextPtr(npx) will have XoR of prev and next
 */
void linkedlist::Insert(int value){
    node *nn = new node();
    nn->data = value;

    if(root == NULL){
        root = nn;
        return;
    }

    node *iter = root, *prev = NULL, *temp;
    while(get_next(iter, prev) != NULL){
        temp = iter;
        iter = get_next(iter, prev); 
        prev = temp; 
    }

    iter->npx = (node*)((int)prev ^ (int)nn);
    nn->npx   = iter;
    return;
}

void linkedlist::Print(){
   node *iter = root, *prev = NULL, *temp;
   
   std::cout << "LL=> ";
   while(iter != NULL){
     std::cout << iter->data << "  ";
     temp = iter;
     iter = get_next(iter, prev); 
     prev = temp;
   }
   std::cout << std::endl;
}

void linkedlist::print_reverse(){
   node *iter = root, *prev = NULL, *temp;

   while(iter != NULL){
     temp = iter;
     iter = get_next(iter, prev); 
     prev = temp;
   }

   // prev will have the last ptr
   //  && iter will be NULL [;)]
   std::cout << "Reversed LL=> ";
   while(prev != NULL){
     std::cout << prev->data << "  ";
     temp = prev;
     prev = get_next(prev, iter); 
     iter = temp;
   }
   std::cout << std::endl;
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
   ll->print_reverse();
   while(1){ continue; }
}
