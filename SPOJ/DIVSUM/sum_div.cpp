/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : sum_div.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Friday 24 June 2011 08:39:13 PM IST

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
    long long unsigned int max = 1;
    int final = int(ceil(sqrt(num))), i=2;
    while(i<=final){
        if(num%i == 0){
            int q = num/i; //additional Check
            if(q<i) break;
            max += i +q;
        } i++;
    }
    return max;
}

int main(){
    long long int num_test_cases, n, _ret;

    std::cin >> num_test_cases;
    for(long long int i=0; i<num_test_cases; i++){
       std::cin >> n;
       
       _ret = do_the_deed(n);
       printf("%lld\n",_ret);
    }
}
