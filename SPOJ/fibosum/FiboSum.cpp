/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : FiboSum.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Monday 20 June 2011 06:17:14 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cstdio>

/*STL *algorithm* */
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 0 
#define MAX 100000000
#define MOD_NUM 1000000007

long long I[4] = {1, 1, 1, 0};

void print(long long int *m){
  if(!DEBUG) return;
  for(int i=0; i<4; i++) std::cout<<m[i]<<" ";
  std::cout<<std::endl;
}
// 1 1   n+1  n
// 1 0   n    n-1
long long int* calc_fib(long long M){
   long long *A, *B;
   A = (long long*)malloc(4*sizeof(long long));
   B = (long long*)malloc(4*sizeof(long long));

   if(M<2){ return I; }
   if(M%2 == 0){
      A = calc_fib(M/2);
      B[0] = (A[0]*A[0]+A[1]*A[2])%MOD_NUM; 
      B[1] = (A[0]*A[1]+A[1]*A[3])%MOD_NUM; 
      B[2] = (A[2]*A[0]+A[3]*A[2])%MOD_NUM; 
      B[3] = (A[2]*A[1]+A[3]*A[3])%MOD_NUM;
      return B; // A^2 i.e. A*A
   }
   else{
      A = calc_fib(M/2);
      B[0] = (A[0]*A[0]+A[1]*A[2])%MOD_NUM; 
      B[1] = (A[0]*A[1]+A[1]*A[3])%MOD_NUM; 
      B[2] = (A[2]*A[0]+A[3]*A[2])%MOD_NUM; 
      B[3] = (A[2]*A[1]+A[3]*A[3])%MOD_NUM;

      long long *C;
      C = (long long*)malloc(4*sizeof(long long));
      C[0] = (B[0]*I[0]+B[1]*I[2])%MOD_NUM;
      C[1] = (B[0]*I[1]+B[1]*I[3])%MOD_NUM; 
      C[2] = (B[2]*I[0]+B[3]*I[2])%MOD_NUM; 
      C[3] = (B[2]*I[1]+B[3]*I[3])%MOD_NUM;
      return C; // B=A*A; C=B*A;
   }
}

long long sum_fib(long long M, long long _x){
    long long Y;
    long long *A = calc_fib(_x);
    Y = A[1]-1;
    return Y;
}

void check_calc_fib(){
  long long *A;
  long long Y;
  for(int i = 100000; i < 100001; i++){
      if(i==0){ Y=0; }
      else if(i==1){ Y=1; }
      else {
        A = calc_fib(i);
        Y = A[1];
      }
      printf("%drd fib is %lld\n",i, Y);
  }
}

int main(){
//    freopen("input.txt", "r", stdin);
    int N, M;
    int num_test_cases;
    scanf("%d",&num_test_cases);
    for(int i = 0; i < num_test_cases; i++){
       scanf("%d %d",&N,&M);
       if(DEBUG) std::cout<<N<<" "<<M<<": ";
       if(M==1 && N==0){ printf("1\n"); }
       else if(M==0 && N==0){ printf("0\n"); }
       else if(M==1 && N==1){ printf("1\n"); }
       else{
           long long X = sum_fib(N, N+1);
           long long Y = sum_fib(M, M+2);
           if(DEBUG) printf("sums are %lld *** %lld\n", X, Y);
           printf("%lld\n", ( (Y-X+MOD_NUM)%MOD_NUM) );
       }
    }
}
