/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : euler_q.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Monday 27 June 2011 05:02:42 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iomanip>

/*STL *algorithm* */
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define MAX_SIZE 1000000
#define DEBUG 0

typedef long long ll;
typedef unsigned long long ull;

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
    int limit = int(ceil(sqrt(MAX_SIZE)));
    int *ARR  = (int*)malloc(limit*sizeof(int));
    int count_d = store_divisors(ARR, limit);
    
    ll num, num_test_cases;
    scanf("%lld",&num_test_cases);
    for(ll x=0; x<num_test_cases; x++){
        scanf("%lld",&num);
        if(num <= 2){
            printf("1\n");
        }
        else{
            ll q = num;
            int final = int(ceil(sqrt(num)));            
            int i = 0; 
            bool flag = true;
            while(i < count_d && ARR[i] <= final){
                if(num%ARR[i] == 0){
                   num /= ARR[i];
                   if(flag){
                      q = (q/ARR[i])*(ARR[i]-1);
                      flag = false;
                   }
                }
                else{
                   flag = true;
                   i++;
                }
            }
            if(num != 1){ // some prime factor
                   q = (q/num)*(num-1);
            }
            printf("%lld\n",q);            
        }
    }
}
