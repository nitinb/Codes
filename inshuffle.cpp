/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : inshuffle.cpp

* Purpose :

* Creation Date : 05-04-2011

* Last Modified : Tue 12 Apr 2011 11:47:56 AM IST

* Created By : Nitin 

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <cmath>

using namespace std;
#define DEBUG 1

int main(){

 int num, eff_num;
  std::cout << "Input length: ";
  std::cin >> num ;
  if(DEBUG) std::cout << "input is " << num << std::endl;

  eff_num = 2*num;
  int *arr = new int[eff_num];

  for(int i = 0; i < eff_num; i++){
    std::cin >> arr[i];
  }

  if(DEBUG){
    for(int i = 0; i < eff_num; i++)
      std::cout << arr[i] << std::endl;
  }

  int cycle_num = 1;
  int pivot = pow(3,cycle_num)-1;
  int curr_index = 0;
  int swap = 0;
  bool flag = false;
  if(DEBUG) std::cout << "pivot is " << pivot << std::endl;
  while(pivot < eff_num){
     curr_index = pivot;
     while(1){
        std::cout << "curr index is: " << curr_index << "; move to: " << (2*curr_index)%(eff_num+1) << std::endl;
        
        curr_index = 2*curr_index;
        if(curr_index > eff_num) break;
     }
     cycle_num++;
     pivot = pow(3,cycle_num)-1;
     if(DEBUG) std::cout << "pivot is " << pivot << std::endl;
  }
}
