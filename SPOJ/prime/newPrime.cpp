/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : newPrime.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Thursday 23 June 2011 11:04:37 AM IST

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
long long int M = 1000000000;

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
    
    long long int num_test_cases, initial_num, final_num, _t, size, i;
    
    scanf("%lld",&num_test_cases); // num of test cases
    for(int z = 0; z < num_test_cases; z++){
        scanf("%lld %lld",&initial_num,&final_num);      
        size = final_num-initial_num+1;
        bool flag[size];
    
        for(long long int x=0; x<size; x++) { flag[x]=true; }

        for(int k = 0; k < count_d; k++){
            if(ARR[k] > sqrt(final_num)) { break; }
            
            i = initial_num/ARR[k];
            i = i >= 2 ? i : 2; // check otherwise it will cut off prime
            while(1){
               _t = i*ARR[k];
               //std::cout << "pdt=>" << _t << std::endl;               
               if(_t > final_num){ break; }
               else if(_t < initial_num){ i++; }
               else if(_t >= initial_num && _t <= final_num){ flag[_t-initial_num] = false; i++; }
            }
        }
        for(long long int x=0; x<size; x++) {
           if( (initial_num+x > 1) && (flag[x]==true) ){ printf("%lld\n",initial_num+x); }
        }
        printf("\n");
    }
 //   while(1){ continue; }
}
