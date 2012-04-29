/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : music.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Monday 04 July 2011 11:28:09 AM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <sstream>
#include <cmath>
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
#define MAX_SIZE 1000000

int main(){
    int N, D;
    while(1){
       scanf("%d %d",&N, &D);
       if(N == 0 && D == 0) break;

       std::list<bool> storage(N);
       int i=0;
       while( N != 1){
          i = (i + D-1)%N;
          storage.erase(storage.begin()+i);
       }
    }
}
