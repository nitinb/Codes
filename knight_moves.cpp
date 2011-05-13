/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : knight_moves.cpp

* Purpose :

* Creation Date : 12-04-2011

* Last Modified : Tue 12 Apr 2011 02:25:10 PM IST

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
  int arr[num];
  int p_calc_moves[8][8];

  /*
   * Initialise 2-D array
   */
  fori(j,0,8){
    fori(k,0,8){
      p_calc_moves[j][k] = -1;
    }
  }

  /*
   * print 2-D array
   */
  fori(j,0,8){
    fori(k,0,8){
      std::cout << p_calc_moves[j][k] << "  ";
    }
    std::cout << std::endl;
  }

 
  int c_x = 3, c_y = 3, _prob = 0;
  fori(i,0,num){
    if(p_calc_moves[c_x][c_y] == -1){ // prob for this pt is not calculated
      _prob = num_moves();
      p_calc_moves[c_x][c_y] = _prob;
    }
    else
      _prob = p_calc_moves[c_x][c_y];
  } 


  /*
   * print 2-D array
   */
  fori(j,0,8){
    fori(k,0,8){
      std::cout << p_calc_moves[j][k] << "  ";
    }
    std::cout << std::endl;
  }
}
