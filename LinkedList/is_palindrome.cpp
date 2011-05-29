/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : is_palindrome.cpp

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
  bool is_palindrome(node*);
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

/*
 * a => left ptr
 * b => right ptr
 */
bool linkedlist::is_palindrome(node *b){
   static node* a = root;
   if(!b) return true;
   
   if( is_palindrome(b->next) == false){ return false; }

   bool _var = (a->data == b->data);
   a = a->next;
   return _var;
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
   bool _ret = ll->is_palindrome(ll->root);
   std::cout << "ret value: " << _ret << std::endl;
   
   while(1){ continue; }
}
