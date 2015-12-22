/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : sum_seq.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Wednesday 29 June 2011 07:11:11 PM IST

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
#define MAX_SIZE 1000000000

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int num_test_cases;
    ll A;
    double oup1, oup2;
 
    scanf("%d",&num_test_cases);
    for(int i = 0; i < num_test_cases; i++){
        scanf("%lld",&A);
        if(A == 1){
            oup1 = 2.0/3;
        }
        else{
            oup1 = 1.0/(2*(A+1));
            oup2 = 1.0/(2*(A+2));
            oup1 = 3.0/4 - oup1 + oup2;
        }
        //printf("%.11f\n",oup1);
	std::cout<< std::setprecision(11) << std::fixed << oup1 <<std::endl;
    }
}
