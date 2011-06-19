/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : FiboSum.cpp

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
#define MAX 1000000000

long long int fib(long long int m, long long int n){
   if(m <= 0 ) return 0;
   if(m == 1 ) return 1;

   long long int x = fib(m-1, n) + fib(m-2,n);
   
   return x;
}

int main(){
    int *S;
    S = (int*)malloc(MAX*sizeof(int));    
    
    S[0]=0, S[1]=1;
    for(int i=2; i<MAX; i++){
        S[i]=S[i-1]+S[i-2];
    }
    
    printf("inputs\n");
    long long int N, M;
    int num_test_cases;   
    for(int i = 0; i < num_test_cases; i++){
            scanf("%lld %lld",&N,&M);
    } 
    while(1){continue;}
}
