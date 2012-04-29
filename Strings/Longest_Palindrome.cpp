/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : longest_palindrome.cpp

* Purpose :

* Creation Date : 09-05-2011

* Last Modified : Monday 09 May 2011 05:26:53 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <cmath>
#include <cstdlib>

/*STL *algorithm* */
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 1


struct info{
       int lower;
       int higher;
};


info max(info a, info b){
     if(a.higher - a.lower > b.higher - b.lower)
          return a;
          
     return b;
}

info palindrome(std::string input_string, int start1, int start2){
    int i = start1, z = start2, j = 0, k = 0, len = input_string.length();
    int lower_index = 0, higher_index = 0;
    
    while(i < len && z < len){
            j = i;
            k = z;
            while(j >= 0 && k < len && input_string[j] == input_string[k]){
                    if(higher_index - lower_index < k - j){
                        lower_index = j;
                        higher_index = k;
                    }
                    j--; k++;
            }
            i++;
            z++;
    }
//    std::cout << higher_index << lower_index << std::endl;
    info ret;
    ret.lower = lower_index;
    ret.higher = higher_index;
    
    return ret;
}


info find_longest_palindrome(std::string input_string){
    // find odd length palindrome
    info ret1, ret2;
    ret1 = palindrome(input_string, 0, 0);
    
    // find even length palindrome
    ret2 = palindrome(input_string, 0, 1);
    
    return max(ret1, ret2);
}


int main(){
    std::string input_string;
    std::cin >> input_string;
    getchar();
        
    info ret = find_longest_palindrome(input_string);
    std::cout << ret.higher - ret.lower + 1 << std::endl;
    getchar();
}
