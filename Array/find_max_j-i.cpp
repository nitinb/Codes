/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : find_max_j-i.cpp

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
#define min(a,b) a<b?a:b;
#define max(a,b) a>b?a:b;

int findMax(int arr[], int n){
    int *minArr = (int *)malloc(n*sizeof(int));
    int *maxArr = (int *)malloc(n*sizeof(int));
    
    minArr[0] = arr[0];
    for(int i = 1; i < n; i++){
       minArr[i] = min(arr[i], minArr[i-1]);
    }
    
    maxArr[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--){
       maxArr[i] = max(arr[i], maxArr[i+1]);
    }
    int i=0, j=0, max = -n;
    while(i<n && j<n){
       if(minArr[i] < maxArr[j]){
           max = max(max, j-i);
           j++;
       }else{ i++; }
    }
    return max;
}


int main(){
   int arr[] = {9, 2, 3, 4, 5, 6, 7, 8, 18, 0};
   int SIZE  = sizeof(arr)/sizeof(int);
   
   int _ret = findMax(arr, SIZE);

   std::cout <<  _ret << std::endl;  
   while(1){continue;}
}
