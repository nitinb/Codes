/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : newer.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Friday 24 June 2011 08:39:13 PM IST

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

int main(){
//    freopen("inp.txt","r",stdin);
  
    long long int num, _ret;
    while(1){
       scanf("%lld",&num);
       if(num == 0) break;
       else if(num == 2){
            printf("2 = 2");
            printf("\nWith 2 marbles, 1 different rectangles can be constructed.\n");
       }
       else{
            long long int max=0, i=2;
            long long int num2 = num;
            bool flag = true;
            
            printf("%lld = ",num);
            int final = int(ceil(sqrt(num)));
            while(1){
                if(i > final) break;
                if(num%i == 0){
                    max++;
                    while(num2%i == 0){
                         if(flag) { printf("%lld",i); flag = false;}
                         else printf(" * %lld",i);
                         num2 /= i;                 
                    }
                } i++;
            }
            if(max == 0){
                printf("%lld",num);           
            }
            else if(num2 != 1){
                printf(" * %lld",num2);
            }
            max += 1; //1*300
            
            printf("\nWith %lld marbles, %lld different rectangles can be constructed.\n", num,max);
       }
    }
}
