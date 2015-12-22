/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : mult.cpp

* Purpose :

* Creation Date : 09-05-2011

* Last Modified : Monday 09 May 2011 02:53:22 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <cmath>

int break_num(long long int num){
  int count = 1;
  for(;;){
    long long int  mod = pow(10, count);
    if(num / mod == 0)
      break;
    count++;
  }
  return count-1;
}

int rem(int mod, int num){
   int rem;
   if(mod != 0)
     rem = num - pow(10,mod);
   else
     rem = num;
   return rem;
}

int main(){

   long long int num1, num2;
   std::cin >> num1 >> num2;   
//   std::cout << num1 << " " << num2 << std::endl;   

   int mod1 = break_num(num1);
   int mod2 = break_num(num2);

   int rem1, rem2;
   rem1 = rem(mod1, num1);  
   rem2 = rem(mod2, num2);  
 
//   std::cout << mod1 << " " << mod2 << std::endl;
//   std::cout << rem1 << " " << rem2 << std::endl;

   long long int p1 = mod2 != 0 ? rem1*pow(10,mod2) : 0;
   long long int p2 = mod1 != 0 ? rem2*pow(10,mod1) : 0;
   long long int p3 = mod1 == 0 && mod2 == 0 ? 0 : pow(10,mod1+mod2);

   long long int final_output = rem1*rem2 + p3 + p1 + p2;
   std::cout << final_output << std::endl;
}
