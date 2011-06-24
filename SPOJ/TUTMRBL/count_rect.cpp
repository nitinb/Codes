/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : count_rect.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Friday 24 June 2011 08:39:13 PM IST

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

#define DEBUG 1
#define MAX_SIZE 10000000

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

void print_a(int *a, int count_d){
   for(int i = 0; i < count_d; i++){
      std::cout << a[i] << std::endl;
   }
}

void rep_num(long long int num, int *a, int n){
  printf("%lld = ",num);
  int i = 0; bool flag = true;
  int final = int(ceil(sqrt(num)));
  while(i < n){
      if(a[i] > final) break;
      if(num%a[i] == 0){
         if(flag) { printf("%d",a[i]); flag = false; }
         else printf(" * %d",a[i]);
         num /= a[i];
      }else{ i++; }
  }
  if(flag){
      printf("%lld",num);
  }
  else if(num != 1){
      printf(" * %lld",num);
  }
}

int do_the_deed(long long int num){
    int max=0, i=2;
    int final = int(ceil(sqrt(num)));
    while(i<final){
        if(num%i == 0){
            max++;
        } i++;
    }
    max+=1; //1*300
    return max;
}

int main(){
//    freopen("inp.txt","r",stdin);

    int limit = int(ceil(sqrt(MAX_SIZE)));
    int *ARR  = (int*)malloc(limit*sizeof(int));
    int count_d = store_divisors(ARR, limit);
  
    long long int A;
    int _ret;
    while(1){
       std::cin >> A;
       if(A==0) break;
       rep_num(A, ARR, count_d);
       _ret = do_the_deed(A);
       printf("\nWith %lld marbles, %d different rectangles can be constructed.\n",A,_ret);
    }
}
