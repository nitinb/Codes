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
    node *random;
    node(){
       data = -1;
       next = NULL;
       random = NULL;
    }
};

class linkedlist{
 public:
  node * root;
  linkedlist(){
    root = NULL;
  }
  node* Insert(int);
  void Print();
  linkedlist* newCopyList();
};

linkedlist* linkedlist::newCopyList() {
    linkedlist *nll = new linkedlist();
    node *temp = this->root;
    while (temp != NULL) {
        node* nn = nll->Insert(-2 * temp->data);
        temp = temp->next;
    }
    std::cout << "prepared list" << std::endl;

    node* temp1 = this->root; 
    node* temp2 = nll->root; 
    while (temp1 != NULL) {
        node* next_temp1 = temp1->next;
        node* next_temp2 = temp2->next;
        temp1->next = temp2;
        temp2->next = next_temp1;
        temp1 = next_temp1;
        temp2 = next_temp2;
    }
    std::cout << "pointer manipulation done.. " << std::endl;

    temp1 = this->root; 
    while (temp1 != NULL && temp1->next != NULL) {
        node* next_temp = temp1->next;
        if (temp1->random != NULL) {
             temp1->next->random = temp1->random->next;
        }
        temp1->next = temp1->next->next;
        next_temp->next = temp1->next ? temp1->next->next : NULL;
        temp1 = temp1->next;
    }
    std::cout << "lists restored .. " << std::endl;

    return nll;
}

void linkedlist::Print() {
    node *temp = root;
    std::cout << "LL=> ";
    while(temp){
        int rand_data = temp->random ? temp->random->data : -1; 
        std::cout << temp->data << "(R: " << rand_data << ") ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

node* linkedlist::Insert(int value) {
    node *nn = new node();
    nn->data = value;

    if(root == NULL){
        root = nn;
        return nn;
    }

    node *temp = root;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = nn;

    return nn;
}

int main() {
   linkedlist *ll = new linkedlist();
   int num;

   std::cin >> num;
   while(num >= 0) {
       ll->Insert(num);
       std::cin >> num;
   }
   ll->root->random = ll->root->next->next;
   ll->root->next->random = ll->root->next->next->next;
   ll->Print();
   std::cout << "prepared a basic list... " << std::endl;

   linkedlist *nll = ll->newCopyList();
   nll->Print();
}
