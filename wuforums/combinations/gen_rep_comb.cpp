#include <iostream>

int count = 0;
void another_method(std::string strA, char* output, int index){

   for(int i = 0; i < strA.length(); i++){
       output[index] = strA[i];

       if(index == strA.length() - 1){
           count++;
           std::cout << count << " " << output << "*" << std::endl;
           continue;
       }
       another_method(strA, output, index + 1);
   }

}

int main(){
    std::string strA;

    std::cout << "string : ";
    std::cin >> strA;

    char output[strA.length() + 1];
    output[strA.length()] = '\0';

    another_method(strA, output, 0);
}
