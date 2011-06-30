/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : min_coins.cpp

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
    int num_test_cases;
    ull num, oup, temp;
    
    scanf("%d",&num_test_cases);
    for(int x = 0; x < num_test_cases; x++){
        scanf("%llu",&num);
        oup = 1;
        if( (num+2)%6 == 0){
            oup = (num+2)/6;
            oup = oup*(num-1);
            printf("%llu\n",oup);
            continue;
        }
        if( (num-1)%6 == 0){
            oup = (num-1)/6;
            oup = oup*(num+2);
            printf("%llu\n",oup);
            continue;            
        }
        
        if( (num+2)%3 == 0){
            oup = (num+2)/3;
            temp = (ull)(ceil((num-1)/2));
            oup = oup*temp;
            printf("%llu\n",oup);
            continue;
        }

        if( (num+2)%2 == 0){
            oup = (num+2)/2;
            temp = (ull)(ceil((num-1)/3));
            oup = oup*temp;
            printf("%llu\n",oup);
            continue;
        }
        
        if( (num-1)%3 == 0){
            oup = (num-1)/3;
            temp = (ull)(ceil((num+2)/2));
            oup = oup*temp;
            printf("%llu\n",oup);
            continue;
        }

        if( (num-1)%2 == 0){
            oup = (num-1)/2;
            int d = ceil(7/3);
            temp = (int)(ceil(7/3));
            std::cout << "temp=>" << temp << "oup=>" << oup << " d=" << d << std::endl;
            oup = oup*temp;
            printf("%llu\n",oup);
            continue;
        }        
    }
}
