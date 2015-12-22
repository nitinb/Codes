/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : roots.cpp

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

#define MAX_SIZE 30
#define DEBUG 0

typedef long long ll;
typedef unsigned long long ull;

void Print(int a, int b, int c){
    ll D;
    
    D = b*b - 4*a*c;
    if(DEBUG) std::cout << a << "()" << b << "()" << c << "=>" << D << "  ";
    if(D == 0){ printf("Equal roots.\n"); }
    else if(D < 0){ printf("Imaginary roots.\n"); }
    else{ printf("Distinct real roots.\n"); }
}

int main(){
//    freopen("input.txt","r",stdin);

    int num_test_cases,a,b,c,t;
    char inp[MAX_SIZE];
    char *ptr;
    scanf("%d",&num_test_cases); getchar();
    for(int i = 0; i < num_test_cases; i++){
        scanf("%[^\n]",inp); getchar();
        a = b = c = 0;
        ptr = inp;

        if(*ptr == '-'){ a = -1; ptr++; }
        else { a = 1; }

        if(*ptr != 'x'){
            sscanf(ptr,"%d",&t);
            a=a*t;
            while(*ptr!= 'x') ptr++;
        }
        ptr++; ptr++; ptr++;
        
        if(*ptr == '-'){ b = -1; }
        else if(*ptr == '+'){ b = 1; }
        else{
            Print(a,0,0);
            continue; 
        }

        ptr++;
        if(*ptr != 'x'){ 
            sscanf(ptr,"%d",&t);
            b=b*t;
            while(*ptr >= '0' && *ptr <= '9') ptr++;
            if(*ptr != '*'){
               c = b; b = 0;
               Print(a,b,c);
               continue;
            }
            else{
              ptr++; 
            }
        }
        ptr++;

        if(*ptr == '-'){ c = -1; }
        else if(*ptr == '+'){ c = 1; }
        else{
            Print(a,b,c);
            continue; 
        }
        ptr++;
        sscanf(ptr,"%d",&t);
        c=c*t;
        Print(a,b,c);
    }
}
