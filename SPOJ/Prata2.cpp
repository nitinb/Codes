/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : Prata2.cpp

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
#include <algorithm>

#define DEBUG 1

struct cook {
  public:
     int wait_time_factor;
     int num_prata;
     int next_time;
     cook(){
        num_prata = 0;
     }     
};

bool compare_heap(cook *a, cook *b){
     return a->next_time > b->next_time ? true : false;
}

int main(){
    int num_test_cases, num_prata, num_cooks;
    std::vector<cook*> heap_ready_pratas;
    
    std::cin >> num_test_cases; // num of test cases
    
    for(int i = 0; i < num_test_cases; i++){
       heap_ready_pratas.clear();
       std::cin >> num_prata;   // num of pratas
       std::cin >> num_cooks;
       for(int j = 0; j < num_cooks; j++){ // rank of cooks
          cook *n = new cook();
          std::cin >> n->wait_time_factor;
          n->next_time = n->wait_time_factor;
          heap_ready_pratas.push_back(n);
       }
       
       //Prepare a heap from vector heap_ready_pratas
       make_heap (heap_ready_pratas.begin(), heap_ready_pratas.end(), compare_heap);
       
       cook *ready_cook;
       while(1){
           /*
            * parata is ready, delete that node from heap
            *  decrease the total num_prata by 1
            *   insert a new node in heap with new next_time
            */
           ready_cook = heap_ready_pratas.front();
           ready_cook->num_prata++;           
           num_prata --;           
           if(num_prata == 0) break;
           
           pop_heap (heap_ready_pratas.begin(),heap_ready_pratas.end(), compare_heap); 
           heap_ready_pratas.pop_back();
           
           ready_cook->next_time+=(ready_cook->num_prata+1)*ready_cook->wait_time_factor;
           heap_ready_pratas.push_back(ready_cook);
           push_heap (heap_ready_pratas.begin(),heap_ready_pratas.end(), compare_heap);
       }
       std::cout << ready_cook->next_time << std::endl;
    }
}


