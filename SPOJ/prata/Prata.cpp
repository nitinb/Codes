/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : Prata.cpp

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

struct cook {
  public:
     int wait_time_factor;
     int num_prata;
     int next_time;
     cook(){
        num_prata = 0;
     }     
};

class compare {
   public:
      bool operator() (cook *a, cook *b){
         return a->next_time > b->next_time ? true : false;
      }
};

int main(){
    int num_test_cases, num_prata, num_cooks;
    
    std::cin >> num_test_cases; // num of test cases
    
    for(int i = 0; i < num_test_cases; i++){
       std::priority_queue<cook*, std::vector<cook*>, compare> heap_ready_pratas;
       std::cin >> num_prata;   // num of pratas
       std::cin >> num_cooks;
       for(int j = 0; j < num_cooks; j++){ // rank of cooks
          cook *n = new cook();
          std::cin >> n->wait_time_factor;
          n->next_time = n->wait_time_factor;
          heap_ready_pratas.push(n);
       }
       
       cook *ready_cook;       
       while(1){
           /*
            * parata is ready, delete that node from heap
            *  decrease the total num_prata by 1
            *   insert a new node in heap with new next_time
            */
           ready_cook = heap_ready_pratas.top();
           ready_cook->num_prata++;           
           num_prata --;           
           if(num_prata == 0) break;
           heap_ready_pratas.pop();           
           ready_cook->next_time+=(ready_cook->num_prata+1)*ready_cook->wait_time_factor;
           heap_ready_pratas.push(ready_cook);           
       }
       std::cout << ready_cook->next_time << std::endl;
//       std::cout << "cook identity " << ready_cook->num_prata << " " << ready_cook->wait_time_factor << std::endl;
    }
}


