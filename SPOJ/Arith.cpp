/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : Arith.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Friday 13 May 2011 07:58:00 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <sstream>
#include <cmath>

/*STL *algorithm* */
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 1
#define MAX_SIZE 500

void print_arr(int *arr){
  for(int i = 0; i < 2; i++){
     for(int j = 0; j < MAX_SIZE; j++){
         std::cout << arr + i*MAX_SIZE + j; 
     }
     std::cout << std::endl;
  }
}

int main(){
    int num_test_cases, operand, count;
    std::cin >> num_test_cases; // num of test cases
    char ch, op;
    std::string num[2][MAX_SIZE]; // There are only two numbers
    ch = getchar();
    
    for(int i = 0; i < num_test_cases; i++){
       operand=0; count=0;
       while(1){
          ch = getchar();
          if(ch == '\n') break;
          if(ch >= '0' && ch <= '9')
             num[operand][count++] = ch - '0';
          else{  // operator
              operand++;
              count = 0;
              op = ch;
          }
       }
       std::cout << num[0] << "  " << op << "  "  << num[1] << std::endl;
    }
    
    while(1) { continue; }
}


