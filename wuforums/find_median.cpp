/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : find_median.cpp

* Purpose :

* Creation Date : 23-05-2011

* Last Modified : Tuesday 24 May 2011 03:57:12 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <cmath>
#include <cstdlib>

/*STL *algorithm* */
#include <algorithm>
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


int find_median(int *arr1, int *arr2, int size1, int size2){
   int diff = (size1-size2)/2;
   int n    = (size1+size2)/2;
   // find K, such that arr1[k-1]<arr2[n-k] && arr1[k]>arr2[n-k-1]
   for(int i = diff; i < size1-diff; i++){
      if(i-1 >= 0){ 
        if(arr1[i-1] < arr2[n-i] && arr1[i] > arr2[n-i-1]) return arr1[i];
      }
      else{
        if(arr1[i] > arr2[n-i-1]) return arr1[i];
      }
   }

   for(int i = 0; i < size2; i++){
      if(i-1 >= 0){ 
        if(arr2[i-1] < arr1[n-i] && arr2[i] > arr1[n-i-1]) return arr2[i];
      }
      else{
        if(arr2[i] > arr1[n-i-1]) return arr2[i];
      }
   }
   return -1;
}

bool myfunction (int i,int j) { return (i<j); }

int find_median_brute(int *arr1, int *arr2, int size1, int size2){
   std::vector<int> comb_arr;
   
   for(int i = 0; i < size1; i++)
     comb_arr.push_back(arr1[i]);

   for(int i = 0; i < size2; i++)
     comb_arr.push_back(arr2[i]);

   sort(comb_arr.begin(), comb_arr.end(), myfunction);
   return comb_arr[comb_arr.size()/2];
}


int main(){

   int size1 = 10, size2 = 9;
//   int arr1[10] = {1,3,5,8,10,11,13,15,17,18};
//   int arr2[9]  = {2,4,6,9,12,14,19,25,37};
   int arr1[10] = {1,3,5,8,10,11,13,15,17,18};
   int arr2[9]  = {192,194,196,199,212,214,219,225,237};

   int _ret;

   if(size1 > size2){ 
      _ret = find_median(arr1, arr2, size1, size2);
   }
   else{
      _ret = find_median(arr2, arr1, size2, size1);
   }
   std::cout << "ret median " << _ret << std::endl;

   std::cout << find_median_brute(arr1, arr2, size1, size2) << std::endl;
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
