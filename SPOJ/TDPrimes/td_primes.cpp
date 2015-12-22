/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : td_primes.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Thursday 23 June 2011 09:00:37 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cstdio>

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
    long long int _t, k, size=(M-limit)/total_p+1, count_p; //divide in batch-- total 100
    count_p = count_d;
    std::vector<bool> flag(size); 
 
    for(int j=0; j<total_p; j++){
        m = limit+size;

        for(k = 0; k < count_d; k++){
            if(ARR[k] > sqrt(m)) { break; }

            int i = limit/ARR[k];
            i = i >= 2 ? i : 2; // check otherwise it will cut off prime
            while(1){
               _t = i*ARR[k];
               //if(DEBUG) std::cout << _t << std::endl;               
               if(_t > m){ break; }
               else if(_t < limit){ i++; }
               else if(_t >= limit && _t <= m){ flag[_t-limit] = true; i++; }
            }
        }
        for(long long int x=0; x<size; x++){
           if(flag[x] == true){ flag[x] = false; }
           else if( limit+x > 1 && limit+x < M){
             count_p++;
             if(count_p%100 == 1) { printf("%lld\n",limit+x); }
           }
        }
        limit = m;
    }
  //  while(1){ continue; }
}
