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
  void Insert(int);
  void Print();
  void print_reverse();
};

/*
 * XOR LINKED LIST
 *  nextPtr(npx) will have XoR of prev and next
 */
void linkedlist::Insert(int value){
    node *nn = new node();
    nn->data = value;
    node *temp, *prev, *_t;
    
    if(!root){ root = nn; }
    else{
       temp = root; prev = NULL;
       while( (node*)( (int)temp->npx^(int)prev ) ){
           _t = temp; temp = (node*)( (int)prev^(int)temp->npx ); prev = _t; 
       }
       temp->npx = (node*)((int)prev^(int)nn);
       nn->npx   = temp;
    }
    return;
}

void linkedlist::Print(){
   node *temp = root, *prev = NULL, *_t;
   
   while(temp){
     std::cout << "Data : " << temp->data << std::endl;
     _t = temp; temp = (node*)( (int)prev^(int)temp->npx ); prev = _t;
   }
}

void linkedlist::print_reverse(){
   node *temp = root, *prev = NULL, *_t;

   while(temp){
     _t = temp; temp = (node*)( (int)prev^(int)temp->npx ); prev = _t;
   }
   // prev will have the last ptr
   //  && temp will be NULL [;)]
   while(prev){
     std::cout << "Rev-Data : " << prev->data << std::endl;
     _t = prev; prev = (node*)( (int)temp^(int)prev->npx ); temp = _t;     
   }
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
   std::cout << "printing done " << std::endl;   
   ll->print_reverse();
   std::cout << "rev printing done " << std::endl;   
   while(1){ continue; }
}
