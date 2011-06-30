/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : chocolate.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Monday 27 June 2011 06:02:08 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <cstdio>
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

typedef unsigned long long ull;
typedef long long ll;

int main(){
    ll N, A;
    int bit_c, bit_l;
    bool flag;
 
    scanf("%lld",&N);
    for(ll i=0; i<N; i++){
       scanf("%lld",&A);
       if( (A & A-1) == 0){
          printf("%lld 0\n",A);
       }
       else{
          flag = true;
          bit_c = 0;
          while(A != 0){
             bit_c++;
             if(flag && A%2 == 1) { 
                bit_l = bit_c;
                flag = false;
             }
             A = A >> 1;
          }
          printf("%.0f %d\n",pow(2,bit_c),bit_c+1-bit_l);
       }
    }
}
