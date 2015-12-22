#include <iostream>
#include <cmath>

/*STL *algorithm* */
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 1
#define max(a, b) a >= b ? a : b

int binary_search(int *M, int start_p, int end_p, int *X, int key){
   int size = end_p - start_p;
   if(size < 0) return -1;
   else if(size == 0) return X[M[end_p]] < key ? end_p : -1;
   else if(size == 1) return X[M[end_p]] < key ? end_p : X[M[start_p]] < key ? start_p : -1;

   int mid = (start_p + end_p) / 2;

   X[M[mid]] >= key ? binary_search(M, start_p, mid, X, key): binary_search(M, mid, end_p, X, key);
}

int linear_search(int *M, int start_p, int end_p, int *X, int key){

   for(int i = end_p; i >= start_p; i--){
      if(X[M[i]] < key){
          return i;
      }
   }
   return -1;
}

int find_seq(int *X, int *M, int *P, int size){
    int i, j, L = 0;
    
    for(i = 0; i < size; i++){
         j = linear_search(M, 0, L, X, X[i]);
         std::cout << "binary search: " << j << std::endl;
         if(j == -1){
              j = 0;
         }
         
         P[i] = M[j];
         if(j == L || X[i] < X[M[j+1]]){
              M[j+1] = i;
              L = max(L, j+1);
         }
    }
    return L;
}


int main(){
   int X[] = {9, 2, 3, 4, 5, 6, 7, 8, 1, 0};
   int SIZE  = sizeof(X)/sizeof(int);
   
   int M[10] = {0};
   int P[10] = {0};
    
   int _ret = find_seq(X, M, P, SIZE);

   std::cout <<  _ret << std::endl;  
   while(1){continue;}
}
