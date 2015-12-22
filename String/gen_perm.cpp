/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : gen_perm.cpp

* Purpose :

* Creation Date : 13-07-2011

* Last Modified : Tuesday 19 July 2011 04:04:42 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>

/*STL *algorithm* */
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 0
#define MAX_SIZE 26

void swap(char *a, char *b){
   char temp = *a;
   *a = *b;
   *b = temp;
}

void gen_perm(char *strA, int i, int len){
   static int count = 0;

   if(i == len-1){
      count++;
      printf("%d %s*\n",count, strA);
      return;
   }

   for(int j = i; j < len; j++){
      swap(strA+i, strA+j);
      gen_perm(strA, i+1, len); 
      swap(strA+i, strA+j);
   } 
}

int main(){
    char *strA = new char[500];
    scanf("%[^\n]",strA);
    if(DEBUG) printf("%s*\n",strA);

    gen_perm(strA, 0, strlen(strA));
}
