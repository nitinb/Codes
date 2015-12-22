/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : phone_list.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Tuesday 28 June 2011 08:39:05 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <cstdio>

/*STL *algorithm* */
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 1
typedef long long ll;
typedef unsigned long long ull;

bool check(std::vector<std::string> dir){
  int size = dir.size();
  int len1, len2, pos;

  for(int i=0; i<size-1; i++){
     len1 = dir[i].length();
     len2 = dir[i+1].length();
    
     if(len1 < len2){
        pos = dir[i+1].find(dir[i]);
     }
     else{
        pos = dir[i].find(dir[i+1]);
     }
     if(pos == 0) return false;
  }
  return true;
}

int main(){
    int num_test_cases, num;
    char ph[10];
 
    scanf("%d",&num_test_cases);
    for(int z = 0; z < num_test_cases; z++){
        scanf("%d",&num);

        std::vector<std::string> dir(num);
        for(int x=0; x<num; x++){
           scanf("%s",ph);
           dir[x] = ph;
        }
        sort(dir.begin(), dir.end());
        bool ret = check(dir);
        if(ret) printf("YES\n");
        else printf("NO\n");
    }
}
