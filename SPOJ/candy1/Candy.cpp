/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : Candy.cpp

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

/*STL *algorithm* */
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 0
#define MAX_SIZE 10000

long long int calc_moves(int *a, int n, long long int m){
     long long int moves=0;
     for(int i=0; i<n; i++){
         if(a[i] < m){
             moves += m-a[i];
         }
     }
     return moves;
}

// **************************************************
int main(){
    int A;
    long long int m, M, _ret;
    while(1){
       scanf("%d",&A);
       if(A == -1) break;
       if(A == 0)  continue;
       m = 0;
       int Arr[A];
       for(int i = 0; i < A; i++){ scanf("%d",&Arr[i]); m += Arr[i]; }
       M = m/A;
       if(M*A != m){
          printf("-1\n");
       }
       else{
          _ret = calc_moves(Arr, A, M);
          printf("%lld\n",_ret);
       }
    }
//    while(1) { continue; }
}
