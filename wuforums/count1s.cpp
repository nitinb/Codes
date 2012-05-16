/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : count1s.cpp

* Purpose :

* Creation Date : 11-05-2011

* Last Modified : Friday 13 May 2011 11:32:26 AM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <cmath>

int m_count_number_1(int num){
   int _temp = num, count = 0;
   while(_temp != 0){
     if (_temp % 10 == 1) { count++; }
     _temp /= 10;
   }
   return count;
}


int main(){

  int num; // how many numbers ???
  num = 10;
  int curr_num = 0, total = 0;

  while(num != 0){
    total += m_count_number_1(curr_num);
    if(total == curr_num) { 
       num--;
       std::cout << "\t **spcl number** " << curr_num << std::endl;
    }
    std::cout << "curr num - " << curr_num << " total 1's- " << total << std::endl;
    curr_num++;
  }
}
