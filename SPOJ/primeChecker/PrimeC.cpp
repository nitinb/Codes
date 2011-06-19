/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : PrimeC.cpp

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
#include <cstdlib>

/*STL *algorithm* */
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 1
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

char check_prime(int *a, int count_d, long long int it){
     int k;
     
     if(it==0||it==1) return '0';
     for(k = 0; k < count_d; k++){
           if(a[k] > sqrt(it)) { k = count_d; break; }           
           if(it%a[k] == 0) break;
     }
     if(k == count_d){ return '1'; }
     else return '0';
}


int main(){
    long long int i, _t, index;
    int *ARR; char *P;
    
    int limit = int(ceil(sqrt(M))), div_f = 1000;
    ARR = (int*)malloc(limit*sizeof(int));
    long long int _size = M/(2);
    P = (char*)malloc( (_size)*sizeof(char) );

    int count_d = store_divisors(ARR, limit);     

    for(i=3; i<M; i+=2){
       P[i] = check_prime(ARR, count_d, i);         
    }
  
    i=1;_t=0;
    while(_t < M){
     if(i==2){printf("1");}             
     else if(i%2==0){printf("0");}
     else if(i>=M/div_f){ 
          printf("%c",check_prime(ARR, count_d, i)); 
     }
     else{
          index=i/2;
          if(P[index]=='1'){printf("1");}
          else{printf("0");}
     }
     _t++;
     i=(i+1234567890)%M;
    } //while(1){continue;}
    std::cout << std::endl;
}
