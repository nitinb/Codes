/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : encoding.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Monday 16 May 2011 06:36:08 PM IST

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
#define MAX_SIZE 10000

std::string gen_binary(int num){
    std::string ret;
    char ch;
    while(num != 0){
        ch = num%2 + '0';
        ret = ret + ch;
        num /= 2;
    }
    return ret;
}

void convert(char *a, int ROWS, int COLS){
     int hr, vb, hl, vt;
     char arr[ROWS][COLS];

    int levl, i=0;
    for (levl=0; levl < COLS-levl; levl++){
        for(hr=levl; hr < COLS-levl; hr++)   // go right
            arr[levl][hr] = a[i++];
        if(i >= ROWS*COLS) break;
        
        for(vb=levl+1; vb < ROWS-levl; vb++) // go down
            arr[vb][hr-1] = a[i++];
        if(i >= ROWS*COLS) break;
        
        for(hl=hr-1; hl-1 >= levl; hl--)  // go left
            arr[vb-1][hl-1] = a[i++];
        if(i >= ROWS*COLS) break;
        
        for(vt=vb-1; vt-1 > levl; vt--)  // go up
            arr[vt-1][hl] = a[i++];
        if(i >= ROWS*COLS) break;            
    }
    
    for(int x=0; x<ROWS; x++){
        for(int y=0; y<COLS; y++){
                printf("%c",arr[x][y]);
        }
    }
}

int main(){
    int num_test_cases, cols, rows, i, num;
    char inp[500], tp[500];
    std::string ret;

    scanf("%d",&num_test_cases); getchar();
    for(int x=0; x<num_test_cases; x++){
       inp[0] = '\0';
       scanf("%[^\n]",tp); getchar();
       sscanf(tp, "%d %d %[^\n]",&rows, &cols, inp);
       
       char M[rows*cols];
       i=0;
       while(inp[i] != '\0'){
          num = inp[i] == ' ' ? 0 : inp[i] - 'A' + 1;
          if(num > 0){
             ret = gen_binary(num);
          }else ret = "";
          
          for(int j=0; j<5; j++){
              if(j<5-ret.length()){ M[5*i+j] = '0'; }
              else{ M[5*i+j] = ret[4-j];}
          }
          i++;
       }
       for(int z=0; z<rows*cols; z++){
           if(M[z] != '0' && M[z] != '1'){
               M[z] = '0';
           }
       }
       printf("%d ",x+1);
       convert(M, rows, cols);
       std::cout << std::endl;       
    }
}
