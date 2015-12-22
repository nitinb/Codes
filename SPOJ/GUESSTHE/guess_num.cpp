/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : guess_num.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Monday 27 June 2011 05:02:42 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
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

#define MAX_SIZE 20
#define DEBUG 0

typedef long long ll;
typedef unsigned long long ull;

int store_divisors(int *a, int limit){
    int _size = 0, k;
    a[_size++] = 2;
    for(int j = 3; j <= limit; j+=2){
      for(k = 0; k < _size; k++){
         if(j%a[k] == 0) break;
         if(a[k] > sqrt(j)) {k = _size; break;}
      }
      if(k == _size){ a[_size++] = j; }
    }
    return _size;
}

int main(){
    int limit = int(ceil(sqrt(MAX_SIZE)));
    int *ARR  = (int*)malloc(limit*sizeof(int));
    int count_d = store_divisors(ARR, limit);
    
    ll oup;
    std::string inp;
    while(1){
        std::cin >> inp;
        if(inp == "*"){ break; } //what if all NNNNN
        else if(inp[0] == 'N'){ printf("-1\n"); }
        else{
             int curr_count = 0;
             int mult[20] = {0};
             oup = 1;
             for(int i=1; i<inp.length(); i++){
                 int num = i+1;
                 if(inp[i] == 'Y'){
                     int final = int(ceil(sqrt(num)));
                     for(int k=0; k<count_d; k++){
                         if(ARR[k] > final){ break; }
                         curr_count = 0;
                         while(1){
                              if(num%ARR[k] == 0){
                                  curr_count++;
                                  num /= ARR[k];
                              }
                              else{
                                  if(mult[ARR[k]-1] < curr_count){ mult[ARR[k]-1] = curr_count; }
                                  break;
                              }
                         }
                     }
                     if(num != 1 && mult[num-1] == 0){
                         mult[num - 1] = 1;
                     }
                 }
             }
             for(int i=1; i<inp.length(); i++){
                 oup = oup * pow(i+1,mult[i]);
             }
             bool flag=true;
             for(int i=1; i<inp.length(); i++){
                 if( (inp[i]=='N') && oup%(i+1) == 0){ 
                     printf("-1\n");
                     flag = false; break;
                 }
             }
             if(flag){ printf("%lld\n",oup); }
        }
    }
}
