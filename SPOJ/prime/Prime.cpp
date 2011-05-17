/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : Prime.cpp

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

#define DEBUG 1
#define MAX_SIZE 1000000000

void PreProcessing(int n, int m){
   std::map<int, char> ARR;
   int i = n, limit = sqrt(m)+2;

   ARR[2] = '1';
   do{ if(i%2 != 0) ARR[i++] = '1'; } while(i <= m);
   for(int j = 3; j < limit; j+=2){ ARR[j] = '1'; }
   
   for(int j = 3; j < limit; j+=2){
      for(int k = j*j; k <= m; k+=2*j)
         if( ARR.find(k) != ARR.end() && k % j == 0) ARR.erase(k);
   }
}

void test(){
    std::map<int, char> ARR;
    ARR[2] = '1'; ARR[3] = '1'; ARR[5] = '1'; ARR[7] = '1';
    for(int j = 11; j <= MAX_SIZE; j+=2){
        if(!(j % 2 == 0 || j % 3 == 0 || j % 5 == 0 || j % 7 == 0))
          ARR[j] = '1';
    }     
}

// **************************************************
int main(){
    int num_test_cases, initial_num, final_num;
    std::cin >> num_test_cases; // num of test cases
    
    for(int i = 0; i < num_test_cases; i++){
       std::cin >> initial_num >> final_num;
   //    PreProcessing(initial_num, final_num);
       test();
       std::cout << initial_num << final_num << std::endl;       
    }
    while(1) { continue; }
}
