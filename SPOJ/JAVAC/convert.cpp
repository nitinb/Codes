/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : convert.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Wednesday 29 June 2011 07:39:44 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iomanip>

/*STL *algorithm* */
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 0
#define MAX_SIZE 10000

int main(){
    int num_test_cases, cols, rows, i, num, k;
    char inp[500], ch;
    std::string ret;

    scanf("%d",&num_test_cases); getchar();
    for(int x=0; x<num_test_cases; x++){
       inp[0] = '\0'; k = 0;
       scanf("%d %d",&rows, &cols);
       getchar();
       while(ch=getchar()){
          if(ch == EOF || ch == '\n') break;
          inp[k++]=ch;
       }
       inp[k] = '\0';
      // printf("%d**%d**%s**\n",rows, cols, inp);
       
       char M[rows*cols];
	memset(M, '0', sizeof(M));
       i=0;
       while(inp[i] != '\0'){
          ret = storage[inp[i]];
          for(int j=0; j<5; j++){
              M[5*i+j] = ret[j];
          }
          i++;
       }
     /*  for(int z=0; z<rows*cols; z++){
           if(M[z] != '0' && M[z] != '1'){
               M[z] = '0';
           }
       }*/
       printf("%d ",x+1);
       convert(M, rows, cols);
       printf("\n");
    }
}
