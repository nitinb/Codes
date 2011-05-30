/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : count_elements.cpp

* Purpose :

* Creation Date : 11-05-2011

* Last Modified : Monday 30 May 2011 05:56:46 PM IST

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

#define DEBUG 0

void find_count_elements(int *arr, int len){
   int i = 1;
   int count_sw = 0;
   while(i < len){
      if(arr[i] < 0 ){ i++; count_sw = 0; continue; }

      int temp = arr[i];
      if(arr[temp] > 0){
         arr[i]    = arr[temp];
         arr[temp] = -1; //First time number is encountered!!
         count_sw++;
         if(count_sw > len-1){ i++; count_sw = 0; }
      }
      else{ 
         arr[temp]--;  arr[i] = -(len+2); i++; count_sw = 0;
      }
          
      if(DEBUG) std::cout << arr[i] << " " << i << std::endl;
   }
}

int main(){
  int _SIZE = 6;
  int SIZE = _SIZE + 1;
  int *arr = (int *)malloc(SIZE*sizeof(int));

  for(int i = 1; i < SIZE; i++){
    std::cin >> arr[i];
  }
  std::cout << std::endl;
   
  find_count_elements(arr, SIZE);
  for(int i = 1; i < SIZE; i++){
    arr[i] *= -1;
    if(arr[i] < SIZE)
      std::cout << "count of "<< i << " ==> " << arr[i] << std::endl;
  }  
  while(1) continue;
}
