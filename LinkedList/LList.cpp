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
  void Print();
  void CreateLoop();
  void DetectAndRemoveLoop();
  void RemoveLoop(node *temp);
};

void linkedlist::Insert(int value){
    node *nn = new node();
    nn->data = value;

    if(root == NULL){
        root = nn;
        return;
    }

    node *temp = root;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = nn;

    return;
}

void linkedlist::Print(){
    node *temp = root;
    std::cout << "LL=> ";
    while(temp){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void linkedlist::CreateLoop(){
   node *temp = root;
   while(temp->next){
       temp = temp->next;
   }
   temp->next = root->next->next;
}

void linkedlist::DetectAndRemoveLoop(){
   node *temp1 = root, *temp2 = root;

   while(1){
     if(temp1 == NULL){
         std::cout << "NULL ptr@1 found " << std::endl;
         return;
     }
     temp1 = temp1->next;

     if(temp2 == NULL){
         std::cout << "NULL ptr@2 found " << std::endl;
         return;
     }
     temp2 = temp2->next;

     if(temp2 == NULL){
         std::cout << "NULL ptr@3 found " << std::endl;
         return;
     }
     temp2 = temp2->next;

     if(temp1 == temp2){
         std::cout << "Loop Detected" << std::endl;
         RemoveLoop(temp1);
         return;
     }
   }
}

void linkedlist::RemoveLoop(node *temp){
    int count = 1;

    node *iter = temp->next;
    while(iter != temp){
        iter = iter->next;
        count++;
    }

    node *start1 = this->root, *start2 = this->root;
    while(count-- != 0){
        start1 = start1->next;
    }

    while(start2->next != start1->next){
        start1 = start1->next;
        start2 = start2->next;
    }

    if(DEBUG){
        std::cout << start2->next->data << " " << start1->next->data << std::endl;
    }

    std::cout << "Loop Removed" << std::endl;
    start1->next = NULL;
}

void linkedlist::InsertSort(int value){
    node *nn = new node();
    nn->data = value;

    if(root == NULL){
        root = nn;
        return;
    }

    node *temp = root, *prev = NULL;
    while(temp && temp->data < value){
        prev = temp;
        temp = temp->next;
    }

    if(prev == NULL){
        nn->next = temp;
        root = nn;
        return;
    }

    prev->next = nn;
    nn->next = temp;
    return;
}

int main(){
   linkedlist *ll = new linkedlist();

   int num;
   std::cin >> num;
   while(num!=-1){
      ll->InsertSort(num);
      std::cin >> num;
   }
   ll->Print();

   ll->CreateLoop();
   ll->DetectAndRemoveLoop();
   ll->Print();

   while(1){ continue; }
}
