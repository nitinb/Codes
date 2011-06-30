/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : prime_or_not.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Thursday 23 June 2011 08:26:16 PM IST

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

#define M 9223372036854775800;

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
    bool flag[M];
    float num;
            
    scanf("%d",&num_test_cases); // num of test cases
    for(int z = 0; z < num_test_cases; z++){
        scanf("%f",&num);
        if(flag[num] == false) printf("YES\n");
        else printf("NO\n");
/*
        for(ll k = 0; k < count_d; k++){
            if(ARR[k] > sqrt(num)) { break; }
            if(num % ARR[k] == 0) 
        }
*/
    }
}
