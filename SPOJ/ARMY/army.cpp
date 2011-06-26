/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : army.cpp

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

int main(){
    int A, D, num_test_cases, temp, max=-1;
    bool flag = true; // def winner godzilla
    
    scanf("%d",&num_test_cases);
    for(int i = 0; i < num_test_cases; i++){
       max=-1; flag=true;
       scanf("%d %d",&A, &D);
       
       for(int x = 0; x < A; x++){ scanf("%d",&temp); if(temp > max) max = temp; }
       for(int x = 0; x < D; x++){ scanf("%d",&temp); if(temp > max) flag = false; }

       if(flag) printf("Godzilla\n");
       else printf("MechaGodzilla\n");
    }
//    while(1) { continue; }
}
