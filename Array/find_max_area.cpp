
#include <iostream>
#include <cmath>

/*STL *algorithm* */
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 1
#define min(a,b) a<b?a:b;
#define max(a,b) a>b?a:b;

int main(){
    int arr[][2] = { {2, 9}, {1, 4}, {5, 2}, {7, 8}, {18, 0} };
    int num_rows = (sizeof(arr) / sizeof(int)) / 2;
    int previous_area = arr[0][0] * arr[0][1];
    
    for(int i=0; i<num_rows-1; i++){
        if(arr[i+1][0] > arr[i+1][0]){
            area_of_current_rect = arr[i][0] * arr[i][1];
            
        }
    }
    std::cout <<  num_rows << std::endl;  
    while(1){continue;}
}
