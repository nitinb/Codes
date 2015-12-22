/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : first_non_rep.cpp

* Purpose :

* Creation Date : 13-07-2011

* Last Modified : Wednesday 13 July 2011 05:12:47 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>

/*STL *algorithm* */
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 1
#define MAX_SIZE 26
 
void non_rep(std::string strA){
   int storage[MAX_SIZE] = {0};
   for(int i = 0; i < strA.length(); i++)
       storage[strA[i]-'a']++;

   for(int i = 0; i < strA.length(); i++){
       if( storage[strA[i]-'a'] == 1){
           std::cout << strA[i] << std::endl;
           break;
       }
   }
}

int main(){
    std::string strA, strB;
    std::cout << "Main string .. string A" << std::endl;
    std::cin >> strA;

    non_rep(strA);
}
