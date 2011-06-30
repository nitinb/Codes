/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : sq_free.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Wednesday 29 June 2011 04:57:03 PM IST

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

#define DEBUG 0
#define LIMIT 10000000

typedef long long ll;
typedef unsigned long long ull;

ull MAX_SIZE = 100000000000001;

int main(){
    std::vector<bool> storage(MAX_SIZE);
    std::vector<int>  oup(MAX_SIZE);
   
    ull sq, mult;
    for(int x=2; x<=LIMIT; x++){
       sq = x*x;
       mult = 1;
       while(mult*sq < MAX_SIZE){
           storage[mult*sq] = true;
           mult++;
       }
    }
    int curr=0;
    for(int x=1; x<MAX_SIZE; x++){
       if(storage[x] == true)
         oup[x] = 0;
       else{
         curr++;
         oup[x]=curr;
       }
    }

    int num_test_cases, A, _ret;
    scanf("%d",&num_test_cases);
    for(int i = 0; i < num_test_cases; i++){
        scanf("%d",&A);
        printf("Case %d: ",i+1);

        if(storage[A] == true){ 
           printf("Not Cube Free\n");
           continue;
        }
        printf("%d\n",oup[A]);
    }
}
