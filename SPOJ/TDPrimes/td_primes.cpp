/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : td_primes.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Monday 16 May 2011 06:36:08 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cstdlib>

/*STL *algorithm* */
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 1
int M = 100000000;

int store_divisors(int *a, int limit){
    int _size = 0, k;
    a[_size++] = 2;
    for(int j = 3; j < limit; j+=2){
      for(k = 0; k < _size; k++){
         if(j%a[k] == 0) break;
         if(a[k] > sqrt(j)) {k = _size; break;}
      }
      if(k == _size){ a[_size++] = j; }
    }
    return _size;   
}

void print_a(int *a, int n){
    for(int i=0; i<n; i+=100){ printf("%d\n",a[i]); }
}

int main(){
    int limit = int(ceil(sqrt(M)));
    int* ARR = (int*)malloc(limit*sizeof(int));
    
    int count_d = store_divisors(ARR, limit);   
    print_a(ARR, count_d);
    
    int total_p=100, m;
    int _t, k, size=(M-limit)/total_p; //divide in batch-- total 100
    bool flag[size];
    
    for(int j=0; j<total_p; j++){
        m = limit+size;
        for(int i=0; i<size; i++) { flag[i]=true; }

        //if(DEBUG) std::cout << m(1009900) << "  " << limit(10000) << "  " << size(999900) << std::endl;
        for(k = 0; k < count_d; k++){
            int i = limit/ARR[k];
            std::cout << "startIndex=>" << i << std::endl;
            while(1){
               _t = i*ARR[k];
               std::cout << _t << std::endl;               
               if(_t >= m){ break; }
               else if(_t < limit){ i++; }
               else if(_t >= limit && _t < m){ flag[_t] = false; i++; }
            }
        }
        std::cout << j+1 << " batch completed" << std::endl;
    }
       
    //if(1){
        // std::cout << "got a prime" << std::endl;
      //  if(count_p%100==1){ printf("%d\n",i); }
    //}
    while(1){ continue; }
}
