/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : tdk_primes.cpp

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
//86028121
int M = 86028122;

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

int main(){
    int limit = int(ceil(sqrt(M)));
    int* ARR = (int*)malloc(limit*sizeof(int));
    int count_d = store_divisors(ARR, limit);
    
    long long int _t, k, size=(M+2)/2, count_p, index;
    std::vector<bool> flag(size);

    for(k = 1; k < count_d; k++){
        if(ARR[k] > sqrt(M)) { break; }

        long long int i = 2;
        while(1){
            _t = i*ARR[k];
            if(_t%2 == 0){ i++; }
            else{
                index = (_t-1)/2;
                if(index > size){ break; }
                else{ flag[index] = true; i++; }
            }
        }
    }
    
    long long int num_test_cases, NUM;
    scanf("%lld",&num_test_cases);
    for(int y = 0; y < num_test_cases; y++){
        scanf("%lld",&NUM); count_p=0;
        
        if(NUM==1){ printf("2\n"); }
        else{ NUM-=1;
           for(long long int x=1; x<size; x++){
                if(flag[x] == false ){  //limit+x > 1 && limit+x < M
                   count_p++;
                   if(count_p == NUM) { printf("%lld\n",2*x+1); break; }
                }
           }
        }
    }
   //while(1){ continue; }
}

