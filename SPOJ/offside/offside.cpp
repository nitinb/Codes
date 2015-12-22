/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : offside.cpp

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
#define MAX_SIZE 500

int max(int a, int b, int c){
   return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

int find_min(int *a, int n, int _t){
    int m1, m2; m1 = 100000, m2 = 1000000;
    for(int i = 0; i < n; i++){
        if(a[i] < m1){
            if(m1 < m2) m2 = m1;                
            m1 = a[i];
        }
        else if(a[i] < m2){
             m2 = a[i];
        }
    }
    return _t == 2 ? m2 : m1;
}

// **************************************************
int main(){
    int A, D;
    while(1){
       scanf("%d %d",&A, &D);
       if(A == 0 && D == 0) break;
     
       int Arr[A], Drr[D];
       for(int i = 0; i < A; i++){ scanf("%d",&Arr[i]); }
       for(int i = 0; i < D; i++){ scanf("%d",&Drr[i]); }
       int x2 = find_min(Drr, D, 2);
       int x1 = find_min(Arr, A, 1);
       if(DEBUG) std::cout << x2 << " " << x1 << std::endl;
       if(x1 < x2) printf("Y\n");
       else printf("N\n");
    }
//    while(1) { continue; }
}
