/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : graycode.cpp

* Purpose :

* Creation Date : 19-04-2011

* Last Modified : Thu 05 May 2011 07:28:22 PM IST

* Created By : Nitin 

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <map>
#include <vector>
#include <cmath>

void generate_gray_code(int n_bits, std::vector<std::string> &gray_codes){
  if(n_bits <= 0) { return; }

  if(n_bits == 1) {
    gray_codes.push_back("0");
    gray_codes.push_back("1");
  }

  generate_gray_code(n_bits-1, gray_codes);
  
  if(n_bits > 1){
     int _size = gray_codes.size();
     /*
      * - Reflect the first half 
      * - Append '0' at start for first half
      * - Append '1' at start for second half 
      */
     for(int i = _size-1; i >= 0; i--){
       gray_codes.push_back(gray_codes[i]);
     }

     _size = gray_codes.size();
     std::string _str; 
     for(int i = 0; i < _size; i++){
        if(i < _size/2) {  
           _str = "0";
           gray_codes[i] = _str.append(gray_codes[i]);
        }
        else{
          _str = "1";
          gray_codes[i] = _str.append(gray_codes[i]);
        }
     }
  }
  return;
}


void print_vector(std::vector<std::string> gray_codes){
  std::vector<std::string>::iterator it;
  int count = 1;
  for(it = gray_codes.begin(); it != gray_codes.end(); it++){
     std::cout << count++ << "==>" << *it << "\t";
  }
}


int linear_search_graycode(std::string g_code, std::vector<std::string> gray_codes){
  std::vector<std::string>::iterator it;
  int count = 1;
  for(it = gray_codes.begin(); it != gray_codes.end(); it++){
    if(g_code == *it) return count;
    count++;
  }
}



int search_graycode(std::string g_code){
   static int pos;
   int len = g_code.length();

   if(g_code == "1") return 2;
   if(g_code == "0") return 1;

   std::string _temp( g_code, 1, len-1 );
   if(g_code[0] == '1') pos += pow(2,len-1) + ( pow(2,len-1)  - search_graycode(_temp) + 1);
   if(g_code[0] == '0') pos = search_graycode(_temp);

   return pos;
}


int main(){
   std::string g_code;
   int n_bits;

   std::cout << " number of bits: " ;
   std::cin  >> n_bits;
   std::cout << " graycode to search: " ;
   std::cin >> g_code;

   std::cout << " Input: " << n_bits << " && " << g_code << std::endl;
   std::vector <std::string> gray_codes;

   generate_gray_code(n_bits, gray_codes);
   print_vector(gray_codes);
  
   std::cout << std::endl << " linear search pos: " << linear_search_graycode(g_code, gray_codes) << std::endl;  
   std::cout << std::endl << " binary search pos: " << search_graycode(g_code) << std::endl;  
}
