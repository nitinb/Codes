/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : n-step.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Monday 27 June 2011 03:05:54 PM IST

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
    long long int N, A, B, oup1, oup2;
    
    scanf("%lld",&N);
    for(long long int i=0; i<N; i++){
       scanf("%lld %lld",&A, &B);

       if(A%2 == 0){
              oup1 = 2*A;
//              oup2 = 2*A-2;
       }else{
              oup1 = 2*A-1;
//              oup2 = 2*A-3;             
       }

       if(B%2 == 0){
//              oup1 = 2*B;
              oup2 = 2*B+2;              
       }else{
//              oup1 = 2*B-1;
              oup2 = 2*B+1;             
       }
       
       if( (oup1 == oup2) || (oup1-2 >=0 && oup1-2 == oup2) ){
               printf("%lld\n",oup2);
       }
       else if( (oup2-2 >=0 && oup2-2 == oup1) ){
               printf("%lld\n",oup1);
       }
       else{
               printf("No Number\n");
       }
    }
}
