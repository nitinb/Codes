/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : Homo.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Thursday 16 June 2011 05:59:05 PM IST

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

void print_map(std::map <long long int, int> _temp){
    std::map<long long int, int>::iterator it;

    for(it = _temp.begin(); it != _temp.end(); it++){
        std::cout << (*it).first << " => " << (*it).second << std::endl;
    }
}


int main(){
    
    int num_test_cases;  // input variables
    char op[12]; long long int num;

    std::map<long long int, int> count; // state variables
    int num_homos = 0, num_heteros = 0;
 
    std::cin >> num_test_cases; // num of test cases
    for(int i = 0; i < num_test_cases; i++){
       scanf("%s %lld",op,&num);
       if(DEBUG) std::cout << op[0] << " ** " << num << std::endl;

       if(op[0] == 'i'){
          if(DEBUG) std::cout << "insert op " << num << std::endl;

          if(count.find(num) == count.end()){ count[num] = 1; }
          else { count[num]++; }

          if(count[num] == 1) num_heteros++;
          else if(count[num] == 2) num_homos++;
       }
       else if(op[0] == 'd'){
          if(DEBUG) std::cout << "delete op " << num << std::endl;

          if(count.find(num) != count.end()){
             int _t = count[num]; _t--;
             count[num] = _t >= 0 ? _t : 0 ;
             if(count[num] == 1) num_homos--;
             else if(count[num] == 0 && _t >= 0) num_heteros--;
          }
       }

       // Decide state of the list
         // print_map(count);
         // std::cout << "num heteros: " << num_heteros << " num homos: " << num_homos << std::endl;

       if(num_heteros > 1 && num_homos > 0) printf("both\n");
       else if(num_heteros <= 1 && num_homos == 0) printf("neither\n");
       else if(num_homos > 0)   printf("homo\n");
       else if(num_heteros > 1) printf("hetero\n");
    }
}
