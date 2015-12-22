/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : max_env.cpp

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
#include <cstdio>
#include <cmath>

/*STL *algorithm* */
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 0
#define MAX_SIZE 500

typedef long long ll;
typedef unsigned long long ull;

#define max(a,b) a>b ?a : b;
#define min(a,b) a>b ?b : a;

int main(){
    int num_test_cases, a, b;
    ll peri = 0;

    scanf("%d",&num_test_cases);
    for(int x=1; x<=num_test_cases; x++){
       scanf("%d %d",&a, &b);
       if(x == 1){
           peri = abs(a-b);
       }
       else if(x == num_test_cases && x%2 == 1){
           peri += abs(a-b);
       }
       else if(x == num_test_cases && x%2 == 0){
           peri += a+b;
       }       
       else if(x%2 == 1){
            if(a-2*b>b-2*a){
                peri += a-2*b;
            }
            else{
                peri += b-2*a; 
            } 
       }
       else{
            if(a+2*b>b+2*a){
                peri += a+2*b;
            }
            else{
                peri += b+2*a; 
            }
       }
    }
    printf("%lld\n",peri);
}
