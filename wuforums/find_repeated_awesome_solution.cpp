/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : find_repeated.cpp

* Purpose :

* Creation Date : 11-05-2011

* Last Modified : Monday 30 May 2011 06:08:16 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <cmath>
#include <cstdlib>

/*STL *algorithm* */
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 1


// First do-while in code is similiar to finding loop in LL
//   and second do-while loop finds the intersection element
int find_repeating_elements(int *A, int n){
  int x = n-1, y = n-1;
  do {x = A[A[x]]; y = A[y];} while (x!=y);
  x = n-1;
  do {x = A[x]; y = A[y];} while (x!=y);
  return x; 
}

int main(){
  int num_te = 6; // length of array (n)

  int SIZE = num_te;
  int *arr = (int *)malloc(SIZE*sizeof(int));

  for(int i = 0; i < num_te; i++){
    std::cin >> arr[i];
  }
  std::cout << std::endl;
   
  int _ret = find_repeating_elements(arr, SIZE);
  std::cout << "_ret value " << _ret << std::endl;
  while(1) continue;
}
