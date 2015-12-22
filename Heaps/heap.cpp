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

class heap{
 public:
  int data[MAX_SIZE];
  int curr_size;
     heap(){
        curr_size = 0;
     }
  void insert(int);
  void deleteMin();
//  void decreaseKey();
//  void merge();   // @THINK
  void HeapSort();
  int top();
  int size();
};


void heap::insert(int value){
   data[curr_size] = value;
   int i = curr_size;
   curr_size++;

   int parent_position = (i - 1) / 2;
   while(i > 0 && (data[i] < data[parent_position])){
       data[i]       = data[i] + data[parent_position];
       data[parent_position] = data[i] - data[parent_position];
       data[i]       = data[i] - data[parent_position];
       i = parent_position;
       parent_position = (i - 1) / 2;
   }
}

int heap::top(){
  return curr_size > 0 ? data[0] : -1;
}

int heap::size(){
  return curr_size;
}

void heap::deleteMin(){
   if(curr_size <= 0) return;

   this->curr_size--;
   data[0] = data[this->curr_size];

   int i = 0, child_position;
   while(2 * i + 1 < this->curr_size){
       child_position = 2 * i + 1;
       if(2 * i + 2 < this->curr_size){
           child_position = data[2 * i + 1] <= data[2 * i + 2] ? 2 * i + 1 : 2 * i + 2;
       }

      if(data[i] > data[child_position]){
           data[i]    = data[i] + data[child_position];
           data[child_position] = data[i] - data[child_position];
           data[i]    = data[i] - data[child_position];
           i = child_position;
           continue;
      }
      return;
   }
}

void heap::HeapSort(){
  while(curr_size > 0){
     std::cout << top() << std::endl;
     deleteMin();
  }
}

int main(){
   heap* h  = new heap();

   std::cout << "min element: " << h->top() << std::endl;
   h->insert(10);
   std::cout << "min element: " << h->top() << std::endl;
   h->insert(19);
   std::cout << "min element: " << h->top() << std::endl;
   h->insert(3);
   std::cout << "min element: " << h->top() << std::endl;
   h->deleteMin();
   std::cout << "min element after delete: " << h->top() << std::endl;
   h->insert(11);
   std::cout << "min element: " << h->top() << std::endl;
   h->deleteMin();
   std::cout << "min element after delete: " << h->top() << std::endl;
   h->insert(1);
   std::cout << "min element here: " << h->top() << std::endl;
   h->deleteMin();
   std::cout << "min element after delete: " << h->top() << std::endl;
   h->deleteMin();
   std::cout << "min element after delete: " << h->top() << std::endl;
   h->deleteMin();
   std::cout << "min element after delete: " << h->top() << std::endl;
   std::cout << "size: " << h->size() << std::endl;
   h->deleteMin();
   std::cout << "min element after delete: " << h->top() << std::endl;
   std::cout << "size: " << h->size() << std::endl;

   h->insert(11);
   h->insert(17);
   h->insert(31);
   h->insert(8);
   h->insert(99);
   h->insert(1);
   h->HeapSort();

   while(1){ continue; }
}
