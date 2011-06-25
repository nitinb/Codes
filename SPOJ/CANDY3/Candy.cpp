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

// **************************************************
int main(){
    long long int m, M, N, A, inp;
    
    scanf("%lld",&N);
    for(long long int i=0; i<N; i++){
       getchar(); getchar(); //read \n
       scanf("%lld",&A);        
       if(A == 0){ printf("YES\n");  continue; }
       m = 0;
       
       for(int i = 0; i < A; i++){ scanf("%lld",&inp); m += inp; }
       M = m/A;
       if(M*A != m){
          printf("NO\n");
       }
       else{
          printf("YES\n");
       }
    }
    while(1) { continue; }
}
