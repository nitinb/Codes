/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : sum_div.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Monday 27 June 2011 03:29:42 PM IST

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

#define DEBUG 1
#define MAX_SIZE 10000000

int do_the_deed(long long int num){
    unsigned long long int max = 1;
    int final = (int) sqrt(num), i=2;
    while(i<=final){
        if(num%i == 0){
            long long int q = num/i; //additional Check
            if( q!=i)
               max += i + q;
            else
               max += i ;
        } i++;
    }
    return max;
}

int main(){
    long long int num_test_cases, n, _ret;

    std::cin >> num_test_cases;
    for(long long int i=0; i<num_test_cases; i++){
       scanf("%lld",&n);
       if( n == 1)  
         printf("0\n");
       else{
         _ret = do_the_deed(n);
         printf("%lld\n",_ret);
       }
    }
}
