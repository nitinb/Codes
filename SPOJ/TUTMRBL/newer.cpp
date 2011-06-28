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

  #define DEBUG 1
  typedef long long ll;

  int main(){
  //    freopen("input.txt","r",stdin);
      ll count=0;
       int num, _ret;
      while(1){
          scanf("%d",&num);
          if(num == 0) break;
          else if(num == 2){
              printf("2 = 2");
              printf("\nWith 2 marbles, 1 different rectangles can be constructed.\n");
          }
          else{
               int max=0, i=2;
               int num2 = num;
              bool flag = true;

              printf("%d = ",num);
              int final = sqrt(num)+1;
              while(i<final){
                  if(num%i == 0){
                      max++;
                      while(num2%i == 0){
                          if(flag) { printf("%d",i); flag = false;}
                          else printf(" * %d",i);
                          num2 /= i;
                      }
                  } i++;
              }
              if(max == 0){
                  printf("%d",num);
              }
              else if(num2 != 1){
                  printf(" * %d",num2);
              }
              max += 1; //1*300

              printf("\nWith %d marbles, %d different rectangles can be constructed.\n", num,max);
          }
      }
  }
