/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : knight_moves.cpp

* Purpose :

* Creation Date : 12-04-2011

* Last Modified : Tue 12 Apr 2011 12:31:01 PM IST

* Created By : Nitin 

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <cstdlib>

#define DEBUG 1
#define fori(i,j,k) for(int i = j; i < k; i++)


/*
 * Hypothetical function which will return the
 *  number of possible knight moves from a given (x,y) 
 *  cordinate on chess.
 */
int num_moves(){
   int _temp = rand()%8;
   return _temp;
}


int main(){

  int num;
  std::cout << "No of moves: ";
  std::cin >> num ;
  if(DEBUG) std::cout << "input is " << num << std::endl;
  int p_calc_moves[num][8][8];

  /*
   * Initialise the 3-D array to -1
   */
  fori(i,0,num){
    fori(j,0,8){
      fori(k,0,8){
        p_calc_moves[i][j][k] = -1;
      }
    }
  }

  /*
   * print the 3-D array
   */
  fori(i,0,num){
    fori(j,0,8){
      fori(k,0,8){
        std::cout << p_calc_moves[i][j][k];
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }
 
  int c_x = 3, c_y = 3;
  fori(i,0,num){
    if()
    int _prob = num_moves();
    
  } 
 
}
