/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : roots.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Monday 27 June 2011 05:02:42 PM IST

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

#define MAX_SIZE 30
#define DEBUG 0

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int num_test_cases,a,b,c,t;
    char inp[MAX_SIZE];
    ll D;
    char *ptr;
    scanf("%d",&num_test_cases); getchar();
    for(int i = 0; i < num_test_cases; i++){
        scanf("%[^\n]",inp); getchar();
        a = b = c = 1;
        ptr = inp;
        if(*ptr != 'x'){ 
            sscanf(ptr,"%d",&a);
            while(*ptr!= 'x') ptr++;
        }
        ptr++; ptr++; ptr++;
        
        if(*ptr == '-'){ b = -1; }
        ptr++;
        if(*ptr != 'x'){ 
            sscanf(ptr,"%d",&t);
            b=b*t;
            while(*ptr!= 'x') ptr++;
        }
        ptr++;

        if(*ptr == '-'){ c = -1; }
        ptr++;        
        sscanf(ptr,"%d",&t);
        c=c*t;
        
        if(DEBUG) std::cout << a << "()" << b << "()" << c << std::endl;
        D = b*b - 4*a*c;
        if(D == 0){ printf("Equal roots.\n"); }
        else if(D < 0){ printf("Imaginary roots.\n"); }
        else{ printf("Distinct real roots.\n"); }
    }
}
