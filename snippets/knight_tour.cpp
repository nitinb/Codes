/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : knight_tour.cpp

* Purpose :

* Creation Date : 12-04-2011

* Last Modified : Thursday 21 July 2011 09:42:58 PM IST

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
    getchar();
}

bool gen_tour(int i, int j, bool *chess, int count){
   std::cout << i << "*" << j << "*" << count << std::endl;
//   print_chess(chess);

   if(count == ROWS*COLS){
      std::cout << "A tour found" << std::endl;
      return true;
   }
   bool flag;

   if( i+2 < ROWS && j+1 < COLS && (*(chess + (i+2)*COLS + j+1)==false) ){
      *(chess + (i+2)*COLS + j+1) = true;
      flag = gen_tour(i+2, j+1, chess, count+1);
      if(!flag) *(chess + (i+2)*COLS + j+1) = false;
      else return flag;
   }
   if( i+2 < ROWS && j-1 > -1 && (*(chess + (i+2)*COLS + j-1)==false) ){
      *(chess + (i+2)*COLS + j-1) = true;
      flag = gen_tour(i+2, j-1, chess, count+1);
      if(!flag) *(chess + (i+2)*COLS + j-1) = false;
      else return flag;
   }
   if( i-2 > -1 && j-1 > -1 && (*(chess + (i-2)*COLS + j-1)==false) ){
      *(chess + (i-2)*COLS + j-1) = true;
      flag = gen_tour(i-2, j-1, chess, count+1);
      if(!flag) *(chess + (i-2)*COLS + j-1) = false;
      else return flag;
   }
   if( i-2 > -1 && j+1 < COLS && (*(chess + (i-2)*COLS + j+1)==false) ){
      *(chess + (i-2)*COLS + j+1) = true;
      flag = gen_tour(i-2, j+1, chess, count+1);
      if(!flag) *(chess + (i-2)*COLS + j+1) = false;
      else return flag;
   }
   if( i+1 < ROWS && j+2 < COLS && (*(chess + (i+1)*COLS + j+2)==false) ){
      *(chess + (i+1)*COLS + j+2) = true;
      flag = gen_tour(i+1, j+2, chess, count+1);
      if(!flag) *(chess + (i+1)*COLS + j+2) = false;
      else return flag;
   }
   if( i+1 < ROWS && j-2 > -1 && (*(chess + (i+1)*COLS + j-2)==false) ){
      *(chess + (i+1)*COLS + j-2) = true;
      flag = gen_tour(i+1, j-2, chess, count+1);
      if(!flag) *(chess + (i+1)*COLS + j-2) = false;
      else return flag;
   }
   if( i-1 > -1 && j-2 > -1 && (*(chess + (i-1)*COLS + j-2)==false) ){
      *(chess + (i-1)*COLS + j-2) = true;
      flag = gen_tour(i-1, j-2, chess, count+1);
      if(!flag) *(chess + (i-1)*COLS + j-2) = false;
      else return flag;
   }
   if( i-1 > -1 && j+2 < COLS && (*(chess + (i-1)*COLS + j+2)==false) ){
      *(chess + (i-1)*COLS + j+2) = true;
      flag = gen_tour(i-1, j+2, chess, count+1);
      if(!flag) *(chess + (i-1)*COLS + j+2) = false;
      else return flag;
   }
   return false;
/*
 *  if(1){
 *     std::cout << "wtf!! knight gone crazy " << std::endl;
 *     std::cout << i << "*" << j << "*" << count << std::endl;
 *  }
 */
}

int main(){
   bool chess[ROWS][COLS] = {false};
   bool ch = gen_tour(0, 4, &chess[0][0], 0);
   if(ch){
     std::cout << "success " << std::endl;
   } else{
      std::cout << "FUUU" << std::endl;
   }
}
