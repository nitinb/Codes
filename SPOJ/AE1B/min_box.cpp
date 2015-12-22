/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : min_box.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Tuesday 28 June 2011 05:15:47 PM IST

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

#define DEBUG 0
#define MAX_SIZE 1000

int main(){

    int nb, nspt, nt, sum;
    scanf("%d %d %d",&nb, &nspt, &nt);
    std::vector<int>A (nb);

    for(int i = 0; i < nb; i++){
        scanf("%d",&A[i]);
    }
    make_heap(A.begin(), A.end());
    
    sum = 0;
    while(sum < nspt*nt){
        sum += A.front();
        pop_heap(A.begin(), A.end());
        A.pop_back();
    }
    printf("%d\n",nb-A.size());
}
