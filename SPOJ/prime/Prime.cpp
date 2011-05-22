/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : Prime.cpp

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
#define MAX_SIZE 1000000000

/* @PreProcessing
 * Store all the prime numbers upto limit ie. sqrt(MAX_SIZE)
 * sqrt(MAX_SIZE) because these are also the divisor
 *    which will be used to check if a number is prime or not
 */
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

int gen_primes(int n, int m, int *a, int *primes_arr, int count_d){
   int limit = int(ceil(sqrt(MAX_SIZE)));
   int _size = 0;
   
   // We already have primes for this in *a
   // just check the range [n, m]   
   if(m <= limit){
     for(int i = 0; i < count_d; i++){
        if(a[i] >= n && a[i] <= m) primes_arr[_size++] = a[i];
        if(a[i] > m) break;
     }
     return _size;
   }
   
   // check for all numbers in range [n,m]
   // whether they are prime or not
   int k;
   for(int j = n; j <= m; j++){
     for(k = 0; k < count_d; k++){
        if(j%a[k] == 0) break;
        if(a[k] > sqrt(j)) { k = count_d; break; }
     }
     if(k == count_d){ primes_arr[_size++] = j; }     
   }
   return _size;
}


int main(){
    int num_test_cases, initial_num, final_num;
    int *ARR, *primes_arr;
    
    int limit = int(ceil(sqrt(MAX_SIZE)));
    ARR       = (int*)malloc(limit*sizeof(int));
    int count_d = store_divisors(ARR, limit);
//    std::cout << count_d << "limit: " << limit << std::endl;
    
    std::cin >> num_test_cases; // num of test cases   
    for(int i = 0; i < num_test_cases; i++){
       std::cin >> initial_num >> final_num;
//       std::cout << initial_num << final_num << std::endl;    
   
       primes_arr  = (int*)malloc((final_num - initial_num + 1)*sizeof(int));
//       std::cout << "mem allocated -- prime generation " << std::endl;
       int count_p = gen_primes(initial_num, final_num, ARR, primes_arr, count_d);
//       std::cout << "prime generated " << std::endl;       
       for(int j = 0; j < count_p; j++){
          std::cout << primes_arr[j] << std::endl;
       }
       std::cout << std::endl;
    }
//    while(1) { continue; }
}
