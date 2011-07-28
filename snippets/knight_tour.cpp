/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : knight_tour.cpp

* Purpose :

* Creation Date : 12-04-2011

* Last Modified : Thursday 28 July 2011 01:58:00 PM IST

* Created By : Nitin 

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <cstdlib>
#include <cmath>
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

#define DEBUG 1
#define ROWS  8
#define COLS  8
#define FORI(i,j,k) for(int i = j; i < k; i++)

void print_chess(bool *chess){
    FORI(i,0,ROWS){
       FORI(j,0,COLS){
         std::cout << *(chess + i*COLS +j) << " ";
       }
       std::cout << std::endl;
    }
}

bool isSafe(int i, int j, bool *chess){
   if( i >= 0 && i < ROWS && j >= 0 && j < COLS && (*(chess + i*COLS +j) == false) )
       return true;
   return false;
}


bool gen_tour(int i, int j, bool *chess, int count){
//   print_chess(chess);

   if(count == ROWS*COLS){
      std::cout << "A tour found" << std::endl;
      return true;
   }
   bool flag;
   int a[ROWS] = {2, 1, -1, -2, -2, -1,   1,  2};
   int b[ROWS] = {1, 2,  2,  1,  -1, -2,  -2, -1};

   FORI(k,0,ROWS){
      int u = i+a[k];
      int v = j+b[k];
      if( isSafe(u, v, chess) ){
         *(chess + u*COLS + v) = true;
         flag = gen_tour(u, v, chess, count+1);
         if(flag == true){ return true; }
         else{ *(chess + u*COLS + v) = false; }
      }
   }
   return false;
}

int main(){
   bool chess[ROWS][COLS] = {false};

   chess[0][0]=true;
   bool ch = gen_tour(0, 0, &chess[0][0], 1);
   if(ch){
     std::cout << "success " << std::endl;
     print_chess(&chess[0][0]);
   } else{
      std::cout << "FUUU" << std::endl;
   }
}
