/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : Mispell.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Monday 16 May 2011 06:36:08 PM IST

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
    int N, M;
    std::string str;
    
    std::cin >> N;
    for(int i=0; i<N; i++){
       std::cin >> M >> str;
       std::cout << i+1 << " ";
       for(int j=0; j<str.length(); j++){
           if(j!=M-1) std::cout << str[j];           
       }
       std::cout << std::endl;
    }
}
