/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : min_in_interval.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Friday 13 May 2011 04:55:46 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <cmath>

/*STL *algorithm* */
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 1
#define min(a,b) a < b ? a : b;
#define max(a,b) a > b ? a : b;

void preprocessing(int *arr, int rows, int store[][4]){
     
     for(int i = 0; i < rows; i++)
         store[i][0] = i;
     
     for(int j = 1; (1 << j) <= rows; j++){
         for(int i = 0; i + (1 << j) - 1 < rows; i++){
             if(arr[store[i][j - 1]] <= arr[store[i + (1 << (j - 1))][j - 1]])
                 store[i][j] = store[i][j - 1];
             else
                 store[i][j] = store[i + (1 << (j - 1))][j - 1];
            // std::cout << "i : " << i << ", j: " << j << std::endl;
         }
     }
     return;
}


int find_min(int store[][4], int initial, int final, int *arr){
    int k = floor( (log(final - initial))/(log(2)) );
    
    if(arr[store[initial][k]] <=  arr[store[final - (1 << k) + 1][k]])
        return store[initial][k];
    
    return store[final - (1 << k) + 1][k];
}


int main(){
   int arr[] = {9, 2, 3, 4, 5, 6, 7, 8, 18, 0};
   int n = sizeof(arr)/sizeof(int), initial, final;
   
   int cols = ceil( (log(n))/(log(2)) );//4
   int store[n][4];
  
   preprocessing(arr, n, store);

   while(1){
       std::cin >> initial >> final;
       std::cout << std::endl;
       
       int index = find_min(store, initial, final, arr);
       std::cout << index << std::endl;
   }
}
