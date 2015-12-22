/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : PrimeC.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Monday 20 June 2011 04:04:03 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cstdlib>

/*STL *algorithm* */
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 0
long long int M = 2147483648;

int store_divisors(int *a, int limit){
    int _size = 0, k;
    a[_size++] = 2;
    for(int j = 3; j < limit; j+=2){
      for(k = 0; k < _size; k++){
         if(j%a[k] == 0) break;
         if(a[k] > sqrt(j)) {k = _size; break;}
      }
      if(k == _size){ a[_size++] = j; }
    }
    return _size;   
}

void gen_primes(int *a, int count_d){
   int k;
   long long unsigned int it = 1, _t = 0;

   while(1){
      _t++;
     if(it==0||it==1)printf("0");
     else{
          for(k = 0; k < count_d; k++){
              if(it%a[k] == 0) break;
                   if(a[k] > sqrt(it)) { k = count_d; break; }
          }
          if(k == count_d){ printf("1"); }
          else printf("0");
     }
     it=(it+1234567890)%M;
     if(DEBUG) printf("**%lld**",it);
     if(_t==150000) break; //337381912
   }
   return;
}


int main(){
    int initial_num, final_num;
    int *ARR;
    
    int limit = int(ceil(sqrt(M)));
    ARR       = (int*)malloc(limit*sizeof(int));
    int count_d = store_divisors(ARR, limit);
    
    gen_primes(ARR, count_d);
    std::cout << std::endl;
}
