/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : check_rotate.cpp

* Purpose :

* Creation Date : 13-07-2011

* Last Modified : Wednesday 13 July 2011 05:21:00 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>

/*STL *algorithm* */
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 1
#define MAX_SIZE 26
 
void check_rotate(std::string strA, std::string strB){
    strA = strA + strA;
    int _pos = strA.find(strB);
    if( _pos == std::string::npos){
        std::cout << "strB is not rotated form of strA " << std::endl;
    }else{
        std::cout << "strB is rotate form of strA @posn " << _pos << std::endl;
    } 
}

int main(){
    std::string strA, strB;
    std::cout << "Main string .. string A" << std::endl;
    std::cin >> strA;

    std::cout << "string to be checked .." << std::endl;
    std::cin >> strB;

    check_rotate(strA, strB);
}
