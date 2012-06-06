#include <iostream>

int count = 0;
void sub(std::string strA, std::string output, int len){
   if(0 == len){
      count++;
      std::cout << count << " " << output << "*" << std::endl;
      return;
   }

   if(strA.length() == len){
      count++;
      std::cout << count << " " << output + strA << "*" << std::endl;
      return;
   }

   sub(strA.substr(1), output + strA.substr(0, 1), len - 1);
   sub(strA.substr(1), output, len);
}

void gen_combi(std::string strA, int x){
    sub(strA, "", strA.length() - x);
}

int main(){
    std::string strA;
    std::cin >> strA;

    int x = 2;
    gen_combi(strA, x);
}
