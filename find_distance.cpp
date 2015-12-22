/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : find_distance.cpp

* Purpose :

* Creation Date : 09-05-2011

* Last Modified : Monday 09 May 2011 05:26:53 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/


#include <iostream>
#include <vector>
#include <algorithm>


int find_min_arr(int _temp[], int N){
  int min = 1000000;  //INF
  for(int i = 0; i < N; i++){
    if( _temp[i] < min )
      min = _temp[i];
  }
  return min;
}


int find_max_arr(int _temp[], int N){
  int max = -1;  //INF SMALL
  for(int i = 0; i < N; i++){
    if( _temp[i] > max )
      max = _temp[i];
  }
  return max;
}


int main(){

   int N = 3, K = 3;
//   std::cin >> N >> K;
   int arr[3][3] = { {6, 16, 67}, {11,17,68}, {10,15,100}};


//   for(int i = 0; i < N; i++)
//     for(int j = 0; j < K; j++)
//        std::cin >> arr[i][j];
//
//   for(int i = 0; i < N; i++)
//     for(int j = 0; j < K; j++)
//        std::cout << arr[i][j];
   int curr_num[3] = {6, 11, 10};



}
