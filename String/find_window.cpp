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
#define NINF -100

void find_window(std::string strA, std::string strB){
   int  storage[MAX_SIZE] = {0};
   bool flag[MAX_SIZE]    = {false};
   int  len = strB.length();
   int  window_size = 100000;

   for(int i = 0; i < strB.length(); i++){
       storage[strB[i]-'a']++;
       flag[strB[i]-'a'] = true;
   }

   int start = -1;
   for(int i = 0; i < strA.length(); i++){
       if(flag[strA[i]-'a'] == true){
           if(start == -1){
               start = i;
           }

           storage[strA[i]-'a']--;
           if(storage[strA[i]-'a'] == 0){
               len--;
           }
       }

       while(len == 0){
           window_size = window_size > i-start+1 ? i-start+1 : window_size;
           std::cout << "found a window; start index=" << start << "; last index=" << i << "; min size=" << window_size << std::endl;

           storage[strA[start]-'a']++;
           if(storage[strA[start]-'a'] > 0){
               len++;
           }

           do{
               start++;
           }while(strA[start] != '\0' && !flag[strA[start]-'a']);

       }
       if(i == strA.length()-1 || window_size == strB.length()) break;
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
