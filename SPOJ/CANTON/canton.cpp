/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : canton.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Tuesday 28 June 2011 03:10:01 PM IST

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

#define MAX_SIZE 200
#define DEBUG 0

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int num_test_cases, num, level, pos;

    scanf("%d",&num_test_cases);
    for(int x = 0; x < num_test_cases; x++){
        scanf("%d",&num);
        level = (int)ceil((sqrt(8*num+1)-1)/2);
        pos = num - (level*(level-1))/2;
        if(level%2 == 0)
           printf("TERM %d IS %d/%d\n",num, pos, level+1-pos);
        else
           printf("TERM %d IS %d/%d\n",num, level+1-pos, pos);        
    }
}
