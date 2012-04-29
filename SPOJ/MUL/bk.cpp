/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : mul.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Monday 04 July 2011 03:42:18 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
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

std::string calculate_sum(std::string num1, std::string num2){
   std::string output;
   char ch;

   int len1, len2, carry, sum, p1, p2;
   len1 = num1.length(); len2 = num2.length();
   carry = 0;
//   std::cout << len1  << "  "  << len2    << std::endl;      
//   std::cout << num1  << "  "  << num2 << std::endl;            
  
   while( len1 > 0 || len2 > 0 ){
      p1 = len1 > 0 && (num1[len1-1] != ' ')? num1[len1-1] - '0' : 0;
      p2 = len2 > 0 && (num2[len2-1] != ' ')? num2[len2-1] - '0' : 0;
            
      sum   = carry + p1 + p2;
      carry = sum/10;
      ch = sum%10+'0';
      output = ch + output;
      len1--; len2--;
//      std::cout << p1  << "  "  << p2    << std::endl;
//      std::cout << sum%10 << "  "  << carry << "  " << output << std::endl;
   }
   if(carry > 0){
      ch     = carry + '0';
      output = ch + output;
   }
   return output;
}

std::vector<std::string> calculate_mult(std::string num1, std::string num2){
   std::string output;
   std::map<int, std::string> map_mult;
   char ch;

   int len1, len2, carry, mult, p1, p2, count;
   len1 = num1.length(); len2 = num2.length();
   std::vector<std::string> partial_mult(len2);
   count = 0;
//   std::cout << "size: " << len1  << "  "  << len2    << std::endl;
//   std::cout << "num:  " << num1  << "  "  << num2 << std::endl;
   map_mult[0] = '0';
  
   while(len2 > 0 ){
      output = ""; carry = 0;
      p2 = num2[len2-1] - '0';
      
      if(map_mult.find(p2) != map_mult.end()){ // We already have this partial pdt
         output = map_mult[p2];
      }
      else{
         len1 = num1.length();
         while(len1 > 0){
            p1    = num1[len1-1] - '0';                 
            mult  = carry + p1*p2;
            carry = mult/10;
            ch    = mult%10+'0';
            output = ch + output;         
            len1--;
//            std::cout << p1  << "  "  << p2    << std::endl;
//            std::cout << mult << "  "  << carry << "  " << output << std::endl;         
         }
         if(carry > 0){
            ch     = carry + '0';
            output = ch + output;
         }
         map_mult[p2] = output;
      }
      
      ch = ' ';
      for(int i = 0; i < count; i++){ output += ch; }
      partial_mult[count] = output;
      len2--; count++;
   }
   return partial_mult;
}

std::string calculate_sum_pdt(std::vector<std::string> partial_mult){
   std::string output;
   while(partial_mult.size() > 1){
//      std::cout << "size (decr): " << partial_mult.size() << std::endl;
      output = calculate_sum(partial_mult[0], partial_mult[1]);
      partial_mult.erase(partial_mult.begin(), partial_mult.begin()+2);
      partial_mult.push_back(output);
   }
   return partial_mult[0];
}

int main(){
    int num_test_cases;
    std::vector<std::string> partial_mult; 
    std::string num1, num2, _ret;
 
    scanf("%d",&num_test_cases);
    for(int i = 0; i < num_test_cases; i++){
       std::cin >> num1 >> num2; 
//       std::cout << num1  << "**"  << num2 << "*" << std::endl;

          _ret = "";
          partial_mult = calculate_mult(num1, num2);
          _ret = calculate_sum_pdt(partial_mult);
          if(_ret[0] == '0') _ret = "0";
          std::cout << _ret << std::endl;
    }
}
