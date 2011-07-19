/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : rev_sentence.cpp

* Purpose :

* Creation Date : 18-07-2011

* Last Modified : Tuesday 19 July 2011 03:21:42 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>

/*STL *algorithm* */
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 0

void rec_reverse(char *strA){
    if(*strA == '\0') return;

    strA++;
    rec_reverse(strA);
    strA--;
    printf("%c",*strA);
}

void iter_reverse(char *strA){
    int len = strlen(strA);
    char ch;

    for(int i = 0; i < len/2; i++){
        ch      = strA[i];
        strA[i] = strA[len-1-i];
        strA[len-1-i] = ch;
    }
}

void select_reverse(char *strA){
   int ini_pos=0, final_pos=0, curr_pos=0;
   char ch;

   while(1){
       if(strA[curr_pos] == ' ' || strA[curr_pos] == '\0'){
          final_pos = curr_pos;
          if(DEBUG) std::cout << "ini pos=" << ini_pos << "; final pos=" << final_pos << std::endl;
          for(int i = 0; i < (final_pos-ini_pos)/2; i++){
             ch      = strA[ini_pos + i];
             strA[ini_pos + i] = strA[final_pos-1-i];
             strA[final_pos-1-i] = ch;
          }
          if(strA[curr_pos] == '\0') break;
          ini_pos = final_pos+1;
       }
       curr_pos++;
   }
}

int main(){
//    char strA[500];
    char *strA = new char[500];
    scanf("%[^\n]",strA);
    if(DEBUG) printf("%s*\n",strA);

//    rec_reverse(strA);
//    printf("\n");
    iter_reverse(strA);
    if(DEBUG) printf("%s\n",strA);

    select_reverse(strA);
    printf("%s*\n",strA);
}
