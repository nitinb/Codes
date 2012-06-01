#include <stdlib.h>
#include <stdio.h>

#include <iostream>

using namespace std;

void doSomething(int p, int q, int r){
    int (*a3d)[q][r] = (int(*)[q][r])malloc(p*sizeof(int[q][r]));

    for(int i=0 ; i<p ; i++){
        for(int j=0 ; j<q ; j++){
            for(int k=0 ; k<r ; k++){
                printf("%d ", ( (&(a3d[i][j][k])) - (&(a3d[0][0][0])) ));
            }
            printf("\n");
        }
        printf("\n");
    }
}

void dootherthing(int p, int q, int r){
    int ***a3d;

    a3d = (int***)malloc(p * sizeof(int**));
    for(int i = 0; i < p; i++){
        a3d[i] = (int**)malloc(q * sizeof(int*));
        for(int j = 0; j < q; j++){
            a3d[i][j] = (int*)malloc(r * sizeof(int));
        }
    }

   for(int i=0 ; i<p ; i++){
       for(int j=0 ; j<q ; j++){
           for(int k=0 ; k<r ; k++){
               printf("%d ", ( (&(a3d[i][j][k])) - (&(a3d[0][0][0])) ));
           }
           printf("\n");
       }
       printf("\n");
   }
}

int main(){
    doSomething(2, 3, 4);
    dootherthing(2, 3, 4);

//    doSomething(3, 4, 2);
//    dootherthing(3, 4, 2);

    std::cout << "sizeof int***" << sizeof(int***) << std::endl;
    std::cout << "sizeof int**" << sizeof(int**) << std::endl;
    std::cout << "sizeof int*" << sizeof(int*) << std::endl;
    std::cout << "sizeof int" << sizeof(int) << std::endl;


    std::cout << "sizeof char***" << sizeof(char***) << std::endl;
    std::cout << "sizeof char**" << sizeof(char**) << std::endl;
    std::cout << "sizeof char*" << sizeof(char*) << std::endl;
    std::cout << "sizeof char" << sizeof(char) << std::endl;
}
