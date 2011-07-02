/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : encoding.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Wednesday 29 June 2011 07:39:44 PM IST

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

void gen_binary(std::map<char, std::string> &storage){
      storage[' ']="00000";
      storage['A']="00001";
      storage['B']="00010";
      storage['C']="00011";
      storage['D']="00100";
      storage['E']="00101";
      storage['F']="00110";
      storage['G']="00111";
      storage['H']="01000";
      storage['I']="01001";
      storage['J']="01010";
      storage['K']="01011";
      storage['L']="01100";
      storage['M']="01101";
      storage['N']="01110";
      storage['O']="01111";
      storage['P']="10000";
      storage['Q']="10001";
      storage['R']="10010";
      storage['S']="10011";
      storage['T']="10100";
      storage['U']="10101";
      storage['V']="10110";
      storage['W']="10111";
      storage['X']="11000";
      storage['Y']="11001";
      storage['Z']="11010";
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
    int num_test_cases, cols, rows, i, num, k;
    char inp[500], ch;
    std::string ret;
    std::map<char, std::string> storage;
    
    gen_binary(storage);

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
       i=0;
       while(inp[i] != '\0'){
          ret = storage[inp[i]];
          for(int j=0; j<5; j++){
              M[5*i+j] = ret[j];
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
       printf("\n");
    }
}
