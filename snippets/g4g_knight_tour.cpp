#include<stdio.h>
#define N 8
 
int solveKTUtil(int x, int y, int movei, int sol[N][N], int a[], int b[]);
 
/* A utility function to return square of n. */
int square(int n) { return n*n; }
 
/* A utility function to check if i,j are valid indexes for N*N chessboard */
int isSafe(int i, int j, int sol[N][N])
{
   if ( i >= 0 && i < N && j >= 0 && j < N && sol[i][j] == 0)
    return 1;
   return 0;
}
 
/* A utility function to print solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
   for (int i = 0; i < N; i++)
   {
     for (int j = 0; j < N; j++)
      printf(" %d ", sol[i][j]);
     printf("\n");
   }
}
 
/* This function solves the Knight Tour problem using Backtracking.  This
function mainly uses solveKTUtil() to solve the problem. It returns false if
no complete tour is possible, otherwise return true and prints the tour.
Please note that there may be more than one solutions, this function
prints one of the feasible solutions.  */
bool solveKT()
{
   int sol[N][N];
 
   /* Initialization of solution matrix */
   for (int i = 0; i < N; i++)
     for (int j = 0; j < N; j++)
       sol[i][j] = 0;
 
   /* a[] and b[] define next move of Knight.
      a[] is for next value of x coordinate
      b[] is for next value of y coordinate */
   int a[N] = {  2, 1, -1, -2, -2, -1,   1,  2};
   int b[N] = {  1, 2,  2,  1,  -1, -2,  -2, -1 };
 
   /* Start from 0,0 and explore all tours using solveKTUtil() */
   if(solveKTUtil(0, 0, 1, sol, a, b) == false)
   {
      printf("Solution does not exist");
      return false;
   }
   else
   {
      printSolution(sol);
   }
 
   return true;
}
 
/* A recursive utility function to solve Knight Tour problem */
int solveKTUtil(int x, int y, int movei, int sol[N][N], int a[N], int b[N])
{
    int k, u, v;
    if (movei == square(N))
      return true;
    else
    {
      /* Try all next moves from the current coordinate x, y */
      for (k = 0; k < N; k++)
      {
        u = x + a[k];
        v = y + b[k];
        if (isSafe(u, v, sol))
        {
            sol[u][v] = movei;
            if( solveKTUtil(u, v, movei+1, sol, a, b) == true)
              return true;
            else
               sol[u][v] = 0;// backtracking
        }
      }
    }
    return false;
}
 
/* Driver program to test above functions */
int main()
{
  solveKT();
  return 0;
}
