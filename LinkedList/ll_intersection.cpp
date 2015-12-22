#include <iostream>
#include <cmath>

/*STL *algorithm* */
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 0
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
   std::cout << "LL=> ";
   while(temp){
     std::cout << " " << temp->data;
     temp = temp->next;
   }
   std::cout << std::endl;
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

linkedlist* remove_common_elements(linkedlist *ll1, linkedlist *ll2){

    if(ll2 == NULL){
        return ll1;
    }

    if(ll1 == NULL){
        return ll2;
    }

    node *start1 = ll1->root, *start2 = ll2->root;
    node *prev1 = NULL, *prev2 = NULL;

    while(start1 != NULL && start2 != NULL){
        if(DEBUG){
            std::cout << "Debug: " << start1->data << " " << start2->data;
            ll1->Print();
        }

        if(start1->data == start2->data){
            prev2 = start2;
            start2 = start2->next;
            continue;
        }

        if(start1->data > start2->data){
            node *temp = start2->next;
            if(prev2 != NULL){
                prev2->next = temp;
            }

            if(prev1 != NULL){
                prev1->next = start2;
            }
            else{
                ll1->root = start2;
            }
            start2->next = start1;
            prev1 = start2;
            start2 = temp;
        }

        if(start1->data < start2->data){
            prev1 = start1;
            start1 = start1->next;
        }
    }

    if(start1 == NULL){
        prev1->next = start2;
        prev2->next = NULL;
    }

    return ll1;
}

int main(){
    linkedlist *ll1 = new linkedlist();
    linkedlist *ll2 = new linkedlist();
    int num;

    std::cin >> num;
    while(num!=-1){
       ll1->InsertSort(num);
       std::cin >> num;
    }
    ll1->Print();

    std::cin >> num;
    while(num!=-1){
       ll2->InsertSort(num);
       std::cin >> num;
    }
    ll2->Print();

    linkedlist *ll = remove_common_elements(ll1, ll2);
    ll->Print();

    while(1){ continue; }
}
