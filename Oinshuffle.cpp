/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : Oinshuffle.cpp

* Purpose :

* Creation Date : 06-04-2011

* Last Modified : Tue 12 Apr 2011 11:47:23 AM IST

* Created By : Nitin 

_._._._._._._._._._._._._._._._._._._._._.*/


 
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
 
 
void inshuffle(int *A, int N);
void follow_cycle(int *A, int N, int seed);
void cyclic_shift(int *A, int size, int distance);
void reverse(int *A, int size);
int Inverseof2(int M);
 
 
/***************************
Main Insuffle Algorithm.
Shuffle a1 a2 ..an b1 b2 ...bn
to
b1 a1 b2 a2 .... bn an
 
Parameters: A = the array
N = 2n, size of the array.
 
The permutation is given by
i -> 2i mod (N + 1)
 
We shuffle the array starting  
from A[1] for easier coding.
****************************/
 
void inshuffle(int *initialA, int initialN)
{
 
      int m =1;
      int i;
      int power3 = 1;
      int seed = 1;
      int k = 1;
      int n = initialN/2; //N is assumed to be even.
      int *A = initialA;
      int N = initialN;
      
      while (N > 0){
 
            
            //Reset Values.
            m = 1;
            i = 0;
            power3 = 1;
            seed = 1;
            k = 1;
            n = N/2;
 
//Step 1: Find an m such that 2m+1 is the largest power of 3 <= N+1
            for (i = 0; i <= N+1; i ++){
                  if (3*power3 > N+1){
                        break;
                  }
                  power3 = 3*power3;
            }
            k = i;
 
            m = (power3 - 1)/2;
//Step 2: Cyclic Right Shift A[m+1, n+m] by m
            cyclic_shift(A+m+1,n,m);
 
// Step3: Do inshuffle of A[1....2m] by 'following cycle'.
      
            for (i = 0 ; i < k; i ++)
            {
                  follow_cycle(A,2*m,seed);
                  seed = 3*seed;
            }
// Step 4: Recurse on A[2m+1...,2n]
 
//Could have made a recursive call here:
//inshuffle(A+2*m,2*(n-m));
// But to make it O(1) space, convert tail recursion to iteration and put in a while loop.
      
            A = A + 2*m;
            N = 2*(n-m);
            // Reset Values.
      } //End of while loop.
}
 
/****************************************
Follow the cycle starting at seed.
For example: insuffle of 1 2 3 4 5 6 7 8
1 -> 2 -> 4 -> 8 -> 7 -> 5 -> 1
We follow this cycle in reverse order.
We look at 1. Save A[1].
Then look at what goes to 1, i.e 5 = 1*x
where x is inverse of 2.
Now fill A[1] with A[5].
Now look at what goes into A[5]. 7 = 5*x  
(x is inverse of 2)
So fill A[5] with A[7].
And so on.
*****************************************/
 
void follow_cycle(int *A, int N, int seed)
{
      int cur;
      int inverse2 = Inverseof2(N+1);
      int tmp;
      int prev;
 
      cur = (seed*inverse2 % (N+1));
      
      tmp = A[seed];
      prev = seed;
      while (cur != seed){
            A[prev] = A[cur];
            prev = cur;
            cur = (cur*inverse2 % (N+1));
      }
      A[prev] = tmp;
}

/*******************************
cyclic right shift an array by a given amount.
********************************/
void cyclic_shift(int *A, int sz, int k)
{
      reverse(A,sz - k);  
      reverse(A+sz-k,k);
      reverse(A,sz);
}
 
/******************************
reverse an array
*******************************/
void reverse(int *A, int sz)
{
      int i;
      int tmp;
      for (i = 0; i < sz/2; i++)
      {
            tmp = A[i];
            A[i] = A[sz-i-1];
            A[sz-i-1] = tmp;
      }
}
 
/***************************
 
find x such that 2x = 1 (mod M)
M is assumed to be an odd integer.
x = (M+1)/2
***************************/
int Inverseof2(int M)
{
      return (M+1)/2;
}
 
 
int main(){
      int n;
      int i;
      int *A;
      printf("Enter the value of n, (total size of array = 2n): ");
      scanf("%d",&n);
      A = (int *)malloc((2*n+1)*sizeof(int));
      for (i = 0; i <= 2*n; i++){
            A[i] = i;
      }
      
      inshuffle(A,2*n);
      
      printf("\n[");
      for (i = 1; i <= 2*n; i ++){
            printf(" %d",A[i]);
      }
      printf(" ]\n");
      free(A);
      return 1;
}
