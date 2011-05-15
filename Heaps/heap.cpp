/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : heap.cpp

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
   while(1){
       if(data[i] < data[(i-1)/2]){ // parent node smaller than child
           data[i]       = data[i] + data[(i-1)/2];   // swap the values
           data[(i-1)/2] = data[i] - data[(i-1)/2];
           data[i]       = data[i] - data[(i-1)/2];
           i = (i-1)/2;
       }
       else{
          break;
       }
   }
   curr_size++;
   return;
}

int heap::top(){
  return curr_size > 0 ? data[0] : -1;
}

int heap::size(){
  return curr_size;
}

void heap::deleteMin(){
   if(curr_size <= 0) return;
   
   data[0] = data[curr_size-1];
   curr_size--;
   
   int i = 0;
   bool flag = false;
   while(!flag){
      flag = true;
      int _pos = data[2*i+1] <= data[2*i+2] ? 2*i+1 : 2*i+2;
        
      if(data[i] > data[_pos]){
           data[i]    = data[i] + data[_pos];   // swap the values
           data[_pos] = data[i] - data[_pos];
           data[i]    = data[i] - data[_pos];
           flag = false;
      }
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
   std::cout << "min element: " << h->top() << std::endl;   
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

/*
http://en.wikipedia.org/wiki/Selection_algorithm
http://en.wikipedia.org/wiki/Prim%27s_algorithm
http://en.wikipedia.org/wiki/Dijkstra%27s_algorithm

BinomialHeap
BinaryHeap
 */
