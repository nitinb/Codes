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
#define min(a,b) a < b ? a : b;
#define max(a,b) a > b ? a : b;

void print_array(int *arr, int n){
    for(int i=0; i<n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void swap(int *arr, int i, int j){
    if(arr[i] == arr[j])
       return; 
     
    arr[j] = arr[i] + arr[j];
    arr[i] = arr[j] - arr[i];
    arr[j] = arr[j] - arr[i]; 
}

void selection_sort(int *arr, int n){
    int temp, index; 
     
    for(int i=0; i<n; i++){
        temp = arr[i];
        index = i;    
        for(int j=i; j<n; j++){
            if(arr[j] < temp){
                temp = arr[j];
                index = j;
            }
        }
        swap(arr, i, index);
    }     
}

void bubble_sort(int *arr, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr, j, j+1);
            }
        }
    }
}


int main(){
    int arr[] = {9, 2, 3, 4, 15, 6, 5, 8, 18, 0};
    int n = sizeof(arr)/sizeof(int);
   
    selection_sort(arr, n);
    print_array(arr, n);
    
    arr[0] = arr[n-1];
    bubble_sort(arr, n);
    print_array(arr, n);
        
    while(1){
        getchar();
    }
}
