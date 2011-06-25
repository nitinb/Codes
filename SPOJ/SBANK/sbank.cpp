/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : sbank.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Monday 16 May 2011 06:36:08 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <cstdio>
#include <iomanip>

/*STL *algorithm* */
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 0
#define MAX_SIZE 100

int main(){
    int n, num_test_cases;
    char acc[33];
    
    std::cin >> num_test_cases;
    for(int i = 0; i < num_test_cases; i++){
       std::cin >> n; getchar();
       std::map<std::string, int> count;
       
       for(int j = 0; j < n; j++){
          scanf("%[^\n]",acc); getchar();
          if(count.find(acc) == count.end()){
             count[acc]=1;
          }else{
             count[acc] += 1;
          }
       }
       
       std::map<std::string, int>::iterator it = count.begin();
       for(; it != count.end(); it++){
           std::cout << (*it).first << " " << (*it).second << std::endl;
       }
       std::cout << std::endl;
    }
}
