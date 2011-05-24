/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : find_median.cpp

* Purpose :

* Creation Date : 23-05-2011

* Last Modified : Monday 23 May 2011 09:02:50 PM IST

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

int binary_search(int *arr, int start_p, int end_p, int key){
   int size = end_p - start_p;
   if(size < 0) return -1;
   else if(size == 0) return arr[start_p] == key ? start_p : -1;
   else if(size == 1) return arr[start_p] == key ? start_p : arr[end_p] == key ? end_p : -1;

   int mid = (start_p + end_p) / 2;
   if(arr[mid] == key) return mid;
   else arr[mid] < key ? binary_search(arr,mid,end_p,key): binary_search(arr,start_p,mid,key);
}


int main(){

   int size1 = 10, size2 = 9;
   int arr1[10] = {1,3,5,8,10,11,13,15,17,18};
   int arr2[9] = {1,3,7,9,10,11,19,25,37};

    // find K, such that arr1[k-1]<arr2[size2-k] && arr1[k]>arr2[size2-k-1]
   

//   int index, key;
//   key   = 3;
//   index = binary_search(arr1, 0, size1-1, key);
//   std::cout << key << " found at :" << index << std::endl;
//
//   key   = 1;
//   index = binary_search(arr1, 0, size1-1, key);
//   std::cout << key << " found at :" << index << std::endl;
//
//   key   = 18;
//   index = binary_search(arr1, 0, size1-1, key);
//   std::cout << key << " found at :" << index << std::endl;
//
//   key   = 13;
//   index = binary_search(arr1, 0, size1-1, key);
//   std::cout << key << " found at :" << index << std::endl;
//
//   key   = 130;
//   index = binary_search(arr1, 0, size1-1, key);
//   std::cout << key << " found at :" << index << std::endl;
}
