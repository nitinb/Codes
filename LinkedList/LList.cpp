/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : LList.cpp

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
  void InsertSort(int);
  void CreateLoop();
  void Print();
  void DetectAndRemoveLoop();
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

void linkedlist::CreateLoop(){
   node *temp = root; // assuming there are few nodes in ll
   while(temp->next){ temp = temp->next; }
   temp->next = root->next->next;
}

void linkedlist::DetectAndRemoveLoop(){
   node *temp1, *temp2;
   temp1 = root; temp2 = root;
   while(1){
     if(temp1 == NULL){ std::cout << "NULL ptr@1 found " << std::endl; return; }
     else temp1 = temp1->next;
     
     if(temp2 == NULL){ std::cout << "NULL ptr@2 found " << std::endl; return; }
     else temp2 = temp2->next;
     
     if(temp2 == NULL){ std::cout << "NULL ptr@3 found " << std::endl; return; }
     else temp2 = temp2->next;
     
     if(temp1 == temp2){
         std::cout << "Loop Detected at " << temp1->data << std::endl; 
         return;      
     }
   }
}

void linkedlist::InsertSort(int value){
    node *nn = new node();
    nn->data = value;
    node *temp, *prev;
    
    if(!root) { root = nn; }
    else{
       temp = root; prev = NULL;
       while(temp && temp->data < value){ prev = temp; temp = temp->next; }
       if(prev == NULL){ nn->next = temp; root = nn; }
       else{
          prev->next = nn;
          nn->next   = temp;
       }
    }
    return;
}

int main(){
   linkedlist *ll = new linkedlist(); 
    
   int num;
   std::cin >> num;
   while(num!=-1){
      ll->InsertSort(num);
      ll->Print();
      std::cin >> num;
   }
   //ll->Print();
   /*
   ll->CreateLoop();
   ll->Print(); // while(1) if loop is present in ll
   ll->DetectAndRemoveLoop();
   */
    
   while(1){ continue; }
}
