/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : encoding.cpp

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

// **************************************************
int main(){
    int cols;
    std::string s;

    while(1){
       scanf("%d",&cols);
       if(cols == 0){ break; }
       std::cin >> s;
       int len = s.length();           
       int rows= len/cols;
       
       char M[rows][cols];
       int curr_r=-1, curr_c, incr;
       for(int i = 0;i < len; i++){
           if(i%cols == 0){
               curr_r++;
               if(curr_r%2 == 0){
                   curr_c=0; incr=1;          
               }else{
                   curr_c=cols-1; incr=-1;
               }
           }
           M[curr_r][curr_c]=s[i];
           curr_c+=incr;
       }

       for(int i = 0; i < cols; i++){
           for(int j = 0; j < rows; j++){
               printf("%c",M[j][i]);
           }
       }
       printf("\n");
    }
//    while(1) { continue; }
}
