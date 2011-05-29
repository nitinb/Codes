/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : delete_right_node.cpp

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
  void delete_right_node();
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

/*
 * Delete nodes which have a greater value on right side
 *   Method1: 
 *    Visit every node and check for right node's value.. 
 *    Delete that node if right node's value > current node value
 *                   else  move current ptr to right
 *     Either way we are moving one ptr to right so O(n)
 * 
 *   Method2:
 *    Reverse the linkedlist
 *    Maintain a currMax of list..
 *     if current node value < currMax delete that node
 *     else currMax is current node's value
 *    Finally, Reverse the linkedlist again
 */
void linkedlist::delete_right_node(){
   node *temp = root, *prev = NULL;
   
   while(temp && temp->next){
      if(temp->next->data > temp->data){  // delete temp;
         node *_t = temp;      
         if(prev == NULL){root = temp->next; }
         else { prev->next = temp->next; }
         temp = temp->next;         
         free(_t);
      }else{
          prev = temp;
          temp = temp->next;
      }
   }
   return;
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
   ll->delete_right_node();
   ll->Print();
      
   while(1){ continue; }
}
