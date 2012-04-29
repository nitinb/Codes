/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : conversion.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Monday 04 July 2011 01:22:11 PM IST

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

#define DEBUG 0
#define MAX_SIZE 10000

int main(){
    int N;
    double inp, oup;
    std::string str, str_oup;
    
    std::cin >> N;
    for(int i=0; i<N; i++){
       std::cin >> inp >> str;
       if(str.compare("kg") == 0){
          oup = (1.0000/0.4536)*inp;
          str_oup = "lb";
       }
       else if(str.compare("lb") == 0){
          oup = (1.0000/2.2046)*inp;
          str_oup = "kg";          
       }
       else if(str.compare("l") == 0){
          oup = (1.0000/3.7854)*inp;
          str_oup = "g";          
       }
       else if(str.compare("g") == 0){
          oup = (1.0000/0.2642)*inp;
          str_oup = "l";          
       }
       std::cout << "act output" << oup << std::endl;
//       printf("%d %.4f %s\n", i+1, oup, str_oup);
       std::cout << i+1 << " " << std::setprecision(4) << std::fixed << oup << " " << str_oup << std::endl;
    }
}
