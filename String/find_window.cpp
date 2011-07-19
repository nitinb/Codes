/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : find_window.cpp

* Purpose :

* Creation Date : 13-07-2011

* Last Modified : Thursday 14 July 2011 02:38:12 PM IST

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
 
void find_window(std::string strA, std::string strB){
   int  storage[MAX_SIZE] = {0};
   bool flag[MAX_SIZE]    = {false};
   int  len = strB.length();
   int  curr_min = strA.length();

   for(int i = 0; i < strB.length(); i++){
       storage[strB[i]-'a']++;
       flag[strB[i]-'a'] = true;
   }

   int j = -1;
   for(int i = 0; i < strA.length(); i++){
       if( storage[strA[i]-'a'] ){
           if( j == -1){ j = i; }
           storage[strA[i]-'a']--;
           len--;
       }
       if(len == 0){
           curr_min = curr_min > i-j+1 ? i-j+1 : curr_min;
           std::cout << "found a window; start index=" << j << "; last index=" << i << "; size=" << curr_min << std::endl;
           if(i == strA.length()-1 || curr_min == strB.length()) break;

           storage[strA[j]-'a']++;
           len++;  j++;
           while(flag[strA[j++]-'a']){ }
       }
   }
}

int main(){
    std::string strA, strB;
    std::cout << "Main string .. string A" << std::endl;
    std::cin >> strA;

    std::cout << "string of chars.. to be searched" << std::endl;
    std::cin >> strB;

    find_window(strA, strB);
}
