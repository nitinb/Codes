/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : addRev.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Thursday 16 June 2011 12:29:32 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <iomanip>

/*STL *algorithm* */
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 1
#define MAX_SIZE 500

std::string calculate_rev_sum(std::string num1, std::string num2){
   std::string output;
   char ch;

   int len1, len2, carry, sum, p1, p2, i, j;
   len1 = num1.length(); len2 = num2.length();
   carry = 0; i = 0; j = 0;
//   std::cout << len1  << "  "  << len2    << std::endl;      
//   std::cout << num1  << "  "  << num2 << std::endl;            
  
   while( i < len1 || j < len2 ){
      p1 = i < len1 ? num1[i] - '0' : 0;
      p2 = j < len2 ? num2[j] - '0' : 0;
            
      sum   = carry + p1 + p2;
      carry = sum/10;
      ch = sum%10+'0';
      output = output + ch;
      i++; j++;
//      std::cout << p1  << "  "  << p2    << std::endl;
//      std::cout << sum%10 << "  "  << carry << "  " << output << std::endl;
   }
   if(carry > 0){
      ch     = carry + '0';
      output = output + ch;
   }
   return output;
}


int main(){
    int num_test_cases;
    std::string num1, num2, _ret;
           
    std::cin >> num_test_cases; // num of test cases    
    for(int i = 0; i < num_test_cases; i++){
       std::cin >> num1 >> num2;

       _ret = calculate_rev_sum(num1, num2);
       int temp=-1;
       for(int i=0; i<_ret.length(); i++){
           if(_ret[i] == '0' && temp == -1) temp=i;
           else if(_ret[i] != '0'){
               if(temp != -1){
                  if(temp == 0) temp=i;
                  for(int j=temp; j<=i; j++)
                     printf("%c",_ret[j]);
                  temp=-1;
              }else{
                     printf("%c",_ret[i]);
              }
           }
       }
       printf("\n");
    }
}
