/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : MissingElements.cpp

* Purpose :

* Creation Date : 11-05-2011

* Last Modified : Monday 30 May 2011 02:30:13 PM IST

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

void find_missing_elements(int *arr, int len){
    int i = 0;
    int count_sw = 0;
    while(i < len){
        int temp = arr[i];

        if(temp == -1 || temp == i + 1){
            i++;
            count_sw = 0;
            continue;
        }

        arr[i]   = arr[temp-1];
        arr[temp-1] = temp;
        count_sw++;
        if(count_sw > len-1){
            i++;
            count_sw = 0;
        }
    }
}

int main(){
  int num_te = 6; // length of array (n)
  int num_me = 4; // number of missing elements(k)

  int SIZE = num_te + num_me;
  int *arr = (int *)malloc(SIZE*sizeof(int));
  for(int i = 0; i < SIZE; i++){
    arr[i] = -1;
  }

  for(int i = 0; i < num_te; i++){
    std::cin >> arr[i];
  }
  std::cout << std::endl;

  find_missing_elements(arr, SIZE);
  for(int i = 0; i < SIZE; i++){
    std::cout << arr[i];
  }  
  std::cout << std::endl;  
  while(1) continue;
}
