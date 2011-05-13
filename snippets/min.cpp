/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : min.cpp

* Purpose :

* Creation Date : 11-05-2011

* Last Modified : Wednesday 11 May 2011 03:23:25 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>

int min(int a, int b, int c){
  return a <= b ? ( a <= c ? a : c ) : ( b <= c ? b : c);
}


int main(){
  std::cout << min (1,0,1) << std::endl;
}
