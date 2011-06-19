#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

std::string calculate_sum(std::string num1, std::string num2){
   std::string output;
   char ch;

   int len1, len2, carry, sum, p1, p2;
   len1 = num1.length(); len2 = num2.length();
   carry = 0;
   while( len1 > 0 || len2 > 0 ){
      p1 = len1 > 0 && (num1[len1-1] != ' ')? num1[len1-1] - '0' : 0;
      p2 = len2 > 0 && (num2[len2-1] != ' ')? num2[len2-1] - '0' : 0;
            
      sum   = carry + p1 + p2;
      carry = sum/10;
      ch = sum%10+'0';
      output = ch + output;
      len1--; len2--;
   }
   if(carry > 0){
      ch     = carry + '0';
      output = ch + output;
   }
   return output;
}

std::string calculate_sum_pdt(std::vector<std::string> partial_mult){
   std::string output;
   while(partial_mult.size() > 1){
      output = calculate_sum(partial_mult[0], partial_mult[1]);
      partial_mult.erase(partial_mult.begin(), partial_mult.begin()+2);
      partial_mult.push_back(output);
   }
   return partial_mult[0];
}

std::string calculate_mult(std::string num1, std::string num2){
   std::string output;
   std::vector<std::string> partial_mult;
   std::map<int, std::string> map_mult;
   char ch;

   int len1, len2, carry, mult, p1, p2, count;
   len1 = num1.length(); len2 = num2.length();
   count = 0;
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
         }
         if(carry > 0){
            ch     = carry + '0';
            output = ch + output;
         }
         map_mult[p2] = output;
      }
      
      ch = ' ';
      for(int i = 0; i < count; i++){ output += ch; }
      partial_mult.push_back(output);      
      len2--; count++;
   }
   return calculate_sum_pdt(partial_mult);
}

int main(){
    int num_test_cases, num;
    std::cin >> num_test_cases;

    std::string ans;
    std::ostringstream _temp;
    for(int i = 0; i < num_test_cases; i++){
       std::cin >> num;
       ans = "1";
       for(int j = 1; j <= num; j++){
          _temp << j;
          ans = calculate_mult(ans, _temp.str());
          _temp.str("");
       }
       std::cout << ans << std::endl;      
    }
}
