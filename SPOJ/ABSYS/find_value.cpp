/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : find_value.cpp

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
//    freopen("input.txt","r",stdin);

    ll num_test_cases, ARR[3];
    int state, i;
    char inp[MAX_SIZE];
    char *ptr1, *ptr2;
    scanf("%lld",&num_test_cases); getchar();
    for(int x = 0; x < num_test_cases; x++){
        getchar();
        scanf("%[^\n]",inp); getchar();
        i = 0;
        ptr1 = inp;

        while( i != 3){
            state = 0;   
            ptr2 = ptr1;   
            while( *ptr1 != ' ' && *ptr1 != '\0'){
                if(*ptr1 >= '0' && *ptr1 <= '9'){
                       if(state == 0) state = 1; 
                }
                if(*ptr1 >= 'a' && *ptr1 <= 'z'){
                       state = 2;
                }
                ptr1++;
            }
            if(state == 1)
               sscanf(ptr2,"%lld",&ARR[i]);
            else
               ARR[i] = -1;
            ptr1++; ptr1++; ptr1++; i++;
        }
//        printf("%lld**%lld**%lld\n",ARR[0], ARR[1], ARR[2]);
        ARR[0] = ARR[0] > 0 ? ARR[0] : ARR[2]-ARR[1];
        ARR[1] = ARR[1] > 0 ? ARR[1] : ARR[2]-ARR[0];
        ARR[2] = ARR[2] > 0 ? ARR[2] : ARR[0]+ARR[1];                
        printf("%lld + %lld = %lld\n", ARR[0], ARR[1], ARR[2]); 
    }
}
