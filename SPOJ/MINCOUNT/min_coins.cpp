/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : min_coins.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Friday 01 July 2011 06:07:10 PM IST

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

#define MAX_SIZE 200
#define DEBUG 0

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int num_test_cases;
    ull n, oup;
    
    scanf("%d",&num_test_cases);
    for(int x = 0; x < num_test_cases; x++){
        scanf("%llu",&n);
        if( n <= 1){
           oup = 0;
        }        
        else if(n%2 == 0){
           oup = 1 + ((n-2)/2)*(n/2);
        }
        else{
           oup = 1 + ((n-1)/2)*((n-1)/2);
        }
        printf("%llu\n",oup);
    }
}
