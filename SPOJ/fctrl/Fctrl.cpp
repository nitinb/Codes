/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : Fctrl.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Wednesday 22 June 2011 05:08:28 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cstdio>

/*STL *algorithm* */
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 0


int main(){
    
    int num_test_cases;  // input variables
    long long unsigned int num, ans;
    
    char ch; // temp
 
    std::cin >> num_test_cases; // num of test cases
    for(int i = 0; i < num_test_cases; i++){
       scanf("%lld",&num);
       if(DEBUG) std::cout << num << std::endl;
       ans = 0;
       for(long long unsigned int j = 5; j <= num; j *= 5) {ans += num/j; }
       std::cout << ans << std::endl;
    }
//    while(1){ ch = getchar(); }
}
