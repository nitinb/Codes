/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : prime_or_not.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Friday 01 July 2011 07:04:38 PM IST

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
typedef long long ll;
typedef unsigned long long ull;

ull M = 4611686018427387904; // 2^63-1
//18446744073709551616 // 2^64
//9223372036854775808  // 2^63
//4294967296           // 2^32

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
    int num_test_cases;
    ull num, limit, mult, i;
    limit = 2147483648ULL; // ceil(sqrt(M))
    bool flag[limit];

    for(i = 2; i < limit; i++){
        mult = 2;
        while(mult*i < limit){
           if(DEBUG) printf("%lld ",mult);
           if(DEBUG) printf("%lld ",i);
           if(DEBUG) printf("%lld\n",mult*i);
           flag[mult*i] = true;
           mult++;
        }
        if(DEBUG) printf("am out of while loop\n");    
    }
    printf("am done with processing\n");    
        
    scanf("%d",&num_test_cases); // num of test cases
    for(int z = 0; z < num_test_cases; z++){
        scanf("%lld",&num);
        if(flag[num] == false) printf("YES\n");
        else printf("NO\n");
    }
}
