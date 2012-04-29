/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : remove_chars.cpp

* Purpose :

* Creation Date : 13-07-2011

* Last Modified : Monday 18 July 2011 03:16:16 PM IST

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
 
void remove_chars(std::string& strA, std::string strB){
   bool storage[MAX_SIZE] = {false};
   for(int i = 0; i < strB.length(); i++)
       storage[strB[i]-'a'] = true;

   int j = -1;
   for(int i = 0; i < strA.length(); i++){
       if( storage[strA[i]-'a'] ){
           if( j == -1){ j = i; } 
       }
       else{
           if( j!= -1){
              strA[j] = strA[i];
              j++;
           }
       }
   }
   if( j!= -1) strA.erase(strA.begin()+j, strA.end());
}

int main(){
    std::string strA, strB;
    std::cout << "Main string .. string A" << std::endl;
    std::cin >> strA;

    std::cout << "string of chars.. to be removed" << std::endl;
    std::cin >> strB;

    remove_chars(strA, strB);
    std::cout << strA << "*" << std::endl;
}
